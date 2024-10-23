//
// Created by osklot12 on 10/23/24.
//

#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <glad/glad.h>

enum class SHADER_TYPE {
    VERTEX,
    FRAGMENT
};

class Shader {
public:
    Shader(const std::string &source_code, SHADER_TYPE type);
    ~Shader();

    // disable copy, allow move
    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;
    Shader(Shader&& other) noexcept;
    Shader& operator=(Shader&& other) noexcept;

    GLuint get_id() const;
private:
    GLuint id;
    SHADER_TYPE type;
    void compile(const std::string &source_code);
};



#endif //SHADER_H
