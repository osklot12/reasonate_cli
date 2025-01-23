#define STB_IMAGE_IMPLEMENTATION

#include "graphics/engine/2d/OpenGlEngine2D.h"
#include "graphics/program/Epsilon.h"

int main() {
    Graphics::Epsilon epsilon{std::make_unique<Graphics::OpenGlEngine2D>()};
    epsilon.run();
}
