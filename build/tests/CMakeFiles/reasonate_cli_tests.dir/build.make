# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/osklot12/code/reasonate_cli

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/osklot12/code/reasonate_cli/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/reasonate_cli_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/reasonate_cli_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/reasonate_cli_tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/reasonate_cli_tests.dir/flags.make

tests/CMakeFiles/reasonate_cli_tests.dir/codegen:
.PHONY : tests/CMakeFiles/reasonate_cli_tests.dir/codegen

tests/CMakeFiles/reasonate_cli_tests.dir/test_main.cpp.o: tests/CMakeFiles/reasonate_cli_tests.dir/flags.make
tests/CMakeFiles/reasonate_cli_tests.dir/test_main.cpp.o: /home/osklot12/code/reasonate_cli/tests/test_main.cpp
tests/CMakeFiles/reasonate_cli_tests.dir/test_main.cpp.o: tests/CMakeFiles/reasonate_cli_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/osklot12/code/reasonate_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/reasonate_cli_tests.dir/test_main.cpp.o"
	cd /home/osklot12/code/reasonate_cli/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/reasonate_cli_tests.dir/test_main.cpp.o -MF CMakeFiles/reasonate_cli_tests.dir/test_main.cpp.o.d -o CMakeFiles/reasonate_cli_tests.dir/test_main.cpp.o -c /home/osklot12/code/reasonate_cli/tests/test_main.cpp

tests/CMakeFiles/reasonate_cli_tests.dir/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reasonate_cli_tests.dir/test_main.cpp.i"
	cd /home/osklot12/code/reasonate_cli/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osklot12/code/reasonate_cli/tests/test_main.cpp > CMakeFiles/reasonate_cli_tests.dir/test_main.cpp.i

tests/CMakeFiles/reasonate_cli_tests.dir/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reasonate_cli_tests.dir/test_main.cpp.s"
	cd /home/osklot12/code/reasonate_cli/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osklot12/code/reasonate_cli/tests/test_main.cpp -o CMakeFiles/reasonate_cli_tests.dir/test_main.cpp.s

tests/CMakeFiles/reasonate_cli_tests.dir/math/linalg/matrix_test.cpp.o: tests/CMakeFiles/reasonate_cli_tests.dir/flags.make
tests/CMakeFiles/reasonate_cli_tests.dir/math/linalg/matrix_test.cpp.o: /home/osklot12/code/reasonate_cli/tests/math/linalg/matrix_test.cpp
tests/CMakeFiles/reasonate_cli_tests.dir/math/linalg/matrix_test.cpp.o: tests/CMakeFiles/reasonate_cli_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/osklot12/code/reasonate_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/reasonate_cli_tests.dir/math/linalg/matrix_test.cpp.o"
	cd /home/osklot12/code/reasonate_cli/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/reasonate_cli_tests.dir/math/linalg/matrix_test.cpp.o -MF CMakeFiles/reasonate_cli_tests.dir/math/linalg/matrix_test.cpp.o.d -o CMakeFiles/reasonate_cli_tests.dir/math/linalg/matrix_test.cpp.o -c /home/osklot12/code/reasonate_cli/tests/math/linalg/matrix_test.cpp

tests/CMakeFiles/reasonate_cli_tests.dir/math/linalg/matrix_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reasonate_cli_tests.dir/math/linalg/matrix_test.cpp.i"
	cd /home/osklot12/code/reasonate_cli/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osklot12/code/reasonate_cli/tests/math/linalg/matrix_test.cpp > CMakeFiles/reasonate_cli_tests.dir/math/linalg/matrix_test.cpp.i

tests/CMakeFiles/reasonate_cli_tests.dir/math/linalg/matrix_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reasonate_cli_tests.dir/math/linalg/matrix_test.cpp.s"
	cd /home/osklot12/code/reasonate_cli/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osklot12/code/reasonate_cli/tests/math/linalg/matrix_test.cpp -o CMakeFiles/reasonate_cli_tests.dir/math/linalg/matrix_test.cpp.s

# Object files for target reasonate_cli_tests
reasonate_cli_tests_OBJECTS = \
"CMakeFiles/reasonate_cli_tests.dir/test_main.cpp.o" \
"CMakeFiles/reasonate_cli_tests.dir/math/linalg/matrix_test.cpp.o"

# External object files for target reasonate_cli_tests
reasonate_cli_tests_EXTERNAL_OBJECTS =

tests/reasonate_cli_tests: tests/CMakeFiles/reasonate_cli_tests.dir/test_main.cpp.o
tests/reasonate_cli_tests: tests/CMakeFiles/reasonate_cli_tests.dir/math/linalg/matrix_test.cpp.o
tests/reasonate_cli_tests: tests/CMakeFiles/reasonate_cli_tests.dir/build.make
tests/reasonate_cli_tests: tests/CMakeFiles/reasonate_cli_tests.dir/compiler_depend.ts
tests/reasonate_cli_tests: libreasonate_lib.a
tests/reasonate_cli_tests: libglad.a
tests/reasonate_cli_tests: lib/libgtest.a
tests/reasonate_cli_tests: lib/libgtest_main.a
tests/reasonate_cli_tests: lib/libgtest.a
tests/reasonate_cli_tests: tests/CMakeFiles/reasonate_cli_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/osklot12/code/reasonate_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable reasonate_cli_tests"
	cd /home/osklot12/code/reasonate_cli/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reasonate_cli_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/reasonate_cli_tests.dir/build: tests/reasonate_cli_tests
.PHONY : tests/CMakeFiles/reasonate_cli_tests.dir/build

tests/CMakeFiles/reasonate_cli_tests.dir/clean:
	cd /home/osklot12/code/reasonate_cli/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/reasonate_cli_tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/reasonate_cli_tests.dir/clean

tests/CMakeFiles/reasonate_cli_tests.dir/depend:
	cd /home/osklot12/code/reasonate_cli/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/osklot12/code/reasonate_cli /home/osklot12/code/reasonate_cli/tests /home/osklot12/code/reasonate_cli/build /home/osklot12/code/reasonate_cli/build/tests /home/osklot12/code/reasonate_cli/build/tests/CMakeFiles/reasonate_cli_tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/reasonate_cli_tests.dir/depend

