# adding math components to the project
target_sources(reasonate_lib PRIVATE
        linalg/Matrix.h
)

target_include_directories(reasonate_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})