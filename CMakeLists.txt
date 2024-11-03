cmake_minimum_required(VERSION 3.29)
project(reasonate_cli)

set(CMAKE_CXX_STANDARD 20)

# enable testing
enable_testing()

# add glad to the project
include_directories(libs/glad/include)
add_library(glad libs/glad/src/glad.c)

# add google test to the project
add_subdirectory(libs/googletest)

# project's core library
add_library(reasonate_lib
        util/FileUtil.h
        shader/Shader.cpp
        shader/Shader.h
        shader/ShaderProgram.cpp
        shader/ShaderProgram.h
        util/stb_image.h
        texture/Texture.cpp
        texture/Texture.h
        texture/GLTexture.cpp
        texture/GLTexture.h
        shader/GLShader.cpp
        shader/GLShader.h
        test/texture_test.cpp
        test/test_main.cpp
)

# link external libraries
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# main executable
add_executable(reasonate_cli main.cpp)
target_link_libraries(reasonate_cli reasonate_lib glad glfw OpenGL::GL pthread)

# test executable
add_executable(reasonate_cli_tests test/texture_test.cpp)
target_link_libraries(reasonate_cli_tests reasonate_lib GTest::gtest GTest::gtest_main)

# register test with CTest
add_test(NAME ReasonateTests COMMAND reasonate_cli_tests)