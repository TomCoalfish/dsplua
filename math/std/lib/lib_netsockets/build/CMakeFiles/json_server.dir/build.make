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
CMAKE_SOURCE_DIR = /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/build

# Include any dependencies generated for this target.
include CMakeFiles/json_server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/json_server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/json_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/json_server.dir/flags.make

CMakeFiles/json_server.dir/examples/json_server.cc.o: CMakeFiles/json_server.dir/flags.make
CMakeFiles/json_server.dir/examples/json_server.cc.o: /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/examples/json_server.cc
CMakeFiles/json_server.dir/examples/json_server.cc.o: CMakeFiles/json_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/json_server.dir/examples/json_server.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/json_server.dir/examples/json_server.cc.o -MF CMakeFiles/json_server.dir/examples/json_server.cc.o.d -o CMakeFiles/json_server.dir/examples/json_server.cc.o -c /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/examples/json_server.cc

CMakeFiles/json_server.dir/examples/json_server.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/json_server.dir/examples/json_server.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/examples/json_server.cc > CMakeFiles/json_server.dir/examples/json_server.cc.i

CMakeFiles/json_server.dir/examples/json_server.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/json_server.dir/examples/json_server.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/examples/json_server.cc -o CMakeFiles/json_server.dir/examples/json_server.cc.s

CMakeFiles/json_server.dir/examples/json_message.cc.o: CMakeFiles/json_server.dir/flags.make
CMakeFiles/json_server.dir/examples/json_message.cc.o: /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/examples/json_message.cc
CMakeFiles/json_server.dir/examples/json_message.cc.o: CMakeFiles/json_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/json_server.dir/examples/json_message.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/json_server.dir/examples/json_message.cc.o -MF CMakeFiles/json_server.dir/examples/json_message.cc.o.d -o CMakeFiles/json_server.dir/examples/json_message.cc.o -c /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/examples/json_message.cc

CMakeFiles/json_server.dir/examples/json_message.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/json_server.dir/examples/json_message.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/examples/json_message.cc > CMakeFiles/json_server.dir/examples/json_message.cc.i

CMakeFiles/json_server.dir/examples/json_message.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/json_server.dir/examples/json_message.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/examples/json_message.cc -o CMakeFiles/json_server.dir/examples/json_message.cc.s

CMakeFiles/json_server.dir/external/gason/src/gason.cpp.o: CMakeFiles/json_server.dir/flags.make
CMakeFiles/json_server.dir/external/gason/src/gason.cpp.o: /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/external/gason/src/gason.cpp
CMakeFiles/json_server.dir/external/gason/src/gason.cpp.o: CMakeFiles/json_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/json_server.dir/external/gason/src/gason.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/json_server.dir/external/gason/src/gason.cpp.o -MF CMakeFiles/json_server.dir/external/gason/src/gason.cpp.o.d -o CMakeFiles/json_server.dir/external/gason/src/gason.cpp.o -c /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/external/gason/src/gason.cpp

CMakeFiles/json_server.dir/external/gason/src/gason.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/json_server.dir/external/gason/src/gason.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/external/gason/src/gason.cpp > CMakeFiles/json_server.dir/external/gason/src/gason.cpp.i

CMakeFiles/json_server.dir/external/gason/src/gason.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/json_server.dir/external/gason/src/gason.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/external/gason/src/gason.cpp -o CMakeFiles/json_server.dir/external/gason/src/gason.cpp.s

# Object files for target json_server
json_server_OBJECTS = \
"CMakeFiles/json_server.dir/examples/json_server.cc.o" \
"CMakeFiles/json_server.dir/examples/json_message.cc.o" \
"CMakeFiles/json_server.dir/external/gason/src/gason.cpp.o"

# External object files for target json_server
json_server_EXTERNAL_OBJECTS =

json_server: CMakeFiles/json_server.dir/examples/json_server.cc.o
json_server: CMakeFiles/json_server.dir/examples/json_message.cc.o
json_server: CMakeFiles/json_server.dir/external/gason/src/gason.cpp.o
json_server: CMakeFiles/json_server.dir/build.make
json_server: liblib_netsockets.a
json_server: CMakeFiles/json_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable json_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/json_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/json_server.dir/build: json_server
.PHONY : CMakeFiles/json_server.dir/build

CMakeFiles/json_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/json_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/json_server.dir/clean

CMakeFiles/json_server.dir/depend:
	cd /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/build /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/build /home/quake/Projects/LuaJIT-Std/lib_netsockets/lib_netsockets/build/CMakeFiles/json_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/json_server.dir/depend
