//
// Created by osklot12 on 1/22/25.
//

#ifndef OPENGLENGINE_H
#define OPENGLENGINE_H

#include <GLFW/glfw3.h>
#include <string>
#include <thread>

#include "Engine.h"
#include "../FrameTime.h"
#include "../Screen.h"
#include "../../../input/InputManagerOpenGl.h"

namespace Graphics {
    // custom deleter for glfw window resource
    struct GLFWWindowDeleter {
        void operator()(GLFWwindow* window) const {
            if (window) {
                glfwDestroyWindow(window);
            }
        }
    };

    // an opengl graphics engine base class
    class OpenGlEngine {
    public:
        // constructor
        OpenGlEngine();

        // destructor
        virtual ~OpenGlEngine() = default;

    private:
        // initializes the graphics engine
        void initEngine();

        // initializes opengl
        static void initOpenGl();

        // creates a new window
        static std::unique_ptr<GLFWwindow, GLFWWindowDeleter> createWindow(int width = SCR_WIDTH, int height = SCR_HEIGHT,
                                        const std::string &windowTitle = WINDOW_TITLE, GLFWmonitor *monitor = nullptr);

        // initializes glad
        static void initGlad();

        // configures opengl state
        static void configureOpenGlState();
    protected:
        // the screen of graphical representation
        Screen screen;

        // data used for frame timing calculations
        FrameTime frameTime;

        // window associated with the engine
        std::unique_ptr<GLFWwindow, GLFWWindowDeleter> window;

        // render thread
        std::thread renderThread;

        // flag to control loop
        std::atomic<bool> running;

        // constants: version
        static constexpr int OPENGL_VERSION_MAJOR = 3;
        static constexpr int OPENGL_VERSION_MINOR = 3;
        static constexpr int OPEN_GL_PROFILE = GLFW_OPENGL_CORE_PROFILE;

        // constants: window
        static constexpr int SCR_WIDTH = 800;
        static constexpr int SCR_HEIGHT = 600;
        static constexpr auto WINDOW_TITLE = "OpenGL Engine";
    };
}

#endif //OPENGLENGINE_H
