//
// Created by osklot12 on 12/5/24.
//

#include <stdexcept>
#include "GLShader.h"

GLShader::GLShader(GLenum type_) : id(0), type(type_) {
    id = glCreateShader(type);
    if (0 == id) {
        throw std::runtime_error("Failed to create shader");
    }
}

GLShader::GLShader(GLShader &&other) noexcept : id(other.id), type(other.type) {
    other.id = 0;
}

GLShader::~GLShader() {
    if (0 != id) {
        glDeleteShader(id);
    }
}

GLuint GLShader::get_id() const {
    return id;
}

GLenum GLShader::get_type() const {
    return type;
}

GLShader &GLShader::operator=(GLShader &&other) noexcept {
    if (this != &other) {
        if (0 != id) {
            glDeleteShader(id);
        }

        id = other.id;
        type = other.type;
        other.id = 0;
    }

    return *this;
}