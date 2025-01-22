//
// Created by osklot12 on 1/21/25.
//

module;

#include <array>

export module Graphics.Camera2D;

import Math.Matrix;

export namespace Graphics {
    // an interface for 2d cameras
    class Camera2D {
    public:
        // destructor
        virtual ~Camera2D() = default;

        // move functions
        virtual void moveVertical(float amount) = 0;

        virtual void moveHorizontal(float amount) = 0;

        // rotation function
        virtual void rotate(float angle) = 0;

        // zoom function
        virtual void adjustZoom(float amount) = 0;

        // getters
        virtual const std::array<float, 2> getPos() const = 0;

        virtual float getRotation() const = 0;

        virtual float getZoom() const = 0;

        // setters
        virtual void setPos(float x, float y) = 0;

        virtual void setRotation(float angle) = 0;

        virtual void setZoom(float amount) = 0;
    };
}
