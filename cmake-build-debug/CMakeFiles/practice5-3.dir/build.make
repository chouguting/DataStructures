# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\choug\CLionProjects\DataStructure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\choug\CLionProjects\DataStructure\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/practice5-3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/practice5-3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/practice5-3.dir/flags.make

CMakeFiles/practice5-3.dir/week5/practice5-3.cpp.obj: CMakeFiles/practice5-3.dir/flags.make
CMakeFiles/practice5-3.dir/week5/practice5-3.cpp.obj: ../week5/practice5-3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\choug\CLionProjects\DataStructure\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/practice5-3.dir/week5/practice5-3.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\practice5-3.dir\week5\practice5-3.cpp.obj -c C:\Users\choug\CLionProjects\DataStructure\week5\practice5-3.cpp

CMakeFiles/practice5-3.dir/week5/practice5-3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practice5-3.dir/week5/practice5-3.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\choug\CLionProjects\DataStructure\week5\practice5-3.cpp > CMakeFiles\practice5-3.dir\week5\practice5-3.cpp.i

CMakeFiles/practice5-3.dir/week5/practice5-3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practice5-3.dir/week5/practice5-3.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\choug\CLionProjects\DataStructure\week5\practice5-3.cpp -o CMakeFiles\practice5-3.dir\week5\practice5-3.cpp.s

# Object files for target practice5-3
practice5__3_OBJECTS = \
"CMakeFiles/practice5-3.dir/week5/practice5-3.cpp.obj"

# External object files for target practice5-3
practice5__3_EXTERNAL_OBJECTS =

practice5-3.exe: CMakeFiles/practice5-3.dir/week5/practice5-3.cpp.obj
practice5-3.exe: CMakeFiles/practice5-3.dir/build.make
practice5-3.exe: CMakeFiles/practice5-3.dir/linklibs.rsp
practice5-3.exe: CMakeFiles/practice5-3.dir/objects1.rsp
practice5-3.exe: CMakeFiles/practice5-3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\choug\CLionProjects\DataStructure\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable practice5-3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\practice5-3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/practice5-3.dir/build: practice5-3.exe

.PHONY : CMakeFiles/practice5-3.dir/build

CMakeFiles/practice5-3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\practice5-3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/practice5-3.dir/clean

CMakeFiles/practice5-3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\choug\CLionProjects\DataStructure C:\Users\choug\CLionProjects\DataStructure C:\Users\choug\CLionProjects\DataStructure\cmake-build-debug C:\Users\choug\CLionProjects\DataStructure\cmake-build-debug C:\Users\choug\CLionProjects\DataStructure\cmake-build-debug\CMakeFiles\practice5-3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/practice5-3.dir/depend

