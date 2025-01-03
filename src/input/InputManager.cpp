//
// Created by osklot12 on 1/2/25.
//

#include "InputManager.h"

void InputManager::registerKeyCallback(int key, const InputManager::KeyCallBack &callback) {
    keyCallbacks[key] = callback;
}

void InputManager::registerComboCallback(const std::vector<int> &keys, const InputManager::ComboCallback &callback) {

}

void InputManager::registerMouseCallback(const InputManager::MouseCallback &callback) {
    mouseCallback = callback;
}

void InputManager::registerScrollCallback(const InputManager::ScrollCallback &callback) {
    scrollCallback = callback;
}

void InputManager::processInput(GLFWwindow *window, float deltaTime) {
    for (const auto &[key, callback] : keyCallbacks) {
        if (glfwGetKey(window, key) == GLFW_PRESS) {
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