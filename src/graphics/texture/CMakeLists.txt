# add texture sources to the core lib
target_sources(reasonate_lib PRIVATE
        Texture.h
        Texture.cpp
        GLTexture.h
        GLTexture.cpp
)

# include the texture headers for this module
target_include_directories(reasonate_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})