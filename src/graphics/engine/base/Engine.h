//
// Created by osklot12 on 1/22/25.
//

#ifndef ENGINE_H
#define ENGINE_H

#include "../../../input/InputManager.h"

namespace Graphics {
    // a graphics engine interface
    class Engine {
    protected:
        // protected default constructor
        Engine() = default;

    public:
        // destructor
        virtual ~Engine() = default;

        // delete copy constructor and copy assignment operator
        Engine(const Engine&) = delete;
        Engine& operator=(const Engine&) = delete;

        // default move constructor and move assignment operator
        Engine(Engine&&) = default;
        Engine& operator=(Engine&&) = default;

        // runs the engine
        virtual void run() = 0;

        // provides access to the input manager
        virtual std::shared_ptr<Input::InputManager> getInputManager() = 0;
    };
}


#endif //ENGINE_H
