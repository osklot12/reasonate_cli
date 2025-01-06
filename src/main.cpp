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
#include "graphics/camera/Camera.h"
#include "input/InputManager.h"

constexpr unsigned int SCR_WIDTH = 800;
constexpr unsigned int SCR_HEIGHT = 600;

constexpr char *WINDOW_TITLE = "Reasonate";

const std::string VERTEX_CODE_PATH = "../src/graphics/shader/shader_src/shader.vs";
const std::string FRAGMENT_CODE_PATH = "../src/graphics/shader/shader_src/shader.fs";

// mouse sensitivity
constexpr float MOUSE_SENSITIVITY = 0.1f;

// defining delta time
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// creating camera
Camera camera;

int main() {
    // initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, WINDOW_TITLE, NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // initialize glad
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, 800, 600);

    // create and configure input manager
    InputManager inputManager;
    glfwSetWindowUserPointer(window, &inputManager);

    glfwSetCursorPosCallback(window, InputManager::mouseCallbackWrapper);
    glfwSetScrollCallback(window, InputManager::scrollCallbackWrapper);

    // registering callback functions
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow *window, const int width, const int height) {
        glViewport(0, 0, width, height);
    });
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // register camera-related input handlers
    inputManager.registerKeyCallback(GLFW_KEY_W, [&](float deltaTime) {
        camera.moveForward(2.5f * deltaTime);
    });
    inputManager.registerKeyCallback(GLFW_KEY_S, [&](float deltaTime) {
        camera.moveBackward(2.5f * deltaTime);
    });
    inputManager.registerKeyCallback(GLFW_KEY_A, [&](float deltaTime) {
        camera.moveLeft(2.5f * deltaTime);
    });
    inputManager.registerKeyCallback(GLFW_KEY_D, [&](float deltaTime) {
        camera.moveRight(2.5f * deltaTime);
    });

    inputManager.registerKeyCallback(GLFW_KEY_ESCAPE, [&](float deltaTime){
        glfwSetWindowShouldClose(window, true);
    });

    inputManager.registerMouseCallback([&](double xOffset, double yOffset) {
        camera.adjustYaw(static_cast<float>(xOffset) * MOUSE_SENSITIVITY);
        camera.adjustPitch(static_cast<float>(yOffset * MOUSE_SENSITIVITY));
    });

    inputManager.registerScrollCallback([&](double yOffset) {
        camera.adjustZoom(static_cast<float>(-yOffset));
    });

    // create vertex and fragment shaders
    const std::string vertex_code = FileUtil::read_file(VERTEX_CODE_PATH);
    const std::string fragment_code = FileUtil::read_file(FRAGMENT_CODE_PATH);

    // build and compile shader program
    const Shader vertex_shader(vertex_code, SHADER_TYPE::VERTEX);
    const Shader fragment_shader(fragment_code, SHADER_TYPE::FRAGMENT);
    const ShaderProgram shader_program(vertex_shader, fragment_shader);
    shader_program.use();

    // set up vertex data
    constexpr std::array<float, 180> vertices = {
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
            0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
            -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

            -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f
    };

    // world space positions of our cubes
    glm::vec3 cubePositions[] = {
            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(2.0f, 5.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3(2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f, 3.0f, -7.5f),
            glm::vec3(1.3f, -2.0f, -2.5f),
            glm::vec3(1.5f, 2.0f, -2.5f),
            glm::vec3(1.5f, 0.2f, -1.5f),
            glm::vec3(-1.3f, 1.0f, -1.5f)
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // load and create textures
    Texture tex_container("../src/graphics/texture/texture/container.jpg");
    Texture tex_face("../src/graphics/texture/texture/awesomeface.png");

    // map sampler to the corresponding texture
    shader_program.set_int("texture1", 0);
    shader_program.set_int("texture2", 1);

    // render loop
    while (!glfwWindowShouldClose(window)) {
        auto currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // process input
        inputManager.processInput(window, deltaTime);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // bind texture
        tex_container.bind_to_unit(GL_TEXTURE0);
        tex_face.bind_to_unit(GL_TEXTURE1);

        // activate shader
        shader_program.use();

        // creating and setting projection matrix
        glm::mat4 projection = glm::perspective(glm::radians(camera.getZoom()), (float) SCR_WIDTH / (float) SCR_HEIGHT,
                                                0.1f, 100.0f);
        shader_program.set_projection_matrix(projection);

        // setting view matrix
        shader_program.set_view_matrix(camera.getViewMatrix());

        // render boxes
        glBindVertexArray(VAO);
        for (unsigned int i = 0; i < 10; ++i) {
            // calculate the model matrix for each object and pass it to shader before drawing
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            shader_program.set_model_matrix(model);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // de-allocate all resources once they have outlived their purpose
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}
