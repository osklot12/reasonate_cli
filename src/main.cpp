#include <array>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "graphics/shader/ShaderProgram.h"
#include "util/FileUtil.h"

#define STB_IMAGE_IMPLEMENTATION

#include "graphics/engine/2d/OpenGlEngine2D.h"

constexpr unsigned int SCR_WIDTH = 800;
constexpr unsigned int SCR_HEIGHT = 600;

import Graphics.Object;
import Graphics.Engine;

int main() {
    Graphics::OpenGlEngine2D engine{};
    engine.run();
}
