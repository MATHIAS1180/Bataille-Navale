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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Mathias.BOURQUI\CLionProjects\Bataille navale 0.1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Mathias.BOURQUI\CLionProjects\Bataille navale 0.1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Bataille_navale_0_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Bataille_navale_0_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bataille_navale_0_1.dir/flags.make

CMakeFiles/Bataille_navale_0_1.dir/main.c.obj: CMakeFiles/Bataille_navale_0_1.dir/flags.make
CMakeFiles/Bataille_navale_0_1.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Mathias.BOURQUI\CLionProjects\Bataille navale 0.1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Bataille_navale_0_1.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Bataille_navale_0_1.dir\main.c.obj   -c "C:\Users\Mathias.BOURQUI\CLionProjects\Bataille navale 0.1\main.c"

CMakeFiles/Bataille_navale_0_1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Bataille_navale_0_1.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Mathias.BOURQUI\CLionProjects\Bataille navale 0.1\main.c" > CMakeFiles\Bataille_navale_0_1.dir\main.c.i

CMakeFiles/Bataille_navale_0_1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Bataille_navale_0_1.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Mathias.BOURQUI\CLionProjects\Bataille navale 0.1\main.c" -o CMakeFiles\Bataille_navale_0_1.dir\main.c.s

# Object files for target Bataille_navale_0_1
Bataille_navale_0_1_OBJECTS = \
"CMakeFiles/Bataille_navale_0_1.dir/main.c.obj"

# External object files for target Bataille_navale_0_1
Bataille_navale_0_1_EXTERNAL_OBJECTS =

Bataille_navale_0_1.exe: CMakeFiles/Bataille_navale_0_1.dir/main.c.obj
Bataille_navale_0_1.exe: CMakeFiles/Bataille_navale_0_1.dir/build.make
Bataille_navale_0_1.exe: CMakeFiles/Bataille_navale_0_1.dir/linklibs.rsp
Bataille_navale_0_1.exe: CMakeFiles/Bataille_navale_0_1.dir/objects1.rsp
Bataille_navale_0_1.exe: CMakeFiles/Bataille_navale_0_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Mathias.BOURQUI\CLionProjects\Bataille navale 0.1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Bataille_navale_0_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Bataille_navale_0_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bataille_navale_0_1.dir/build: Bataille_navale_0_1.exe

.PHONY : CMakeFiles/Bataille_navale_0_1.dir/build

CMakeFiles/Bataille_navale_0_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Bataille_navale_0_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Bataille_navale_0_1.dir/clean

CMakeFiles/Bataille_navale_0_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Mathias.BOURQUI\CLionProjects\Bataille navale 0.1" "C:\Users\Mathias.BOURQUI\CLionProjects\Bataille navale 0.1" "C:\Users\Mathias.BOURQUI\CLionProjects\Bataille navale 0.1\cmake-build-debug" "C:\Users\Mathias.BOURQUI\CLionProjects\Bataille navale 0.1\cmake-build-debug" "C:\Users\Mathias.BOURQUI\CLionProjects\Bataille navale 0.1\cmake-build-debug\CMakeFiles\Bataille_navale_0_1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Bataille_navale_0_1.dir/depend

