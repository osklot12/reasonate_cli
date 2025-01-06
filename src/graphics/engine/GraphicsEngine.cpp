//
// Created by osklot12 on 1/3/25.
//

#include <iostream>
#include "GraphicsEngine.h"

void GraphicsEngine::init(int width, int height, const std::string &title) {
    glfwInit();
    configureVersion();
    createWindow(width, height, title);
}

void GraphicsEngine::configureVersion() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GraphicsConfig::CONTEXT_VERSION_MAJOR);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GraphicsConfig::CONTEXT_VERSION_MINOR);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void GraphicsEngine::createWindow(int width, int height, const std::string &title) {
    window = glfwCreateWindow(width, height, title.c_str(),
                                          nullptr, nullptr);

    if (window == nullptr) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window.");
    }

    glfwMakeContextCurrent(window);
}