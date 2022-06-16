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
CMAKE_SOURCE_DIR = /home/quake/Projects/audio-analysis/src/pffft

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/quake/Projects/audio-analysis/src/pffft/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/flags.make

examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/example_cpp11_cplx_dbl_fwd.cpp.o: examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/flags.make
examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/example_cpp11_cplx_dbl_fwd.cpp.o: /home/quake/Projects/audio-analysis/src/pffft/examples/example_cpp11_cplx_dbl_fwd.cpp
examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/example_cpp11_cplx_dbl_fwd.cpp.o: examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quake/Projects/audio-analysis/src/pffft/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/example_cpp11_cplx_dbl_fwd.cpp.o"
	cd /home/quake/Projects/audio-analysis/src/pffft/build/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/example_cpp11_cplx_dbl_fwd.cpp.o -MF CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/example_cpp11_cplx_dbl_fwd.cpp.o.d -o CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/example_cpp11_cplx_dbl_fwd.cpp.o -c /home/quake/Projects/audio-analysis/src/pffft/examples/example_cpp11_cplx_dbl_fwd.cpp

examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/example_cpp11_cplx_dbl_fwd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/example_cpp11_cplx_dbl_fwd.cpp.i"
	cd /home/quake/Projects/audio-analysis/src/pffft/build/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quake/Projects/audio-analysis/src/pffft/examples/example_cpp11_cplx_dbl_fwd.cpp > CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/example_cpp11_cplx_dbl_fwd.cpp.i

examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/example_cpp11_cplx_dbl_fwd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/example_cpp11_cplx_dbl_fwd.cpp.s"
	cd /home/quake/Projects/audio-analysis/src/pffft/build/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quake/Projects/audio-analysis/src/pffft/examples/example_cpp11_cplx_dbl_fwd.cpp -o CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/example_cpp11_cplx_dbl_fwd.cpp.s

# Object files for target example_cpp11_cplx_dbl_fwd
example_cpp11_cplx_dbl_fwd_OBJECTS = \
"CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/example_cpp11_cplx_dbl_fwd.cpp.o"

# External object files for target example_cpp11_cplx_dbl_fwd
example_cpp11_cplx_dbl_fwd_EXTERNAL_OBJECTS =

examples/example_cpp11_cplx_dbl_fwd: examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/example_cpp11_cplx_dbl_fwd.cpp.o
examples/example_cpp11_cplx_dbl_fwd: examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/build.make
examples/example_cpp11_cplx_dbl_fwd: libpffft.a
examples/example_cpp11_cplx_dbl_fwd: examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/quake/Projects/audio-analysis/src/pffft/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example_cpp11_cplx_dbl_fwd"
	cd /home/quake/Projects/audio-analysis/src/pffft/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/build: examples/example_cpp11_cplx_dbl_fwd
.PHONY : examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/build

examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/clean:
	cd /home/quake/Projects/audio-analysis/src/pffft/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/clean

examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/depend:
	cd /home/quake/Projects/audio-analysis/src/pffft/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/quake/Projects/audio-analysis/src/pffft /home/quake/Projects/audio-analysis/src/pffft/examples /home/quake/Projects/audio-analysis/src/pffft/build /home/quake/Projects/audio-analysis/src/pffft/build/examples /home/quake/Projects/audio-analysis/src/pffft/build/examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/example_cpp11_cplx_dbl_fwd.dir/depend

