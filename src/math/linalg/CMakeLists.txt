# adding linalg components to the project
target_sources(reasonate_lib PRIVATE

        PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES Matrix.ixx
)