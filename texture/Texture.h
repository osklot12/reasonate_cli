//
// Created by osklot12 on 11/2/24.
//

#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>
#include <glad/glad.h>

#include "GLTexture.h"

class Texture {
public:
    void load_texture(const std::string &path);

    Texture(const std::string &path, GLenum target = GL_TEXTURE_2D);
    void bind() const { gl_texture.bind(); };
    void unbind() const { gl_texture.unbind(); };
    int get_width() const { return width; };
    int get_height() const { return height; };
    void set_texture_parameter(GLenum pname, GLint param) const;
    const std::string &get_path() const { return path; };
private:
    unsigned char* load_image();
    GLenum get_image_format(unsigned char *data) const;
    void load_texture();
    void set_default_parameters() const;

    GLTexture gl_texture;
    int width, height, nr_channels;
    std::string path;

    static constexpr GLint DEFAULT_WRAP_S = GL_REPEAT;
    static constexpr GLint DEFAULT_WRAP_T = GL_REPEAT;
    static constexpr GLint DEFAULT_MIN_FILTER = GL_LINEAR_MIPMAP_LINEAR;
    static constexpr GLint DEFAULT_MAG_FILTER = GL_LINEAR;
};



#endif //TEXTURE_H
