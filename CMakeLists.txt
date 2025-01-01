cmake_minimum_required(VERSION 3.29)
project(reasonate_cli)

set(CMAKE_CXX_STANDARD 20)

# enable testing
enable_testing()

# add glad to the project
include_directories(libs/glad/include)
add_library(glad libs/glad/src/glad.c
        src/graphics/camera/Camera.cpp
        src/graphics/camera/Camera.h)

# add glm to the project
include_directories(libs/glm)

# add google test to the project
add_subdirectory(libs/googletest)

# declaring core library
add_library(reasonate_lib)

# add src dir
add_subdirectory(src)

# add tests dir
add_subdirectory(tests)

# link external libraries
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# main executable
add_executable(reasonate_cli src/main.cpp)
target_link_libraries(reasonate_cli reasonate_lib glad glfw OpenGL::GL pthread)