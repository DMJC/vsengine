# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_SOURCE_DIR = /home/james/development/privgold/vegastrike-code/vegastrike

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/james/development/privgold/vegastrike-code/vegastrike/build

# Include any dependencies generated for this target.
include objconv/CMakeFiles/trisort.dir/depend.make

# Include the progress variables for this target.
include objconv/CMakeFiles/trisort.dir/progress.make

# Include the compile flags for this target's objects.
include objconv/CMakeFiles/trisort.dir/flags.make

objconv/CMakeFiles/trisort.dir/trisort.cpp.o: objconv/CMakeFiles/trisort.dir/flags.make
objconv/CMakeFiles/trisort.dir/trisort.cpp.o: ../objconv/trisort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/james/development/privgold/vegastrike-code/vegastrike/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object objconv/CMakeFiles/trisort.dir/trisort.cpp.o"
	cd /home/james/development/privgold/vegastrike-code/vegastrike/build/objconv && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/trisort.dir/trisort.cpp.o -c /home/james/development/privgold/vegastrike-code/vegastrike/objconv/trisort.cpp

objconv/CMakeFiles/trisort.dir/trisort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/trisort.dir/trisort.cpp.i"
	cd /home/james/development/privgold/vegastrike-code/vegastrike/build/objconv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/development/privgold/vegastrike-code/vegastrike/objconv/trisort.cpp > CMakeFiles/trisort.dir/trisort.cpp.i

objconv/CMakeFiles/trisort.dir/trisort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/trisort.dir/trisort.cpp.s"
	cd /home/james/development/privgold/vegastrike-code/vegastrike/build/objconv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/development/privgold/vegastrike-code/vegastrike/objconv/trisort.cpp -o CMakeFiles/trisort.dir/trisort.cpp.s

# Object files for target trisort
trisort_OBJECTS = \
"CMakeFiles/trisort.dir/trisort.cpp.o"

# External object files for target trisort
trisort_EXTERNAL_OBJECTS =

objconv/trisort: objconv/CMakeFiles/trisort.dir/trisort.cpp.o
objconv/trisort: objconv/CMakeFiles/trisort.dir/build.make
objconv/trisort: objconv/CMakeFiles/trisort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/james/development/privgold/vegastrike-code/vegastrike/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable trisort"
	cd /home/james/development/privgold/vegastrike-code/vegastrike/build/objconv && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/trisort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
objconv/CMakeFiles/trisort.dir/build: objconv/trisort

.PHONY : objconv/CMakeFiles/trisort.dir/build

objconv/CMakeFiles/trisort.dir/clean:
	cd /home/james/development/privgold/vegastrike-code/vegastrike/build/objconv && $(CMAKE_COMMAND) -P CMakeFiles/trisort.dir/cmake_clean.cmake
.PHONY : objconv/CMakeFiles/trisort.dir/clean

objconv/CMakeFiles/trisort.dir/depend:
	cd /home/james/development/privgold/vegastrike-code/vegastrike/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/james/development/privgold/vegastrike-code/vegastrike /home/james/development/privgold/vegastrike-code/vegastrike/objconv /home/james/development/privgold/vegastrike-code/vegastrike/build /home/james/development/privgold/vegastrike-code/vegastrike/build/objconv /home/james/development/privgold/vegastrike-code/vegastrike/build/objconv/CMakeFiles/trisort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : objconv/CMakeFiles/trisort.dir/depend

