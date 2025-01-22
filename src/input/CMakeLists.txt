# add input manager sources to the core lib
target_sources(reasonate_lib PRIVATE
        InputManagerOpenGl.h
        InputManagerOpenGl.cpp
        PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES
        InputManager.ixx
        KeyBindings.ixx
)