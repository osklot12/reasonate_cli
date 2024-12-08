# add test executable
add_executable(reasonate_cli_tests
        test_main.cpp
        math/linalg/matrix_test.cpp
)

# link libraries required by the test executable
target_link_libraries(reasonate_cli_tests
        PRIVATE reasonate_lib
        PRIVATE glad
        PRIVATE GTest::gtest
        PRIVATE GTest::gtest_main
        PRIVATE pthread
)

# register the test executable with CTests
add_test(NAME ReasonateTests COMMAND reasonate_cli_tests)