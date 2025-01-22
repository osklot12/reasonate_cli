//
// Created by osklot12 on 1/19/25.
//

#include <memory>
#include <vector>
#include <array>

import Graphics.Object;

namespace Graphics {
    Object::Object(const std::shared_ptr<std::vector<float>> &vertices) : vertices(vertices) {}

    Object::Object(const std::vector<float> &vertices)
    : vertices(std::make_shared<std::vector<float>>(vertices)) {}

    const std::vector<float> &Object::getVertices() const {
        return *vertices;
    }
}