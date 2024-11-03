//
// Created by osklot12 on 11/2/24.
//

#include "Texture.h"
#include "../util/stb_image.h"

#include <iostream>
#include <ostream>
#include <unordered_map>
#include <glad/glad.h>

Texture::Texture(const std::string &path, const GLenum target)
    : gl_texture(target), width(0), height(0), nr_channels(0), path(path) {
    bind();
    set_default_parameters();
    load_texture();
    unbind();
}

void Texture::bind_to_unit(const
    GLenum unit) const {
    gl_texture.bind_to_unit(unit);
}


unsigned char* Texture::load_image() {
    stbi_set_flip_vertically_on_load(true);
    return stbi_load(path.c_str(), &width, &height, &nr_channels, 0);
}

GLenum Texture::get_image_format(unsigned char *data) const {
    // image formats for nr. of channels
    static const std::unordered_map<int, GLenum> format_map = {
        {1, GL_RED},
        {3, GL_RGB},
        {4, GL_RGBA}
    };

    const auto internal_format_it = format_map.find(nr_channels);
    if (internal_format_it == format_map.end()) {
        throw std::runtime_error("Unsupported image format (" + std::to_string(nr_channels) + " channels) for texture: " + path);
    }

    return internal_format_it->second;
}

void Texture::load_texture()  {
    bind();

    if (unsigned char* data = load_image()) {
        try {
            const GLenum internal_format = get_image_format(data);
            glTexImage2D(gl_texture.get_target(), 0, GL_RGB, width, height, 0, internal_format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(gl_texture.get_target());
        } catch (...) {
            stbi_image_free(data);
            unbind();
            throw;
        }

        stbi_image_free(data);
    } else {
        unbind();
        throw std::runtime_error("Failed to load texture: " + path);
    }

    unbind();
}

void Texture::set_default_parameters() const {
    // wrapping parameters
    set_texture_parameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
    set_texture_parameter(GL_TEXTURE_WRAP_T, GL_REPEAT);

    // filtering parameters
    set_texture_parameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    set_texture_parameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Texture::set_texture_parameter(const GLenum pname, const GLint param) const {
    bind();
    glTexParameteri(gl_texture.get_target(), pname, param);
    unbind();
}