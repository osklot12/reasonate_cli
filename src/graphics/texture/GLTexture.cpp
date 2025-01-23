//
// Created by osklot12 on 11/2/24.
//

#include "GLTexture.h"

GLTexture::GLTexture(const GLenum target) : target(target) {
    glGenTextures(1, &id);
}

GLTexture::~GLTexture() {
    glDeleteTextures(1, &id);
}

void GLTexture::bind() const {
    glBindTexture(target, id);
}

void GLTexture::unbind() const {
    glBindTexture(target, 0);
}

void GLTexture::bind_to_unit(const GLenum unit) const {
    glActiveTexture(unit);
    bind();
}
