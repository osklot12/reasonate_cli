//
// Created by osklot12 on 1/2/25.
//

#ifndef REASONATE_CLI_INPUTMANAGER_H
#define REASONATE_CLI_INPUTMANAGER_H


#include <functional>
#include <GLFW/glfw3.h>
#include <unordered_set>

// handles user input with custom callback functions
class InputManager {
public:
    // giving convenient aliases
    using KeyCallBack = std::function<void(float)>;
    using ComboCallback = std::function<void(float)>;
    using MouseCallback = std::function<void(double, double)>;
    using ScrollCallback = std::function<void(double)>;

    // register single key callback
    void registerKeyCallback(int key, const KeyCallBack &callback);

    // register multi-key callback
    void registerComboCallback(const std::vector<int> &keys, const ComboCallback &callback);

    // register mouse movement callback
    void registerMouseCallback(const MouseCallback &callback);

    // register scroll callback
    void registerScrollCallback(const ScrollCallback &callback);

    // process user input
    void processInput(GLFWwindow* window, float deltaTime);

    // handles mouse movement
    void handleMouse(double xPos, double yPos);

    // handles scrolling
    void handleScroll(double yOffset);

private:
    // maps keys to callback functions
    std::unordered_map<int, KeyCallBack> keyCallbacks;

    // callback for mouse movement
    MouseCallback mouseCallback = nullptr;

    // callback for scrolling
    ScrollCallback scrollCallback = nullptr;

};


#endif //REASONATE_CLI_INPUTMANAGER_H
