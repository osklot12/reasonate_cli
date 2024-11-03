//
// Created by osklot12 on 11/2/24.
//

#ifndef GLTEXTURE_H
#define GLTEXTURE_H
#include <glad/glad.h>


class GLTexture {
public:
    explicit GLTexture(GLenum target);

    ~GLTexture();

    void bind() const;

    void unbind() const;

    void bind_to_unit(GLenum unit) const;

    GLuint get_id() const { return id; };
    GLenum get_target() const { return target; }

private:
    GLuint id{};
    GLenum target;
};


#endif //GLTEXTURE_H
