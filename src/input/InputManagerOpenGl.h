//
// Created by osklot12 on 1/2/25.
//

#ifndef REASONATE_CLI_INPUTMANAGER_H
#define REASONATE_CLI_INPUTMANAGER_H

#include <functional>
#include <GLFW/glfw3.h>

#include "InputManager.h"

namespace Input {
    // handles user input with custom callback functions
    class InputManagerOpenGl : public InputManager {
    public:
        // giving convenient aliases
        using KeyCallBack = std::function<void(float)>;
        using ComboCallback = std::function<void(float)>;
        using MouseCallback = std::function<void(double, double)>;
        using ScrollCallback = std::function<void(double)>;

        // register single key callback
        void registerKeyCallback(KeyBinding key, const KeyCallBack &callback) override;

        // unregisters a single key callback
        void unregisterKeyCallback(KeyBinding key) override;

        // register mouse movement callback
        void registerMouseCallback(const MouseCallback &callback);

        // register scroll callback
        void registerScrollCallback(const ScrollCallback &callback);

        // process user input
        void processInput(GLFWwindow *window, float deltaTime);

        // handles mouse movement
        void handleMouse(double xPos, double yPos);

        // handles scrolling
        void handleScroll(double yOffset);

        // handles first mouse movement
        void handleFirstMouse(float xPos, float yPos);

        // callback wrapper
        static void mouseCallbackWrapper(GLFWwindow *window, double xPos, double yPos);

        static void scrollCallbackWrapper(GLFWwindow *window, double xOffset, double yOffset);

        // set sensitivities
        void setMouseSensitivity(float sensitivity);

        void setScrollSensitivity(float sensitivity);

    private:
        // maps keys to callback functions
        std::unordered_map<int, KeyCallBack> keyCallbacks;

        // callback for mouse movement
        MouseCallback mouseCallback = nullptr;

        // callback for scrolling
        ScrollCallback scrollCallback = nullptr;

        // keeps track of whether mouse has been moved
        bool firstMouse = true;

        // stores the last mouse x and y positions
        float lastX = 400.0f;
        float lastY = 300.0f;

        // sensitivities
        float mouseSensitivity = 0.1f;
        float scrollSensitivity = 1.0f;

        // retrieves the input manager associated with a glfw window
        static InputManagerOpenGl *getWindowInputManager(GLFWwindow *window);
    };
}
#endif //REASONATE_CLI_INPUTMANAGER_H
