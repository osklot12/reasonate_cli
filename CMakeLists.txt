cmake_minimum_required(VERSION 3.29)
project(reasonate_cli)

# configuring cmake
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API ON)

# enable testing
enable_testing()

# add glad to the project
add_library(glad libs/glad/src/glad.c
        src/graphics/program/Epsilon.cpp)
target_include_directories(glad PUBLIC libs/glad/include)

# add google test to the project
add_subdirectory(libs/googletest)

# declaring core library
add_library(reasonate_lib)
target_link_libraries(reasonate_lib PUBLIC glad)

# add glm to the project
target_include_directories(reasonate_lib PUBLIC libs/glm)

# add src dir
add_subdirectory(src)

# add tests dir
add_subdirectory(tests)

# link external libraries
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# main executable
add_executable(reasonate_cli src/main.cpp)
target_link_libraries(reasonate_cli PRIVATE reasonate_lib glad glfw OpenGL::GL pthread)