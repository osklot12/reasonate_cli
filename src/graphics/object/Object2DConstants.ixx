//
// Created by osklot12 on 1/20/25.
//

module;

#include <vector>
#include <array>

export module Graphics.Object2D.Constants;

export namespace Graphics {
    // default values
    constexpr std::array<float, 2> INIT_POS{0, 0};
    constexpr float INIT_ROTATION = 0.0f;
    constexpr std::array<float, 2> INIT_SCALE{1, 1};
}
