//
// Created by osklot12 on 1/22/25.
//

#ifndef ENGINE_H
#define ENGINE_H

#include "../../../input/InputManager.h"

namespace Graphics {
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


#endif //ENGINE_H
