//
// Created by osklot12 on 1/22/25.
//

#ifndef EPSILON_H
#define EPSILON_H

#include <memory>
#include "../engine/2d/Engine2D.h"

namespace Graphics {
    // a graphics program for general purposes
    class Epsilon {
    public:
        // constructor for unique_ptr
        explicit Epsilon(std::unique_ptr<Engine2D> engine_);

        // runs the program
        void run();
    private:
        // graphics engine
        std::unique_ptr<Engine2D> engine;

        // initializes the program
        void init();
    };
}

#endif //EPSILON_H
