# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Ex4_C.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Ex4_C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ex4_C.dir/flags.make

CMakeFiles/Ex4_C.dir/main.c.o: CMakeFiles/Ex4_C.dir/flags.make
CMakeFiles/Ex4_C.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Ex4_C.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Ex4_C.dir/main.c.o   -c /mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/main.c

CMakeFiles/Ex4_C.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ex4_C.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/main.c > CMakeFiles/Ex4_C.dir/main.c.i

CMakeFiles/Ex4_C.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ex4_C.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/main.c -o CMakeFiles/Ex4_C.dir/main.c.s

CMakeFiles/Ex4_C.dir/algo.c.o: CMakeFiles/Ex4_C.dir/flags.make
CMakeFiles/Ex4_C.dir/algo.c.o: ../algo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Ex4_C.dir/algo.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Ex4_C.dir/algo.c.o   -c /mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/algo.c

CMakeFiles/Ex4_C.dir/algo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ex4_C.dir/algo.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/algo.c > CMakeFiles/Ex4_C.dir/algo.c.i

CMakeFiles/Ex4_C.dir/algo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ex4_C.dir/algo.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/algo.c -o CMakeFiles/Ex4_C.dir/algo.c.s

CMakeFiles/Ex4_C.dir/graph.c.o: CMakeFiles/Ex4_C.dir/flags.make
CMakeFiles/Ex4_C.dir/graph.c.o: ../graph.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Ex4_C.dir/graph.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Ex4_C.dir/graph.c.o   -c /mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/graph.c

CMakeFiles/Ex4_C.dir/graph.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ex4_C.dir/graph.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/graph.c > CMakeFiles/Ex4_C.dir/graph.c.i

CMakeFiles/Ex4_C.dir/graph.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ex4_C.dir/graph.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/graph.c -o CMakeFiles/Ex4_C.dir/graph.c.s

# Object files for target Ex4_C
Ex4_C_OBJECTS = \
"CMakeFiles/Ex4_C.dir/main.c.o" \
"CMakeFiles/Ex4_C.dir/algo.c.o" \
"CMakeFiles/Ex4_C.dir/graph.c.o"

# External object files for target Ex4_C
Ex4_C_EXTERNAL_OBJECTS =

Ex4_C: CMakeFiles/Ex4_C.dir/main.c.o
Ex4_C: CMakeFiles/Ex4_C.dir/algo.c.o
Ex4_C: CMakeFiles/Ex4_C.dir/graph.c.o
Ex4_C: CMakeFiles/Ex4_C.dir/build.make
Ex4_C: CMakeFiles/Ex4_C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Ex4_C"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ex4_C.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ex4_C.dir/build: Ex4_C

.PHONY : CMakeFiles/Ex4_C.dir/build

CMakeFiles/Ex4_C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Ex4_C.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Ex4_C.dir/clean

CMakeFiles/Ex4_C.dir/depend:
	cd /mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C /mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C /mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/cmake-build-debug /mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/cmake-build-debug /mnt/c/Users/barak/Documents/GitHub/SystemProg_C/Ex4_C/cmake-build-debug/CMakeFiles/Ex4_C.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ex4_C.dir/depend

