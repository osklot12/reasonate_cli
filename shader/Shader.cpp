//
// Created by osklot12 on 10/23/24.
//

#include "Shader.h"
#include <stdexcept>

constexpr size_t LOG_SIZE = 512;

Shader::Shader(const std::string &source_code, SHADER_TYPE type) : type(type) {
    id = glCreateShader(type == SHADER_TYPE::VERTEX ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
    if (id == 0) {
        throw std::runtime_error("Failed to create shader");
    }
    compile(source_code);
}

Shader::~Shader() {
    if (id != 0) {
        glDeleteShader(id);
    }
}

Shader::Shader(Shader&& other) noexcept : id(other.id), type(other.type) {
    other.id = 0;
}

Shader &Shader::operator=(Shader&& other) noexcept {
    if (this != &other) {
        glDeleteShader(id);
        id = other.id;
        type = other.type;
        other.id = 0;
    }
    return *this;
}

GLuint Shader::get_id() const {
    return id;
}

void Shader::compile(const std::string &source_code) const {
    const char *code = source_code.c_str();
    glShaderSource(id, 1, &code, NULL);
    glCompileShader(id);

    GLint success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success) {
        char info_log[LOG_SIZE];
        glGetShaderInfoLog(id, LOG_SIZE, nullptr, info_log);
        throw std::runtime_error("Shader compilation failed: " + std::string(info_log));
    }
}
