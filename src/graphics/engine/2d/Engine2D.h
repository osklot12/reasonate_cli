//
// Created by osklot12 on 1/22/25.
//

#ifndef ENGINE2D_H
#define ENGINE2D_H

#include "../../object/2d/Object2D.h"
#include "../base/Engine.h"

namespace Graphics {
    class Camera2D;

    // a graphics engine providing two dimensions
    class Engine2D : public Engine {
    public:
        // destructor
        ~Engine2D() override = default;

        // adds a graphical object
        virtual void addObject(Object2D& obj) = 0;

        // getter for camera
        virtual Camera2D& getCamera() = 0;
    };
}

#endif //ENGINE2D_H
