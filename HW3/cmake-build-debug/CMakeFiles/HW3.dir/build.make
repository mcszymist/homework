# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/CLion/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/CLion/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zym/Desktop/CS411/HW3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zym/Desktop/CS411/HW3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HW3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HW3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW3.dir/flags.make

CMakeFiles/HW3.dir/contigsum_test.cpp.o: CMakeFiles/HW3.dir/flags.make
CMakeFiles/HW3.dir/contigsum_test.cpp.o: ../contigsum_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zym/Desktop/CS411/HW3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HW3.dir/contigsum_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HW3.dir/contigsum_test.cpp.o -c /home/zym/Desktop/CS411/HW3/contigsum_test.cpp

CMakeFiles/HW3.dir/contigsum_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW3.dir/contigsum_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zym/Desktop/CS411/HW3/contigsum_test.cpp > CMakeFiles/HW3.dir/contigsum_test.cpp.i

CMakeFiles/HW3.dir/contigsum_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW3.dir/contigsum_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zym/Desktop/CS411/HW3/contigsum_test.cpp -o CMakeFiles/HW3.dir/contigsum_test.cpp.s

CMakeFiles/HW3.dir/inversions_test.cpp.o: CMakeFiles/HW3.dir/flags.make
CMakeFiles/HW3.dir/inversions_test.cpp.o: ../inversions_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zym/Desktop/CS411/HW3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/HW3.dir/inversions_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HW3.dir/inversions_test.cpp.o -c /home/zym/Desktop/CS411/HW3/inversions_test.cpp

CMakeFiles/HW3.dir/inversions_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW3.dir/inversions_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zym/Desktop/CS411/HW3/inversions_test.cpp > CMakeFiles/HW3.dir/inversions_test.cpp.i

CMakeFiles/HW3.dir/inversions_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW3.dir/inversions_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zym/Desktop/CS411/HW3/inversions_test.cpp -o CMakeFiles/HW3.dir/inversions_test.cpp.s

# Object files for target HW3
HW3_OBJECTS = \
"CMakeFiles/HW3.dir/contigsum_test.cpp.o" \
"CMakeFiles/HW3.dir/inversions_test.cpp.o"

# External object files for target HW3
HW3_EXTERNAL_OBJECTS =

HW3: CMakeFiles/HW3.dir/contigsum_test.cpp.o
HW3: CMakeFiles/HW3.dir/inversions_test.cpp.o
HW3: CMakeFiles/HW3.dir/build.make
HW3: CMakeFiles/HW3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zym/Desktop/CS411/HW3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable HW3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HW3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW3.dir/build: HW3

.PHONY : CMakeFiles/HW3.dir/build

CMakeFiles/HW3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HW3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HW3.dir/clean

CMakeFiles/HW3.dir/depend:
	cd /home/zym/Desktop/CS411/HW3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zym/Desktop/CS411/HW3 /home/zym/Desktop/CS411/HW3 /home/zym/Desktop/CS411/HW3/cmake-build-debug /home/zym/Desktop/CS411/HW3/cmake-build-debug /home/zym/Desktop/CS411/HW3/cmake-build-debug/CMakeFiles/HW3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HW3.dir/depend
