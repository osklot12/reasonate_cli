#include <array>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "graphics/shader/ShaderProgram.h"
#include "util/FileUtil.h"
#define STB_IMAGE_IMPLEMENTATION
#include "graphics/texture/Texture.h"
#include "util/stb_image.h"

constexpr unsigned int SCR_WIDTH = 800;
constexpr unsigned int SCR_HEIGHT = 600;

constexpr char* WINDOW_TITLE = "Reasonate";

const std::string VERTEX_CODE_PATH = "../src/graphics/shader/shader_src/shader.vs";
const std::string FRAGMENT_CODE_PATH = "../src/graphics/shader/shader_src/shader.fs";

void process_input(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, WINDOW_TITLE, NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, [](GLFWwindow *window, const int width, const int height) {
        glViewport(0, 0, width, height);
    });

    const std::string vertex_code = FileUtil::read_file(VERTEX_CODE_PATH);
    const std::string fragment_code = FileUtil::read_file(FRAGMENT_CODE_PATH);

    const Shader vertex_shader(vertex_code, SHADER_TYPE::VERTEX);
    const Shader fragment_shader(fragment_code, SHADER_TYPE::FRAGMENT);

    const ShaderProgram shader_program(vertex_shader, fragment_shader);
    shader_program.use();

    constexpr std::array<float, 32> vertices = {
        // positions        // colors
         0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // top left
    };

    constexpr std::array<int, 6> indices = {
        0, 1, 3,
        1, 2, 3
    };

    unsigned int EBO;
    glGenBuffers(1, &EBO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    // initialization code
    // bind vertex array object
    glBindVertexArray(VAO);
    // copy our vertices array in a vertex buffer for opengl to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);
    // copy our index array in an element buffer for opengl to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices.data(), GL_STATIC_DRAW);
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    Texture tex_container("../src/graphics/texture/texture/container.jpg");
    Texture tex_face("../src/graphics/texture/texture/awesomeface.png");

    shader_program.set_int("texture1", 0);
    shader_program.set_int("texture2", 1);

    // model matrix to make plane lie on the ground
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    // view matrix
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    // projection matrix
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    // query the model transformation uniform and send the matrix data
    int modelLoc = glGetUniformLocation(shader_program.get_id(), "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    // query the view transformation uniform and send the matrix data
    int viewLoc = glGetUniformLocation(shader_program.get_id(), "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    // query the projection transformation uniform and send the matrix data
    int projLoc = glGetUniformLocation(shader_program.get_id(), "projection");
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    while (!glfwWindowShouldClose(window)) {
        // input
        process_input(window);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // bind texture
        tex_container.bind_to_unit(GL_TEXTURE0);
        tex_face.bind_to_unit(GL_TEXTURE1);

        // render container
        shader_program.use();
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        // glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();

    return 0;
}
