//
// Created by osklot12 on 1/2/25.
//

#include <stdexcept>
#include "InputManagerOpenGl.h"

namespace Input {
    void InputManagerOpenGl::registerKeyCallback(KeyBinding key, const KeyCallBack &callback) {
        const int keyCode = KeyMapper::mapKeyBindingToGLFWKey(key);
        keyCallbacks[keyCode] = callback;
    }

    void InputManagerOpenGl::unregisterKeyCallback(KeyBinding key) {
        const int keyCode = KeyMapper::mapKeyBindingToGLFWKey(key);
        keyCallbacks.erase(keyCode);
    }

    void InputManagerOpenGl::registerMouseCallback(const MouseCallback &callback) {
        mouseCallback = callback;
    }

    void InputManagerOpenGl::registerScrollCallback(const ScrollCallback &callback) {
        scrollCallback = callback;
    }

    void InputManagerOpenGl::processInput(GLFWwindow *window, float deltaTime) {
        for (const auto &[key, callback]: keyCallbacks) {
            if (glfwGetKey(window, key) == GLFW_PRESS && callback) {
                callback(deltaTime);
            }
        }
    }

    void InputManagerOpenGl::handleMouse(double xPos, double yPos) {
        if (mouseCallback) {
            mouseCallback(xPos * mouseSensitivity, yPos * mouseSensitivity);
        }
    }

    void InputManagerOpenGl::handleScroll(double yOffset) {
        if (scrollCallback) {
            scrollCallback(yOffset * scrollSensitivity);
        }
    }

    void InputManagerOpenGl::handleFirstMouse(float xPos, float yPos) {
        lastX = xPos;
        lastY = yPos;
        firstMouse = false;
    }

    void InputManagerOpenGl::mouseCallbackWrapper(GLFWwindow *window, double xPos, double yPos) {
        auto *inputManager = getWindowInputManager(window);
        if (!inputManager) return;

        // handles the case of first mouse movement
        if (inputManager->firstMouse)
            inputManager->handleFirstMouse(static_cast<float>(xPos),
                                           static_cast<float>(yPos));

        // calculating offsets
        float xOffset = static_cast<float>(xPos) - inputManager->lastX;
        float yOffset = inputManager->lastY - static_cast<float>(yPos);

        inputManager->lastX = static_cast<float>(xPos);
        inputManager->lastY = static_cast<float>(yPos);

        inputManager->handleMouse(xOffset, yOffset);
    }

    void InputManagerOpenGl::scrollCallbackWrapper(GLFWwindow *window, double xOffset, double yOffset) {
        auto *inputManager = getWindowInputManager(window);
        if (!inputManager) return;

        inputManager->handleScroll(yOffset);
    }

    void InputManagerOpenGl::setMouseSensitivity(float sensitivity) {
        if (sensitivity <= 0) {
            throw std::invalid_argument("Mouse sensitivity must be greater than 0");
        }
        mouseSensitivity = sensitivity;
    }

    void InputManagerOpenGl::setScrollSensitivity(float sensitivity) {
        if (sensitivity <= 0) {
            throw std::invalid_argument("Scroll sensitivity must be greater than 0");
        }
        scrollSensitivity = sensitivity;
    }

    InputManagerOpenGl *InputManagerOpenGl::getWindowInputManager(GLFWwindow *window) {
        return static_cast<InputManagerOpenGl *>(glfwGetWindowUserPointer(window));
    }
}
