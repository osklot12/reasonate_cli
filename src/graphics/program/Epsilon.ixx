//
// Created by osklot12 on 1/19/25.
//

module;

#include <memory>

export module Graphics.Epsilon;

import Graphics.Engine2D;

export namespace Graphics {
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
