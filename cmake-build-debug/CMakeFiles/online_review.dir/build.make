# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sjhuang/Documents/projects/online_review

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sjhuang/Documents/projects/online_review/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/online_review.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/online_review.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/online_review.dir/flags.make

CMakeFiles/online_review.dir/pdd_410/q4.cpp.o: CMakeFiles/online_review.dir/flags.make
CMakeFiles/online_review.dir/pdd_410/q4.cpp.o: ../pdd_410/q4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sjhuang/Documents/projects/online_review/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/online_review.dir/pdd_410/q4.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/online_review.dir/pdd_410/q4.cpp.o -c /Users/sjhuang/Documents/projects/online_review/pdd_410/q4.cpp

CMakeFiles/online_review.dir/pdd_410/q4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/online_review.dir/pdd_410/q4.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sjhuang/Documents/projects/online_review/pdd_410/q4.cpp > CMakeFiles/online_review.dir/pdd_410/q4.cpp.i

CMakeFiles/online_review.dir/pdd_410/q4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/online_review.dir/pdd_410/q4.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sjhuang/Documents/projects/online_review/pdd_410/q4.cpp -o CMakeFiles/online_review.dir/pdd_410/q4.cpp.s

# Object files for target online_review
online_review_OBJECTS = \
"CMakeFiles/online_review.dir/pdd_410/q4.cpp.o"

# External object files for target online_review
online_review_EXTERNAL_OBJECTS =

online_review: CMakeFiles/online_review.dir/pdd_410/q4.cpp.o
online_review: CMakeFiles/online_review.dir/build.make
online_review: CMakeFiles/online_review.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sjhuang/Documents/projects/online_review/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable online_review"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/online_review.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/online_review.dir/build: online_review

.PHONY : CMakeFiles/online_review.dir/build

CMakeFiles/online_review.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/online_review.dir/cmake_clean.cmake
.PHONY : CMakeFiles/online_review.dir/clean

CMakeFiles/online_review.dir/depend:
	cd /Users/sjhuang/Documents/projects/online_review/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sjhuang/Documents/projects/online_review /Users/sjhuang/Documents/projects/online_review /Users/sjhuang/Documents/projects/online_review/cmake-build-debug /Users/sjhuang/Documents/projects/online_review/cmake-build-debug /Users/sjhuang/Documents/projects/online_review/cmake-build-debug/CMakeFiles/online_review.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/online_review.dir/depend

