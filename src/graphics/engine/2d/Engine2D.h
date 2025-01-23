//
// Created by osklot12 on 1/22/25.
//

#ifndef ENGINE2D_H
#define ENGINE2D_H

#include "../base/Engine.h"

namespace Graphics {
    class Camera2D;

    // a graphics engine providing two dimensions
    class Engine2D : public Engine {
    public:
        // destructor
        ~Engine2D() override = default;

        // getter for camera
        virtual Camera2D& getCamera() = 0;
    };
}

#endif //ENGINE2D_H
