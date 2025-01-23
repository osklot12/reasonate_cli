//
// Created by osklot12 on 1/22/25.
//

#ifndef ENGINE3D_H
#define ENGINE3D_H

#include "../base/Engine.h"

namespace Graphics {
    // a graphics engine providing three dimensions
    class Engine3D : public Engine {
    protected:
        // protected default constructor
        Engine3D() = default;

    public:
        ~Engine3D() override = default;

        // delete copy constructor and copy assignment operator
        Engine3D(const Engine3D&) = delete;
        Engine3D& operator=(const Engine3D&) = delete;

        // default move constructor and move assignment operator
        Engine3D(Engine3D&&) = delete;
        Engine3D& operator=(Engine3D&&) = default;
    };
}

#endif //ENGINE3D_H
