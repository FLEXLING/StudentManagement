# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "D:\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\HUGE\CLionProjects\StudentManagement

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\HUGE\CLionProjects\StudentManagement\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/StudentManagement.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StudentManagement.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StudentManagement.dir/flags.make

CMakeFiles/StudentManagement.dir/main.cpp.obj: CMakeFiles/StudentManagement.dir/flags.make
CMakeFiles/StudentManagement.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\HUGE\CLionProjects\StudentManagement\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StudentManagement.dir/main.cpp.obj"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\StudentManagement.dir\main.cpp.obj -c C:\Users\HUGE\CLionProjects\StudentManagement\main.cpp

CMakeFiles/StudentManagement.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StudentManagement.dir/main.cpp.i"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\HUGE\CLionProjects\StudentManagement\main.cpp > CMakeFiles\StudentManagement.dir\main.cpp.i

CMakeFiles/StudentManagement.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StudentManagement.dir/main.cpp.s"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\HUGE\CLionProjects\StudentManagement\main.cpp -o CMakeFiles\StudentManagement.dir\main.cpp.s

# Object files for target StudentManagement
StudentManagement_OBJECTS = \
"CMakeFiles/StudentManagement.dir/main.cpp.obj"

# External object files for target StudentManagement
StudentManagement_EXTERNAL_OBJECTS =

StudentManagement.exe: CMakeFiles/StudentManagement.dir/main.cpp.obj
StudentManagement.exe: CMakeFiles/StudentManagement.dir/build.make
StudentManagement.exe: CMakeFiles/StudentManagement.dir/linklibs.rsp
StudentManagement.exe: CMakeFiles/StudentManagement.dir/objects1.rsp
StudentManagement.exe: CMakeFiles/StudentManagement.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\HUGE\CLionProjects\StudentManagement\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable StudentManagement.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\StudentManagement.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StudentManagement.dir/build: StudentManagement.exe

.PHONY : CMakeFiles/StudentManagement.dir/build

CMakeFiles/StudentManagement.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\StudentManagement.dir\cmake_clean.cmake
.PHONY : CMakeFiles/StudentManagement.dir/clean

CMakeFiles/StudentManagement.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\HUGE\CLionProjects\StudentManagement C:\Users\HUGE\CLionProjects\StudentManagement C:\Users\HUGE\CLionProjects\StudentManagement\cmake-build-debug C:\Users\HUGE\CLionProjects\StudentManagement\cmake-build-debug C:\Users\HUGE\CLionProjects\StudentManagement\cmake-build-debug\CMakeFiles\StudentManagement.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StudentManagement.dir/depend
