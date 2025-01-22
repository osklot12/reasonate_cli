//
// Created by osklot12 on 1/20/25.
//

#include <memory>
#include <vector>
#include <array>

import Graphics.Object2D;
import Graphics.Object2D.Constants;

namespace Graphics {
    Object2D::Object2D(const ::std::shared_ptr<::std::vector<float> > &vertices) : Object(vertices), position(INIT_POS),
        rotation(INIT_ROTATION), scale(INIT_SCALE) {
    }

    Object2D::Object2D(const std::vector<float> &vertices) : Object(vertices), position(INIT_POS),
                                                             rotation(INIT_ROTATION),
                                                             scale(INIT_SCALE) {
    }

    const std::array<float, 2> &Object2D::getPosition() const {
        return position;
    }

    void Object2D::setPosition(const float x, const float y) {
        position[0] = x;
        position[1] = y;
    }

   float Object2D::getRotation() const {
       return rotation;
   }

    void Object2D::setRotation(float angle) {
        rotation = angle;
    }

    const std::array<float, 2> &Object2D::getScale() const {
        return scale;
    }

    void Object2D::setScale(const float x, const float y) {
        scale[0] = x;
        scale[1] = y;
    }
}
