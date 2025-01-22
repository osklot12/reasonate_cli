//
// Created by osklot12 on 1/17/25.
//

#include "OpenGlEngine2D.h"

#include <glm/gtc/matrix_transform.hpp>

#include "FileUtil.h"
#include "Texture.h"
#include "../camera/Camera.h"
#include "../input/InputManagerOpenGl.h"

namespace Graphics {
    OpenGlEngine2D::OpenGlEngine2D() : vbo(), vao(), deltaTime(0.0f), lastFrame(0.0f) {
        initEngine();
    }

    OpenGlEngine2D::~OpenGlEngine2D() {
        if (vbo)
            glDeleteBuffers(1, &vbo);
        if (vao)
            glDeleteVertexArrays(1, &vao);
        glfwTerminate();
    }

    void OpenGlEngine2D::run() {
        // activate shader
        shaderProgram->use();

        const float screenWidth = 800.f;
        const float screenHeight = 600.f;
        projectionMatrix = glm::ortho(
            -screenWidth / 2.0f, screenWidth / 2.0f,
            -screenHeight / 2.0f, screenHeight / 2.0f,
            -1.0f, 1.0f);
        shaderProgram->set_mat4("uProjection", projectionMatrix);

        // render loop
        while (!glfwWindowShouldClose(window)) {
            const auto currentFrame = static_cast<float>(glfwGetTime());
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;

            // render
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // process input
            inputManager.processInput(window, deltaTime);

            shaderProgram->set_mat4("uView", camera.getViewMatrix());

            // draw point
            drawLine(std::array{-100.0f, 0.0f}, std::array{100.0f, 0.0f},
                std::array{1.0f, 1.0f, 1.0f, 1.0f});

            glfwSwapBuffers(window);
            if (!window) {
                throw std::runtime_error("GLFW window is null before calling glfwPollEvents.");
            }
            glfwPollEvents();
        }
    }

    void OpenGlEngine2D::addObject(Object2D &obj) {
        objects.emplace_back(obj);
    }


    void OpenGlEngine2D::initEngine() {
        // setup input manager
        inputManager = createInputManager();

        // set shader program
        shaderProgram = std::make_unique<ShaderProgram>(createShaderProgram());

        // generate and bind vao
        initVao();

        // generate and bind vbo
        initVbo();

        // set up vertex attribute pointers
        initVertexArrays();
    }

    Input::InputManagerOpenGl OpenGlEngine2D::createInputManager() {
        glfwSetWindowUserPointer(window, &inputManager);

        glfwSetCursorPosCallback(window, Input::InputManagerOpenGl::mouseCallbackWrapper);
        glfwSetScrollCallback(window, Input::InputManagerOpenGl::scrollCallbackWrapper);

        // registering callback functions
        glfwSetFramebufferSizeCallback(window, [](GLFWwindow *window, const int width, const int height) {
            glViewport(0, 0, width, height);
        });
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        // register camera-related input handlers
        inputManager.registerKeyCallback(Input::KeyBinding::W, [&](float deltaTime) {
            camera.moveVertical(100.0f * deltaTime);
        });
        inputManager.registerKeyCallback(Input::KeyBinding::S, [&](float deltaTime) {
            camera.moveVertical(-100.0f * deltaTime);
        });
        inputManager.registerKeyCallback(Input::KeyBinding::A, [&](float deltaTime) {
            camera.moveHorizontal(-100.0f * deltaTime);
        });
        inputManager.registerKeyCallback(Input::KeyBinding::D, [&](float deltaTime) {
            camera.moveHorizontal(100.0f * deltaTime);
        });

        inputManager.registerKeyCallback(Input::KeyBinding::Escape, [&](float deltaTime) {
            glfwSetWindowShouldClose(window, true);
        });

        inputManager.registerMouseCallback([&](double xOffset, double yOffset) {
        });

        inputManager.registerScrollCallback([&](double yOffset) {
        });

        return inputManager;
    }

    void addVertexAttribute(int index, int size, GLenum type, bool normalized, int stride, const void *ptr) {
        glVertexAttribPointer(index, size, type, normalized, stride, ptr);
    }

    ShaderProgram OpenGlEngine2D::createShaderProgram() {
        const std::string VERTEX_CODE_PATH = "../src/graphics/shader/shader_src/2d/shader.vs";
        const std::string FRAGMENT_CODE_PATH = "../src/graphics/shader/shader_src/2d/shader.fs";

        try {
            // create vertex and fragment shaders
            const std::string vertexCode = FileUtil::read_file(VERTEX_CODE_PATH);
            const std::string fragmentCode = FileUtil::read_file(FRAGMENT_CODE_PATH);

            // build and compile shader program
            const Shader vertexShader(vertexCode, SHADER_TYPE::VERTEX);
            const Shader fragmentShader(fragmentCode, SHADER_TYPE::FRAGMENT);
            ShaderProgram shaderProgram(vertexShader, fragmentShader);
            return shaderProgram;
        } catch (const std::exception &e) {
            throw std::runtime_error("Failed to create shader program");
        }
    }

    void OpenGlEngine2D::initVao() {
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
    }

    void OpenGlEngine2D::initVbo() {
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
    }

    void OpenGlEngine2D::addVertexAttribute(int index, int size, GLenum type, bool normalized, int stride,
                                            const void *ptr) {
        glVertexAttribPointer(index, size, type, normalized, stride, ptr);
        glEnableVertexAttribArray(index);
    }

    void OpenGlEngine2D::initVertexArrays() {
        addVertexAttribute(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
        addVertexAttribute(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (2 * sizeof(float)));
    }

    void OpenGlEngine2D::drawLine(const std::array<float, 2> &from, const std::array<float, 2> &to,
                                  const std::array<float, 4> &color) {
        std::vector<float> vertices{
            from[0], from[1], color[0], color[1], color[2], color[3],
            to[0], to[1], color[0], color[1], color[2], color[3],
        };

        Object2D line(vertices);
        drawObject(line, vbo, vao);
    }

    void OpenGlEngine2D::drawObject(const Object2D& obj, const unsigned int vbo_, const unsigned int vao_) {
        const auto pos = obj.getPosition();
        const auto rotation = obj.getRotation();
        const auto scale = obj.getScale();

        glm::vec2 position = glm::vec2(pos[0], pos[1]);
        float rotationAngle = rotation;
        glm::vec2 scaleVec = glm::vec2(scale[0], scale[1]);

        glm::mat4 model = glm::mat4(1.0f); // Identity matrix
        model = glm::translate(model, glm::vec3(position, 0.0f)); // Translation
        model = glm::rotate(model, rotationAngle, glm::vec3(0.0f, 0.0f, 1.0f)); // Rotation
        model = glm::scale(model, glm::vec3(scaleVec, 1.0f)); // Scaling
        shaderProgram->set_mat4("uModel", model);

        // binding vao
        glBindVertexArray(vao_);

        // binding vbo
        glBindBuffer(GL_ARRAY_BUFFER, vbo_);

        // sending vertex data
        glBufferData(GL_ARRAY_BUFFER, obj.getVertices().size() * sizeof(float), obj.getVertices().data(), GL_DYNAMIC_DRAW);

        // drawing
        glDrawArrays(GL_LINES, 0, 2);

        // unbinding vao
        glBindVertexArray(0);

        // unbinding vbo
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    Camera2D &OpenGlEngine2D::getCamera() {
        return camera;
    }

    Input::InputManager &OpenGlEngine2D::getInputManager() {
        return inputManager;
    }

}
