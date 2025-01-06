//
// Created by osklot12 on 1/3/25.
//

#ifndef REASONATE_CLI_GRAPHICSENGINECONFIG_H
#define REASONATE_CLI_GRAPHICSENGINECONFIG_H

#include <string>

// namespace for graphics related configurations
namespace GraphicsConfig {
    // default window dimensions
    constexpr unsigned int WINDOW_WIDTH = 800;
    constexpr unsigned int WINDOW_HEIGHT = 600;

    // default window title
    constexpr std::string WINDOW_TITLE = "Graphics Engine";

    // opengl core profile version
    constexpr unsigned int CONTEXT_VERSION_MAJOR = 3;
    constexpr unsigned int CONTEXT_VERSION_MINOR = 3;
}


#endif //REASONATE_CLI_GRAPHICSENGINECONFIG_H
