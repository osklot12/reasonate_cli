//
// Created by osklot12 on 1/17/25.
//

#include "OpenGlEngine3D.h"

#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include "FileUtil.h"
#include "Texture.h"
#include "../camera/Camera.h"
#include "../input/InputManagerOpenGl.h"

namespace Graphics {
    OpenGlEngine3D::OpenGlEngine3D() : vbo(), vao(), deltaTime(0.0f), lastFrame(0.0f) {
        initEngine();
    }

    OpenGlEngine3D::~OpenGlEngine3D() {
        if (vbo)
            glDeleteBuffers(1, &vbo);
        if (vao)
            glDeleteVertexArrays(1, &vao);
    }

    void OpenGlEngine3D::run() {
        // load and create textures
        Texture tex_container("../src/graphics/texture/texture/container.jpg");
        Texture tex_face("../src/graphics/texture/texture/awesomeface.png");

        // map sampler to the corresponding texture
        shaderProgram->set_int("texture1", 0);
        shaderProgram->set_int("texture2", 1);

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
            shaderProgram->use();

            // creating and setting projection matrix
            glm::mat4 projection = glm::perspective(glm::radians(camera.getZoom()),
                                                    (float) SCR_WIDTH / (float) SCR_HEIGHT,
                                                    0.1f, 100.0f);
            shaderProgram->set_projection_matrix(projection);

            // setting view matrix
            shaderProgram->set_view_matrix(camera.getViewMatrix());

            // render boxes
            glBindVertexArray(vao);
            int rotationCounter = 0;
            for (Object o : objects) {
                const float* objectVertices = o.getVertices().data();
                glBufferData(GL_ARRAY_BUFFER, o.getVertices().size() * sizeof(float), objectVertices, GL_STATIC_DRAW);
                // calculate the model matrix for each object and pass it to shader before drawing
                glm::mat4 model = glm::mat4(1.0f);
                // std::array<float, 3> pos = o.getPosition();
                // model = glm::translate(model, glm::vec3(pos[0], pos[1], pos[2]));
                float angle = 20.0f * rotationCounter;
                model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
                shaderProgram->set_model_matrix(model);

                glDrawArrays(GL_TRIANGLES, 0, o.getVertices().size() / 5);
                ++rotationCounter;
            }

            glfwSwapBuffers(window);
            if (!window) {
                throw std::runtime_error("GLFW window is null before calling glfwPollEvents.");
            }
            glfwPollEvents();
        }
        // de-allocate all resources once they have outlived their purpose
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);

        glfwTerminate();
        std::cout << "this is ran" << std::endl;
    }

    void OpenGlEngine3D::addObject(Object& obj) {
        objects.emplace_back(obj);
    }


    void OpenGlEngine3D::initEngine() {
        inputManager = createInputManager();

        shaderProgram = std::make_unique<ShaderProgram>(createShaderProgram());
        shaderProgram->use();

        initVbo();
        initVao();
        initVertexArrays();
    }

    Input::InputManagerOpenGl OpenGlEngine3D::createInputManager() {
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
            camera.moveForward(2.5f * deltaTime);
        });
        inputManager.registerKeyCallback(Input::KeyBinding::S, [&](float deltaTime) {
            camera.moveBackward(2.5f * deltaTime);
        });
        inputManager.registerKeyCallback(Input::KeyBinding::A, [&](float deltaTime) {
            camera.moveLeft(2.5f * deltaTime);
        });
        inputManager.registerKeyCallback(Input::KeyBinding::D, [&](float deltaTime) {
            camera.moveRight(2.5f * deltaTime);
        });

        inputManager.registerKeyCallback(Input::KeyBinding::Escape, [&](float deltaTime) {
            std::cout << "closing" << std::endl;
            glfwSetWindowShouldClose(window, true);
        });

        inputManager.registerMouseCallback([&](double xOffset, double yOffset) {
            camera.adjustYaw(static_cast<float>(xOffset));
            camera.adjustPitch(static_cast<float>(yOffset));
        });

        inputManager.registerScrollCallback([&](double yOffset) {
            camera.adjustZoom(static_cast<float>(-yOffset));
        });

        return inputManager;
    }

    void addVertexAttribute(int index, int size, GLenum type, bool normalized, int stride, const void *ptr) {
        glVertexAttribPointer(index, size, type, normalized, stride, ptr);
    }

    ShaderProgram OpenGlEngine3D::createShaderProgram() {
        const std::string VERTEX_CODE_PATH = "../src/graphics/shader/shader_src/3d/shader.vs";
        const std::string FRAGMENT_CODE_PATH = "../src/graphics/shader/shader_src/3d/shader.fs";

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

    void OpenGlEngine3D::initVao() {
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
    }

    void OpenGlEngine3D::initVbo() {
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
    }

    void OpenGlEngine3D::addVertexAttribute(int index, int size, GLenum type, bool normalized, int stride,
                                          const void *ptr) {
        glVertexAttribPointer(index, size, type, normalized, stride, ptr);
        glEnableVertexAttribArray(index);
    }

    void OpenGlEngine3D::initVertexArrays() {
        addVertexAttribute(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) 0);
        addVertexAttribute(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
    }
}
