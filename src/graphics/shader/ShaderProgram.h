//
// Created by osklot12 on 10/23/24.
//

#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H
#include <string>
#include <glad/glad.h>

#include "Shader.h"


class ShaderProgram {
public:
    ShaderProgram(const Shader &vertex_shader, const Shader &fragment_shader);
    ~ShaderProgram();

    // disable copy, allow move
    ShaderProgram(const ShaderProgram&) = delete;
    ShaderProgram &operator=(const ShaderProgram&) = delete;
    ShaderProgram(ShaderProgram&& other) noexcept;
    ShaderProgram &operator=(ShaderProgram&& other) noexcept;

    void use() const;
    GLuint get_id() const;

    // uniform setting utilities
    void set_bool(const std::string &name, bool value) const;
    void set_int(const std::string &name, int value) const;
    void set_float(const std::string &name, float value) const;

private:
    GLuint id;
    void link_program(const Shader& vertex_shader, const Shader& fragment_shader);
};



#endif //SHADERPROGRAM_H
