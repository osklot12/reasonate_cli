//
// Created by osklot12 on 10/23/24.
//

#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include "GLShader.h"

enum class SHADER_TYPE {
    VERTEX,
    FRAGMENT
};

class Shader {
public:
    Shader(const std::string &source_code, SHADER_TYPE type);
    GLuint get_id() const;
private:
    GLShader shader;
    void compile(const std::string &source_code);
};



#endif //SHADER_H
