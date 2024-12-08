# add sources to the core lib
target_sources(reasonate_lib PRIVATE
        FileUtil.h
        stb_image.h
)

# include headers for this module
target_include_directories(reasonate_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})