//
// Created by osklot12 on 1/3/25.
//

#ifndef REASONATE_CLI_GRAPHICSENGINE_H
#define REASONATE_CLI_GRAPHICSENGINE_H


#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../camera/Camera.h"
#include "../../input/InputManager.h"
#include "../shader/ShaderProgram.h"
#include "../texture/Texture.h"
#include "GraphicsEngineConfig.h"

class GraphicsEngine {
    explicit GraphicsEngine(int width = GraphicsConfig::WINDOW_WIDTH, int height = GraphicsConfig::WINDOW_HEIGHT,
                   const std::string &title = GraphicsConfig::WINDOW_TITLE);
    ~GraphicsEngine();

private:
    GLFWwindow *window;

    // initializes engine
    void init(int width, int height, const std::string &title);

    // configures opengl version
    static void configureVersion();

    // creating window
    void createWindow(int width, int height, const std::string &title);
};


#endif //REASONATE_CLI_GRAPHICSENGINE_H
