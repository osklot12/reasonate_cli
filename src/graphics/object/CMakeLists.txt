# add graphics object sources to the core library
target_sources(reasonate_lib
        PRIVATE
        base/Object.cpp
        2d/Object2D.cpp
        PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES
        base/Object.ixx
        2d/Object2D.ixx
        Object2DConstants.ixx
)
