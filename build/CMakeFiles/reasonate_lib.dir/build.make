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
include CMakeFiles/reasonate_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/reasonate_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/reasonate_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/reasonate_lib.dir/flags.make

CMakeFiles/reasonate_lib.dir/codegen:
.PHONY : CMakeFiles/reasonate_lib.dir/codegen

CMakeFiles/reasonate_lib.dir/src/graphics/shader/Shader.cpp.o: CMakeFiles/reasonate_lib.dir/flags.make
CMakeFiles/reasonate_lib.dir/src/graphics/shader/Shader.cpp.o: /home/osklot12/code/reasonate_cli/src/graphics/shader/Shader.cpp
CMakeFiles/reasonate_lib.dir/src/graphics/shader/Shader.cpp.o: CMakeFiles/reasonate_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/osklot12/code/reasonate_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/reasonate_lib.dir/src/graphics/shader/Shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reasonate_lib.dir/src/graphics/shader/Shader.cpp.o -MF CMakeFiles/reasonate_lib.dir/src/graphics/shader/Shader.cpp.o.d -o CMakeFiles/reasonate_lib.dir/src/graphics/shader/Shader.cpp.o -c /home/osklot12/code/reasonate_cli/src/graphics/shader/Shader.cpp

CMakeFiles/reasonate_lib.dir/src/graphics/shader/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reasonate_lib.dir/src/graphics/shader/Shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osklot12/code/reasonate_cli/src/graphics/shader/Shader.cpp > CMakeFiles/reasonate_lib.dir/src/graphics/shader/Shader.cpp.i

CMakeFiles/reasonate_lib.dir/src/graphics/shader/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reasonate_lib.dir/src/graphics/shader/Shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osklot12/code/reasonate_cli/src/graphics/shader/Shader.cpp -o CMakeFiles/reasonate_lib.dir/src/graphics/shader/Shader.cpp.s

CMakeFiles/reasonate_lib.dir/src/graphics/shader/GLShader.cpp.o: CMakeFiles/reasonate_lib.dir/flags.make
CMakeFiles/reasonate_lib.dir/src/graphics/shader/GLShader.cpp.o: /home/osklot12/code/reasonate_cli/src/graphics/shader/GLShader.cpp
CMakeFiles/reasonate_lib.dir/src/graphics/shader/GLShader.cpp.o: CMakeFiles/reasonate_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/osklot12/code/reasonate_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/reasonate_lib.dir/src/graphics/shader/GLShader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reasonate_lib.dir/src/graphics/shader/GLShader.cpp.o -MF CMakeFiles/reasonate_lib.dir/src/graphics/shader/GLShader.cpp.o.d -o CMakeFiles/reasonate_lib.dir/src/graphics/shader/GLShader.cpp.o -c /home/osklot12/code/reasonate_cli/src/graphics/shader/GLShader.cpp

CMakeFiles/reasonate_lib.dir/src/graphics/shader/GLShader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reasonate_lib.dir/src/graphics/shader/GLShader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osklot12/code/reasonate_cli/src/graphics/shader/GLShader.cpp > CMakeFiles/reasonate_lib.dir/src/graphics/shader/GLShader.cpp.i

CMakeFiles/reasonate_lib.dir/src/graphics/shader/GLShader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reasonate_lib.dir/src/graphics/shader/GLShader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osklot12/code/reasonate_cli/src/graphics/shader/GLShader.cpp -o CMakeFiles/reasonate_lib.dir/src/graphics/shader/GLShader.cpp.s

CMakeFiles/reasonate_lib.dir/src/graphics/shader/ShaderProgram.cpp.o: CMakeFiles/reasonate_lib.dir/flags.make
CMakeFiles/reasonate_lib.dir/src/graphics/shader/ShaderProgram.cpp.o: /home/osklot12/code/reasonate_cli/src/graphics/shader/ShaderProgram.cpp
CMakeFiles/reasonate_lib.dir/src/graphics/shader/ShaderProgram.cpp.o: CMakeFiles/reasonate_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/osklot12/code/reasonate_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/reasonate_lib.dir/src/graphics/shader/ShaderProgram.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reasonate_lib.dir/src/graphics/shader/ShaderProgram.cpp.o -MF CMakeFiles/reasonate_lib.dir/src/graphics/shader/ShaderProgram.cpp.o.d -o CMakeFiles/reasonate_lib.dir/src/graphics/shader/ShaderProgram.cpp.o -c /home/osklot12/code/reasonate_cli/src/graphics/shader/ShaderProgram.cpp

CMakeFiles/reasonate_lib.dir/src/graphics/shader/ShaderProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reasonate_lib.dir/src/graphics/shader/ShaderProgram.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osklot12/code/reasonate_cli/src/graphics/shader/ShaderProgram.cpp > CMakeFiles/reasonate_lib.dir/src/graphics/shader/ShaderProgram.cpp.i

CMakeFiles/reasonate_lib.dir/src/graphics/shader/ShaderProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reasonate_lib.dir/src/graphics/shader/ShaderProgram.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osklot12/code/reasonate_cli/src/graphics/shader/ShaderProgram.cpp -o CMakeFiles/reasonate_lib.dir/src/graphics/shader/ShaderProgram.cpp.s

