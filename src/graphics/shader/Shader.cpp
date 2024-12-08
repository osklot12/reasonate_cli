//
// Created by osklot12 on 10/23/24.
//

#include "Shader.h"
#include <stdexcept>

constexpr size_t LOG_SIZE = 512;

Shader::Shader(const std::string &source_code, SHADER_TYPE type)
        : shader(type == SHADER_TYPE::VERTEX ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER) {
    compile(source_code);
}

GLuint Shader::get_id() const {
    return shader.get_id();
}

void Shader::compile(const std::string &source_code) {
    const char *code = source_code.c_str();
    glShaderSource(shader.get_id(), 1, &code, NULL);
    glCompileShader(shader.get_id());

    GLint success;
    glGetShaderiv(shader.get_id(), GL_COMPILE_STATUS, &success);
    if (!success) {
        char info_log[LOG_SIZE];
        glGetShaderInfoLog(shader.get_id(), LOG_SIZE, nullptr, info_log);
        throw std::runtime_error("Shader compilation failed: " + std::string(info_log));
    }
}
