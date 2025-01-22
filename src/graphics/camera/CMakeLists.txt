# add camera sources to the core lib
target_sources(reasonate_lib PRIVATE
        Camera.h
        Camera.cpp
        Cam2DOpenGl.h
        Cam2DOpenGl.cpp
        PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES
        Camera2D.ixx
)