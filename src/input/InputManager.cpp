//
// Created by osklot12 on 1/2/25.
//

#include "InputManager.h"

void InputManager::registerKeyCallback(int key, const InputManager::KeyCallBack &callback) {
    keyCallbacks[key] = callback;
}

void InputManager::unregisterKeyCallback(int key) {
    keyCallbacks.erase(key);
}

void InputManager::registerMouseCallback(const InputManager::MouseCallback &callback) {
    mouseCallback = callback;
}

void InputManager::registerScrollCallback(const InputManager::ScrollCallback &callback) {
    scrollCallback = callback;
}

void InputManager::processInput(GLFWwindow *window, float deltaTime) {
    for (const auto &[key, callback]: keyCallbacks) {
        if (glfwGetKey(window, key) == GLFW_PRESS && callback) {
            callback(deltaTime);
        }
    }
}

void InputManager::handleMouse(double xPos, double yPos) {
    if (mouseCallback) {
        mouseCallback(xPos, yPos);
    }
}

void InputManager::handleScroll(double yOffset) {
    if (scrollCallback) {
        scrollCallback(yOffset);
    }
}

void InputManager::handleFirstMouse(float xPos, float yPos) {
    lastX = xPos;
    lastY = yPos;
    firstMouse = false;
}

void InputManager::mouseCallbackWrapper(GLFWwindow *window, double xPos, double yPos) {
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

void InputManager::scrollCallbackWrapper(GLFWwindow *window, double xOffset, double yOffset) {
    auto *inputManager = getWindowInputManager(window);

    if (inputManager && inputManager->scrollCallback) {
        inputManager->scrollCallback(static_cast<float>(yOffset));
    }
}

InputManager *InputManager::getWindowInputManager(GLFWwindow *window) {
    return static_cast<InputManager *>(glfwGetWindowUserPointer(window));
}

