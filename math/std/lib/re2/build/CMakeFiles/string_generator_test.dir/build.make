# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/quake/Projects/LuaJIT-Std/re2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/quake/Projects/LuaJIT-Std/re2/build

# Include any dependencies generated for this target.
include CMakeFiles/string_generator_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/string_generator_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/string_generator_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/string_generator_test.dir/flags.make

CMakeFiles/string_generator_test.dir/re2/testing/string_generator_test.cc.o: CMakeFiles/string_generator_test.dir/flags.make
CMakeFiles/string_generator_test.dir/re2/testing/string_generator_test.cc.o: /home/quake/Projects/LuaJIT-Std/re2/re2/testing/string_generator_test.cc
CMakeFiles/string_generator_test.dir/re2/testing/string_generator_test.cc.o: CMakeFiles/string_generator_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quake/Projects/LuaJIT-Std/re2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/string_generator_test.dir/re2/testing/string_generator_test.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/string_generator_test.dir/re2/testing/string_generator_test.cc.o -MF CMakeFiles/string_generator_test.dir/re2/testing/string_generator_test.cc.o.d -o CMakeFiles/string_generator_test.dir/re2/testing/string_generator_test.cc.o -c /home/quake/Projects/LuaJIT-Std/re2/re2/testing/string_generator_test.cc

CMakeFiles/string_generator_test.dir/re2/testing/string_generator_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/string_generator_test.dir/re2/testing/string_generator_test.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quake/Projects/LuaJIT-Std/re2/re2/testing/string_generator_test.cc > CMakeFiles/string_generator_test.dir/re2/testing/string_generator_test.cc.i

CMakeFiles/string_generator_test.dir/re2/testing/string_generator_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/string_generator_test.dir/re2/testing/string_generator_test.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quake/Projects/LuaJIT-Std/re2/re2/testing/string_generator_test.cc -o CMakeFiles/string_generator_test.dir/re2/testing/string_generator_test.cc.s

CMakeFiles/string_generator_test.dir/util/test.cc.o: CMakeFiles/string_generator_test.dir/flags.make
CMakeFiles/string_generator_test.dir/util/test.cc.o: /home/quake/Projects/LuaJIT-Std/re2/util/test.cc
CMakeFiles/string_generator_test.dir/util/test.cc.o: CMakeFiles/string_generator_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quake/Projects/LuaJIT-Std/re2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/string_generator_test.dir/util/test.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/string_generator_test.dir/util/test.cc.o -MF CMakeFiles/string_generator_test.dir/util/test.cc.o.d -o CMakeFiles/string_generator_test.dir/util/test.cc.o -c /home/quake/Projects/LuaJIT-Std/re2/util/test.cc

CMakeFiles/string_generator_test.dir/util/test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/string_generator_test.dir/util/test.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quake/Projects/LuaJIT-Std/re2/util/test.cc > CMakeFiles/string_generator_test.dir/util/test.cc.i

CMakeFiles/string_generator_test.dir/util/test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/string_generator_test.dir/util/test.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quake/Projects/LuaJIT-Std/re2/util/test.cc -o CMakeFiles/string_generator_test.dir/util/test.cc.s

# Object files for target string_generator_test
string_generator_test_OBJECTS = \
"CMakeFiles/string_generator_test.dir/re2/testing/string_generator_test.cc.o" \
"CMakeFiles/string_generator_test.dir/util/test.cc.o"

# External object files for target string_generator_test
string_generator_test_EXTERNAL_OBJECTS =

string_generator_test: CMakeFiles/string_generator_test.dir/re2/testing/string_generator_test.cc.o
string_generator_test: CMakeFiles/string_generator_test.dir/util/test.cc.o
string_generator_test: CMakeFiles/string_generator_test.dir/build.make
string_generator_test: libtesting.a
string_generator_test: libre2.a
string_generator_test: CMakeFiles/string_generator_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/quake/Projects/LuaJIT-Std/re2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable string_generator_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/string_generator_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/string_generator_test.dir/build: string_generator_test
.PHONY : CMakeFiles/string_generator_test.dir/build

CMakeFiles/string_generator_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/string_generator_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/string_generator_test.dir/clean

CMakeFiles/string_generator_test.dir/depend:
	cd /home/quake/Projects/LuaJIT-Std/re2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/quake/Projects/LuaJIT-Std/re2 /home/quake/Projects/LuaJIT-Std/re2 /home/quake/Projects/LuaJIT-Std/re2/build /home/quake/Projects/LuaJIT-Std/re2/build /home/quake/Projects/LuaJIT-Std/re2/build/CMakeFiles/string_generator_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/string_generator_test.dir/depend

