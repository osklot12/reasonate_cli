//
// Created by osklot12 on 1/22/25.
//

module;

#include <functional>

export module Input.InputManager;

import Input.KeyBindings;

export namespace Input {
    // interface for input managers
    class InputManager {
    public:
        // aliases
        using KeyCallBack = std::function<void(float)>;
        using MouseCallback = std::function<void(double, double)>;
        using ScrollCallback = std::function<void(double)>;

        // destructor
        virtual ~InputManager() = default;

        // register key callback
        virtual void registerKeyCallback(KeyBinding key, const KeyCallBack& callback) = 0;

        // unregister key callback
        virtual void unregisterKeyCallback(KeyBinding key) = 0;
    };
}
