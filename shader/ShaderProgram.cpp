//
// Created by osklot12 on 10/23/24.
//

#include "ShaderProgram.h"

#include <stdexcept>

constexpr size_t LOG_SIZE = 512;

ShaderProgram::ShaderProgram(const Shader &vertex_shader, const Shader &fragment_shader) {
    id = glCreateProgram();
    glAttachShader(id, vertex_shader.get_id());
    glAttachShader(id, fragment_shader.get_id());
    link_program(vertex_shader, fragment_shader);
}

ShaderProgram::~ShaderProgram() {
    if (id != 0) {
        glDeleteProgram(id);
    }
}

ShaderProgram::ShaderProgram(ShaderProgram &&other) noexcept : id(other.id) {
    other.id = 0;
}

ShaderProgram &ShaderProgram::operator=(ShaderProgram &&other) noexcept {
    if (this != &other) {
        glDeleteProgram(id);
        id = other.id;
        other.id = 0;
    }
    return *this;
}

void ShaderProgram::use() const {
    glUseProgram(id);
}

GLuint ShaderProgram::get_id() const {
    return id;
}

void ShaderProgram::link_program(const Shader &vertex_shader, const Shader &fragment_shader) {
    glLinkProgram(id);

    GLint success;
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {
        char info_log[LOG_SIZE];
        glGetProgramInfoLog(id, LOG_SIZE, nullptr, info_log);
        throw std::runtime_error("Shader program linking failed: " + std::string(info_log));
    }
}

void ShaderProgram::set_bool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(id, name.c_str()), static_cast<int>(value));
}

void ShaderProgram::set_int(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

void ShaderProgram::set_float(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}