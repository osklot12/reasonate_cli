//
// Created by osklot12 on 1/20/25.
//

export module Graphics.Engine;

import Input.InputManager;

export namespace Graphics {
    // a graphics engine interface
    class Engine {
    public:
        // destructor
        virtual ~Engine() = default;

        // runs the engine
        virtual void run() = 0;

        // getter for input manager
        virtual Input::InputManager& getInputManager() = 0;
    };
}
