# add graphics engine sources to the core library
target_sources(reasonate_lib
        PRIVATE
        base/OpenGlEngine.cpp
        3d/OpenGlEngine3D.h
        3d/OpenGlEngine3D.cpp
        2d/OpenGlEngine2D.h
        2d/OpenGlEngine2D.cpp
        PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES
        base/Engine.ixx
        base/OpenGlEngine.ixx
        2d/Engine2D.ixx
        3d/Engine3D.ixx
        OpenGlStatus.ixx
)
