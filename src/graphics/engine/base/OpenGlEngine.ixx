//
// Created by osklot12 on 1/19/25.
//

module;

#include <glad/glad.h>
#include <GLFW/glfw3.h>

export module Graphics.OpenGlEngine;

import <string>;
import <thread>;
import <memory>;
import Graphics.Engine;
import Graphics.OpenGlStatus;

export namespace Graphics {
    // constants: version
    constexpr int OPENGL_VERSION_MAJOR = 3;
    constexpr int OPENGL_VERSION_MINOR = 3;
    constexpr int OPEN_GL_PROFILE = GLFW_OPENGL_CORE_PROFILE;

    // constants: window
    constexpr int WINDOW_WIDTH = 800;
    constexpr int WINDOW_HEIGHT = 600;
    const std::string WINDOW_TITLE = "OpenGL Engine";

    // an opengl graphics engine base class
    class OpenGlEngine : public Engine {
    public:
        // constructor
        OpenGlEngine();

        // destructor
        ~OpenGlEngine() override;

    private:
        // initializes the graphics engine
        void initEngine();

        // initializes opengl
        static void initOpenGl();

        // creates a new window
        static GLFWwindow *createWindow(int width = WINDOW_WIDTH, int height = WINDOW_HEIGHT,
                                        const std::string &windowTitle = WINDOW_TITLE, GLFWmonitor *monitor = nullptr);

        // initializes glad
        static void initGlad();

        // configures opengl state
        static void configureOpenGlState();
    protected:
        // the window associated with the engine
        GLFWwindow *window;

        // render thread
        std::thread renderThread;

        // flag to control loop
        std::atomic<bool> running;
    };
}
