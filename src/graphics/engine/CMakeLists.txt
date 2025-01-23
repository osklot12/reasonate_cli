# add subdirectories
add_subdirectory(base)
add_subdirectory(2d)
add_subdirectory(3d)

# add graphics engine sources to the core library
target_sources(reasonate_lib PRIVATE
        OpenGlStatus.h
)
