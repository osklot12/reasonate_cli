//
// Created by osklot12 on 12/5/24.
//

#ifndef REASONATE_CLI_GLSHADER_H
#define REASONATE_CLI_GLSHADER_H


#include "glad/glad.h"

class GLShader {
public:
    explicit GLShader(GLenum type_);
    GLShader(const GLShader&) = delete;
    GLShader(GLShader &&other) noexcept;
    ~GLShader();
    GLuint get_id() const;
    GLenum get_type() const;
    GLShader &operator=(const GLShader&) = delete;
    GLShader &operator=(GLShader&& other) noexcept;
private:
    GLuint id{};
    GLenum type;
};


#endif //REASONATE_CLI_GLSHADER_H