CMakeFiles/reasonate_lib.dir/src/graphics/texture/Texture.cpp.o: CMakeFiles/reasonate_lib.dir/flags.make
CMakeFiles/reasonate_lib.dir/src/graphics/texture/Texture.cpp.o: /home/osklot12/code/reasonate_cli/src/graphics/texture/Texture.cpp
CMakeFiles/reasonate_lib.dir/src/graphics/texture/Texture.cpp.o: CMakeFiles/reasonate_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/osklot12/code/reasonate_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/reasonate_lib.dir/src/graphics/texture/Texture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reasonate_lib.dir/src/graphics/texture/Texture.cpp.o -MF CMakeFiles/reasonate_lib.dir/src/graphics/texture/Texture.cpp.o.d -o CMakeFiles/reasonate_lib.dir/src/graphics/texture/Texture.cpp.o -c /home/osklot12/code/reasonate_cli/src/graphics/texture/Texture.cpp

CMakeFiles/reasonate_lib.dir/src/graphics/texture/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reasonate_lib.dir/src/graphics/texture/Texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osklot12/code/reasonate_cli/src/graphics/texture/Texture.cpp > CMakeFiles/reasonate_lib.dir/src/graphics/texture/Texture.cpp.i

CMakeFiles/reasonate_lib.dir/src/graphics/texture/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reasonate_lib.dir/src/graphics/texture/Texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osklot12/code/reasonate_cli/src/graphics/texture/Texture.cpp -o CMakeFiles/reasonate_lib.dir/src/graphics/texture/Texture.cpp.s

CMakeFiles/reasonate_lib.dir/src/graphics/texture/GLTexture.cpp.o: CMakeFiles/reasonate_lib.dir/flags.make
CMakeFiles/reasonate_lib.dir/src/graphics/texture/GLTexture.cpp.o: /home/osklot12/code/reasonate_cli/src/graphics/texture/GLTexture.cpp
CMakeFiles/reasonate_lib.dir/src/graphics/texture/GLTexture.cpp.o: CMakeFiles/reasonate_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/osklot12/code/reasonate_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/reasonate_lib.dir/src/graphics/texture/GLTexture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reasonate_lib.dir/src/graphics/texture/GLTexture.cpp.o -MF CMakeFiles/reasonate_lib.dir/src/graphics/texture/GLTexture.cpp.o.d -o CMakeFiles/reasonate_lib.dir/src/graphics/texture/GLTexture.cpp.o -c /home/osklot12/code/reasonate_cli/src/graphics/texture/GLTexture.cpp

CMakeFiles/reasonate_lib.dir/src/graphics/texture/GLTexture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reasonate_lib.dir/src/graphics/texture/GLTexture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osklot12/code/reasonate_cli/src/graphics/texture/GLTexture.cpp > CMakeFiles/reasonate_lib.dir/src/graphics/texture/GLTexture.cpp.i

CMakeFiles/reasonate_lib.dir/src/graphics/texture/GLTexture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reasonate_lib.dir/src/graphics/texture/GLTexture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osklot12/code/reasonate_cli/src/graphics/texture/GLTexture.cpp -o CMakeFiles/reasonate_lib.dir/src/graphics/texture/GLTexture.cpp.s

# Object files for target reasonate_lib
reasonate_lib_OBJECTS = \
"CMakeFiles/reasonate_lib.dir/src/graphics/shader/Shader.cpp.o" \
"CMakeFiles/reasonate_lib.dir/src/graphics/shader/GLShader.cpp.o" \
"CMakeFiles/reasonate_lib.dir/src/graphics/shader/ShaderProgram.cpp.o" \
"CMakeFiles/reasonate_lib.dir/src/graphics/texture/Texture.cpp.o" \
"CMakeFiles/reasonate_lib.dir/src/graphics/texture/GLTexture.cpp.o"

# External object files for target reasonate_lib
reasonate_lib_EXTERNAL_OBJECTS =

libreasonate_lib.a: CMakeFiles/reasonate_lib.dir/src/graphics/shader/Shader.cpp.o
libreasonate_lib.a: CMakeFiles/reasonate_lib.dir/src/graphics/shader/GLShader.cpp.o
libreasonate_lib.a: CMakeFiles/reasonate_lib.dir/src/graphics/shader/ShaderProgram.cpp.o
libreasonate_lib.a: CMakeFiles/reasonate_lib.dir/src/graphics/texture/Texture.cpp.o
libreasonate_lib.a: CMakeFiles/reasonate_lib.dir/src/graphics/texture/GLTexture.cpp.o
libreasonate_lib.a: CMakeFiles/reasonate_lib.dir/build.make
libreasonate_lib.a: CMakeFiles/reasonate_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/osklot12/code/reasonate_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libreasonate_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/reasonate_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reasonate_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/reasonate_lib.dir/build: libreasonate_lib.a
.PHONY : CMakeFiles/reasonate_lib.dir/build

CMakeFiles/reasonate_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reasonate_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reasonate_lib.dir/clean

CMakeFiles/reasonate_lib.dir/depend:
	cd /home/osklot12/code/reasonate_cli/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/osklot12/code/reasonate_cli /home/osklot12/code/reasonate_cli /home/osklot12/code/reasonate_cli/build /home/osklot12/code/reasonate_cli/build /home/osklot12/code/reasonate_cli/build/CMakeFiles/reasonate_lib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/reasonate_lib.dir/depend

