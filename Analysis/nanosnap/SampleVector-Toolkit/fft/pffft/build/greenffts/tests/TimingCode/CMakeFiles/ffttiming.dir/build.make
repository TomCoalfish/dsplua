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
include greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/compiler_depend.make

# Include the progress variables for this target.
include greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/progress.make

# Include the compile flags for this target's objects.
include greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/flags.make

greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/fftTiming.c.o: greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/flags.make
greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/fftTiming.c.o: /home/quake/Projects/audio-analysis/src/pffft/greenffts/tests/TimingCode/fftTiming.c
greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/fftTiming.c.o: greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quake/Projects/audio-analysis/src/pffft/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/fftTiming.c.o"
	cd /home/quake/Projects/audio-analysis/src/pffft/build/greenffts/tests/TimingCode && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/fftTiming.c.o -MF CMakeFiles/ffttiming.dir/fftTiming.c.o.d -o CMakeFiles/ffttiming.dir/fftTiming.c.o -c /home/quake/Projects/audio-analysis/src/pffft/greenffts/tests/TimingCode/fftTiming.c

greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/fftTiming.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ffttiming.dir/fftTiming.c.i"
	cd /home/quake/Projects/audio-analysis/src/pffft/build/greenffts/tests/TimingCode && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/quake/Projects/audio-analysis/src/pffft/greenffts/tests/TimingCode/fftTiming.c > CMakeFiles/ffttiming.dir/fftTiming.c.i

greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/fftTiming.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ffttiming.dir/fftTiming.c.s"
	cd /home/quake/Projects/audio-analysis/src/pffft/build/greenffts/tests/TimingCode && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/quake/Projects/audio-analysis/src/pffft/greenffts/tests/TimingCode/fftTiming.c -o CMakeFiles/ffttiming.dir/fftTiming.c.s

# Object files for target ffttiming
ffttiming_OBJECTS = \
"CMakeFiles/ffttiming.dir/fftTiming.c.o"

# External object files for target ffttiming
ffttiming_EXTERNAL_OBJECTS =

greenffts/tests/TimingCode/ffttiming: greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/fftTiming.c.o
greenffts/tests/TimingCode/ffttiming: greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/build.make
greenffts/tests/TimingCode/ffttiming: greenffts/src/libGreenFFT.a
greenffts/tests/TimingCode/ffttiming: greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/quake/Projects/audio-analysis/src/pffft/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ffttiming"
	cd /home/quake/Projects/audio-analysis/src/pffft/build/greenffts/tests/TimingCode && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ffttiming.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/build: greenffts/tests/TimingCode/ffttiming
.PHONY : greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/build

greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/clean:
	cd /home/quake/Projects/audio-analysis/src/pffft/build/greenffts/tests/TimingCode && $(CMAKE_COMMAND) -P CMakeFiles/ffttiming.dir/cmake_clean.cmake
.PHONY : greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/clean

greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/depend:
	cd /home/quake/Projects/audio-analysis/src/pffft/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/quake/Projects/audio-analysis/src/pffft /home/quake/Projects/audio-analysis/src/pffft/greenffts/tests/TimingCode /home/quake/Projects/audio-analysis/src/pffft/build /home/quake/Projects/audio-analysis/src/pffft/build/greenffts/tests/TimingCode /home/quake/Projects/audio-analysis/src/pffft/build/greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : greenffts/tests/TimingCode/CMakeFiles/ffttiming.dir/depend
