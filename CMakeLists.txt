cmake_minimum_required(VERSION 3.29)
project(reasonate_cli)

set(CMAKE_CXX_STANDARD 20)

include_directories(libs/include)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(glad libs/src/glad.c
        util/FileUtil.h
        shader/Shader.cpp
        shader/Shader.h
        shader/ShaderProgram.cpp
        shader/ShaderProgram.h
        util/stb_image.h
)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GTest REQUIRED)


add_executable(reasonate_cli main.cpp
)

target_link_libraries(reasonate_cli glad glfw OpenGL::GL ${GTEST_LIBRARIES} pthread)
