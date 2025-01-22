//
// Created by osklot12 on 1/20/25.
//

module;

#include <memory>
#include <vector>
#include <array>

export module Graphics.Object2D;

import Graphics.Object;
import Graphics.Object2D.Constants;

export namespace Graphics {
    // a graphical object in two dimensions
    class Object2D : public Object {
    public:
        // constructor for shared_ptr
        explicit Object2D(const std::shared_ptr<std::vector<float>>& vertices);

        // constructor for vector
        explicit Object2D(const std::vector<float>& vertices);

        // constructor for array
        template <std::size_t N>
        explicit Object2D(const std::array<float, N> &vertices) : Object(vertices), position(INIT_POS),
        rotation(INIT_ROTATION), scale(INIT_SCALE) {}

        // returns the position coordinates
        [[nodiscard]] const std::array<float, 2> &getPosition() const;

        // sets the position coordinates
        void setPosition(float x, float y);

        // returns the rotation
        [[nodiscard]] float getRotation() const;

        // sets the rotation
        void setRotation(float angle);

        // returns the scale vector
        [[nodiscard]] const std::array<float, 2> &getScale() const;

        // sets the scale
        void setScale(float x, float y);

    private:
        // position vector
        std::array<float, 2> position;

        // counterclockwise rotation in degrees
        float rotation;

        // scale vector
        std::array<float, 2> scale;
    };
}
