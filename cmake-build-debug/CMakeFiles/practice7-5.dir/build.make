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
include CMakeFiles/practice7-5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/practice7-5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/practice7-5.dir/flags.make

CMakeFiles/practice7-5.dir/week7/practice7-5.c.obj: CMakeFiles/practice7-5.dir/flags.make
CMakeFiles/practice7-5.dir/week7/practice7-5.c.obj: ../week7/practice7-5.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\choug\CLionProjects\DataStructure\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/practice7-5.dir/week7/practice7-5.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\practice7-5.dir\week7\practice7-5.c.obj   -c C:\Users\choug\CLionProjects\DataStructure\week7\practice7-5.c

CMakeFiles/practice7-5.dir/week7/practice7-5.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/practice7-5.dir/week7/practice7-5.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\choug\CLionProjects\DataStructure\week7\practice7-5.c > CMakeFiles\practice7-5.dir\week7\practice7-5.c.i

CMakeFiles/practice7-5.dir/week7/practice7-5.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/practice7-5.dir/week7/practice7-5.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\choug\CLionProjects\DataStructure\week7\practice7-5.c -o CMakeFiles\practice7-5.dir\week7\practice7-5.c.s

# Object files for target practice7-5
practice7__5_OBJECTS = \
"CMakeFiles/practice7-5.dir/week7/practice7-5.c.obj"

# External object files for target practice7-5
practice7__5_EXTERNAL_OBJECTS =

practice7-5.exe: CMakeFiles/practice7-5.dir/week7/practice7-5.c.obj
practice7-5.exe: CMakeFiles/practice7-5.dir/build.make
practice7-5.exe: CMakeFiles/practice7-5.dir/linklibs.rsp
practice7-5.exe: CMakeFiles/practice7-5.dir/objects1.rsp
practice7-5.exe: CMakeFiles/practice7-5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\choug\CLionProjects\DataStructure\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable practice7-5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\practice7-5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/practice7-5.dir/build: practice7-5.exe

.PHONY : CMakeFiles/practice7-5.dir/build

CMakeFiles/practice7-5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\practice7-5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/practice7-5.dir/clean

CMakeFiles/practice7-5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\choug\CLionProjects\DataStructure C:\Users\choug\CLionProjects\DataStructure C:\Users\choug\CLionProjects\DataStructure\cmake-build-debug C:\Users\choug\CLionProjects\DataStructure\cmake-build-debug C:\Users\choug\CLionProjects\DataStructure\cmake-build-debug\CMakeFiles\practice7-5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/practice7-5.dir/depend
