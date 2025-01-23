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
    protected:
        // protected default constructor
        Engine2D() = default;

    public:
        // destructor
        ~Engine2D() override = default;

        // delete copy constructor and copy assignment operator
        Engine2D(const Engine2D&) = delete;
        Engine2D& operator=(const Engine2D&) = delete;

        // default move constructor and move assignment operator
        Engine2D(Engine2D&&) = default;
        Engine2D& operator=(Engine2D&&) = default;

        // adds a graphical object
        virtual void addObject(Object2D& obj) = 0;

        // getter for camera
        virtual Camera2D& getCamera() = 0;
    };
}

#endif //ENGINE2D_H
