//
// Created by osklot12 on 1/22/25.
//

#ifndef EPSILON_H
#define EPSILON_H

#include <memory>

namespace Graphics {
    class Engine2D;

    // a graphics program for general purposes
    class Epsilon {
    public:
        // constructor
        explicit Epsilon(std::unique_ptr<Engine2D> engine);
    private:
        // graphics engine
        std::unique_ptr<Engine2D> engine;

        // x and y offset
        double xOffset, yOffset;

        // zoom
        double zoom;
    };
}

#endif //EPSILON_H
