# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
include boost/1_61/CMakeFiles/boost_system.dir/depend.make

# Include the progress variables for this target.
include boost/1_61/CMakeFiles/boost_system.dir/progress.make

# Include the compile flags for this target's objects.
include boost/1_61/CMakeFiles/boost_system.dir/flags.make

boost/1_61/CMakeFiles/boost_system.dir/system/src/error_code.cpp.o: boost/1_61/CMakeFiles/boost_system.dir/flags.make
boost/1_61/CMakeFiles/boost_system.dir/system/src/error_code.cpp.o: ../boost/1_61/system/src/error_code.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/james/development/privgold/vegastrike-code/vegastrike/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object boost/1_61/CMakeFiles/boost_system.dir/system/src/error_code.cpp.o"
	cd /home/james/development/privgold/vegastrike-code/vegastrike/build/boost/1_61 && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boost_system.dir/system/src/error_code.cpp.o -c /home/james/development/privgold/vegastrike-code/vegastrike/boost/1_61/system/src/error_code.cpp

boost/1_61/CMakeFiles/boost_system.dir/system/src/error_code.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boost_system.dir/system/src/error_code.cpp.i"
	cd /home/james/development/privgold/vegastrike-code/vegastrike/build/boost/1_61 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/development/privgold/vegastrike-code/vegastrike/boost/1_61/system/src/error_code.cpp > CMakeFiles/boost_system.dir/system/src/error_code.cpp.i

boost/1_61/CMakeFiles/boost_system.dir/system/src/error_code.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boost_system.dir/system/src/error_code.cpp.s"
	cd /home/james/development/privgold/vegastrike-code/vegastrike/build/boost/1_61 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/development/privgold/vegastrike-code/vegastrike/boost/1_61/system/src/error_code.cpp -o CMakeFiles/boost_system.dir/system/src/error_code.cpp.s

boost/1_61/CMakeFiles/boost_system.dir/system/src/error_code.cpp.o.requires:

.PHONY : boost/1_61/CMakeFiles/boost_system.dir/system/src/error_code.cpp.o.requires

boost/1_61/CMakeFiles/boost_system.dir/system/src/error_code.cpp.o.provides: boost/1_61/CMakeFiles/boost_system.dir/system/src/error_code.cpp.o.requires
	$(MAKE) -f boost/1_61/CMakeFiles/boost_system.dir/build.make boost/1_61/CMakeFiles/boost_system.dir/system/src/error_code.cpp.o.provides.build
.PHONY : boost/1_61/CMakeFiles/boost_system.dir/system/src/error_code.cpp.o.provides

boost/1_61/CMakeFiles/boost_system.dir/system/src/error_code.cpp.o.provides.build: boost/1_61/CMakeFiles/boost_system.dir/system/src/error_code.cpp.o


# Object files for target boost_system
boost_system_OBJECTS = \
"CMakeFiles/boost_system.dir/system/src/error_code.cpp.o"

# External object files for target boost_system
boost_system_EXTERNAL_OBJECTS =

boost/1_61/libboost_system.a: boost/1_61/CMakeFiles/boost_system.dir/system/src/error_code.cpp.o
boost/1_61/libboost_system.a: boost/1_61/CMakeFiles/boost_system.dir/build.make
boost/1_61/libboost_system.a: boost/1_61/CMakeFiles/boost_system.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/james/development/privgold/vegastrike-code/vegastrike/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libboost_system.a"
	cd /home/james/development/privgold/vegastrike-code/vegastrike/build/boost/1_61 && $(CMAKE_COMMAND) -P CMakeFiles/boost_system.dir/cmake_clean_target.cmake
	cd /home/james/development/privgold/vegastrike-code/vegastrike/build/boost/1_61 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boost_system.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
boost/1_61/CMakeFiles/boost_system.dir/build: boost/1_61/libboost_system.a

.PHONY : boost/1_61/CMakeFiles/boost_system.dir/build

boost/1_61/CMakeFiles/boost_system.dir/requires: boost/1_61/CMakeFiles/boost_system.dir/system/src/error_code.cpp.o.requires

.PHONY : boost/1_61/CMakeFiles/boost_system.dir/requires

boost/1_61/CMakeFiles/boost_system.dir/clean:
	cd /home/james/development/privgold/vegastrike-code/vegastrike/build/boost/1_61 && $(CMAKE_COMMAND) -P CMakeFiles/boost_system.dir/cmake_clean.cmake
.PHONY : boost/1_61/CMakeFiles/boost_system.dir/clean

boost/1_61/CMakeFiles/boost_system.dir/depend:
	cd /home/james/development/privgold/vegastrike-code/vegastrike/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/james/development/privgold/vegastrike-code/vegastrike /home/james/development/privgold/vegastrike-code/vegastrike/boost/1_61 /home/james/development/privgold/vegastrike-code/vegastrike/build /home/james/development/privgold/vegastrike-code/vegastrike/build/boost/1_61 /home/james/development/privgold/vegastrike-code/vegastrike/build/boost/1_61/CMakeFiles/boost_system.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : boost/1_61/CMakeFiles/boost_system.dir/depend

