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
CMAKE_SOURCE_DIR = "C:\Users\mathi\Bataille-Navale\Bataille Navale 1.0"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\mathi\Bataille-Navale\Bataille Navale 1.0\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Bataille_Navale_1_0.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Bataille_Navale_1_0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bataille_Navale_1_0.dir/flags.make

CMakeFiles/Bataille_Navale_1_0.dir/main.c.obj: CMakeFiles/Bataille_Navale_1_0.dir/flags.make
CMakeFiles/Bataille_Navale_1_0.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\mathi\Bataille-Navale\Bataille Navale 1.0\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Bataille_Navale_1_0.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Bataille_Navale_1_0.dir\main.c.obj   -c "C:\Users\mathi\Bataille-Navale\Bataille Navale 1.0\main.c"

CMakeFiles/Bataille_Navale_1_0.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Bataille_Navale_1_0.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\mathi\Bataille-Navale\Bataille Navale 1.0\main.c" > CMakeFiles\Bataille_Navale_1_0.dir\main.c.i

CMakeFiles/Bataille_Navale_1_0.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Bataille_Navale_1_0.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\mathi\Bataille-Navale\Bataille Navale 1.0\main.c" -o CMakeFiles\Bataille_Navale_1_0.dir\main.c.s

# Object files for target Bataille_Navale_1_0
Bataille_Navale_1_0_OBJECTS = \
"CMakeFiles/Bataille_Navale_1_0.dir/main.c.obj"

# External object files for target Bataille_Navale_1_0
Bataille_Navale_1_0_EXTERNAL_OBJECTS =

Bataille_Navale_1_0.exe: CMakeFiles/Bataille_Navale_1_0.dir/main.c.obj
Bataille_Navale_1_0.exe: CMakeFiles/Bataille_Navale_1_0.dir/build.make
Bataille_Navale_1_0.exe: CMakeFiles/Bataille_Navale_1_0.dir/linklibs.rsp
Bataille_Navale_1_0.exe: CMakeFiles/Bataille_Navale_1_0.dir/objects1.rsp
Bataille_Navale_1_0.exe: CMakeFiles/Bataille_Navale_1_0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\mathi\Bataille-Navale\Bataille Navale 1.0\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Bataille_Navale_1_0.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Bataille_Navale_1_0.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bataille_Navale_1_0.dir/build: Bataille_Navale_1_0.exe

.PHONY : CMakeFiles/Bataille_Navale_1_0.dir/build

CMakeFiles/Bataille_Navale_1_0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Bataille_Navale_1_0.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Bataille_Navale_1_0.dir/clean

CMakeFiles/Bataille_Navale_1_0.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\mathi\Bataille-Navale\Bataille Navale 1.0" "C:\Users\mathi\Bataille-Navale\Bataille Navale 1.0" "C:\Users\mathi\Bataille-Navale\Bataille Navale 1.0\cmake-build-debug" "C:\Users\mathi\Bataille-Navale\Bataille Navale 1.0\cmake-build-debug" "C:\Users\mathi\Bataille-Navale\Bataille Navale 1.0\cmake-build-debug\CMakeFiles\Bataille_Navale_1_0.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Bataille_Navale_1_0.dir/depend

