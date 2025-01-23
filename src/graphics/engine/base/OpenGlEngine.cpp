//
// Created by osklot12 on 1/20/25.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <string>
#include <thread>

#include "OpenGlEngine.h"
#include "../OpenGlStatus.h"

namespace Graphics {
    OpenGlEngine::OpenGlEngine() : window(nullptr) {
        initEngine();
    }

    void OpenGlEngine::initEngine() {
        if (OpenGlStatus &status = OpenGlStatus::instance(); !status.getConfigured()) {
            initOpenGl();
            status.setConfigured(true);
        }

        window = createWindow();
        glfwMakeContextCurrent(window.get());

        initGlad();

        configureOpenGlState();
    }

    void OpenGlEngine::initOpenGl() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION_MAJOR);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION_MINOR);
        glfwWindowHint(GLFW_OPENGL_PROFILE, OPEN_GL_PROFILE);
    }

    std::unique_ptr<GLFWwindow, GLFWWindowDeleter> OpenGlEngine::createWindow(int width, int height,
                                     const std::string &windowTitle, GLFWmonitor *monitor) {
        const auto rawWindow = glfwCreateWindow(width, height, windowTitle.c_str(), NULL, NULL);
        if (!rawWindow) {
            throw std::runtime_error("Failed to create GLFW window");
        }
        return std::unique_ptr<GLFWwindow, GLFWWindowDeleter>(rawWindow);
    }

    void OpenGlEngine::initGlad() {
        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
            throw std::runtime_error("Failed to initialize GLAD");
        }
    }

    void OpenGlEngine::configureOpenGlState() {
        glEnable(GL_DEPTH_TEST);
        glViewport(0, 0, 800, 600);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
}
