# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/138/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/138/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes

# Include any dependencies generated for this target.
include CMakeFiles/dynamicRankingsWithAttributes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dynamicRankingsWithAttributes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dynamicRankingsWithAttributes.dir/flags.make

CMakeFiles/dynamicRankingsWithAttributes.dir/simulation.c.o: CMakeFiles/dynamicRankingsWithAttributes.dir/flags.make
CMakeFiles/dynamicRankingsWithAttributes.dir/simulation.c.o: simulation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/dynamicRankingsWithAttributes.dir/simulation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dynamicRankingsWithAttributes.dir/simulation.c.o   -c /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/simulation.c

CMakeFiles/dynamicRankingsWithAttributes.dir/simulation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dynamicRankingsWithAttributes.dir/simulation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/simulation.c > CMakeFiles/dynamicRankingsWithAttributes.dir/simulation.c.i

CMakeFiles/dynamicRankingsWithAttributes.dir/simulation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dynamicRankingsWithAttributes.dir/simulation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/simulation.c -o CMakeFiles/dynamicRankingsWithAttributes.dir/simulation.c.s

CMakeFiles/dynamicRankingsWithAttributes.dir/include/setting.c.o: CMakeFiles/dynamicRankingsWithAttributes.dir/flags.make
CMakeFiles/dynamicRankingsWithAttributes.dir/include/setting.c.o: include/setting.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/dynamicRankingsWithAttributes.dir/include/setting.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dynamicRankingsWithAttributes.dir/include/setting.c.o   -c /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/include/setting.c

CMakeFiles/dynamicRankingsWithAttributes.dir/include/setting.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dynamicRankingsWithAttributes.dir/include/setting.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/include/setting.c > CMakeFiles/dynamicRankingsWithAttributes.dir/include/setting.c.i

CMakeFiles/dynamicRankingsWithAttributes.dir/include/setting.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dynamicRankingsWithAttributes.dir/include/setting.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/include/setting.c -o CMakeFiles/dynamicRankingsWithAttributes.dir/include/setting.c.s

CMakeFiles/dynamicRankingsWithAttributes.dir/include/inputOutput.c.o: CMakeFiles/dynamicRankingsWithAttributes.dir/flags.make
CMakeFiles/dynamicRankingsWithAttributes.dir/include/inputOutput.c.o: include/inputOutput.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/dynamicRankingsWithAttributes.dir/include/inputOutput.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dynamicRankingsWithAttributes.dir/include/inputOutput.c.o   -c /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/include/inputOutput.c

CMakeFiles/dynamicRankingsWithAttributes.dir/include/inputOutput.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dynamicRankingsWithAttributes.dir/include/inputOutput.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/include/inputOutput.c > CMakeFiles/dynamicRankingsWithAttributes.dir/include/inputOutput.c.i

CMakeFiles/dynamicRankingsWithAttributes.dir/include/inputOutput.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dynamicRankingsWithAttributes.dir/include/inputOutput.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/include/inputOutput.c -o CMakeFiles/dynamicRankingsWithAttributes.dir/include/inputOutput.c.s

CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/dynDHondt.c.o: CMakeFiles/dynamicRankingsWithAttributes.dir/flags.make
CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/dynDHondt.c.o: include/rules/dynDHondt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/dynDHondt.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/dynDHondt.c.o   -c /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/include/rules/dynDHondt.c

CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/dynDHondt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/dynDHondt.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/include/rules/dynDHondt.c > CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/dynDHondt.c.i

CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/dynDHondt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/dynDHondt.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/include/rules/dynDHondt.c -o CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/dynDHondt.c.s

CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/lazyDHondt.c.o: CMakeFiles/dynamicRankingsWithAttributes.dir/flags.make
CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/lazyDHondt.c.o: include/rules/lazyDHondt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/lazyDHondt.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/lazyDHondt.c.o   -c /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/include/rules/lazyDHondt.c

CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/lazyDHondt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/lazyDHondt.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/include/rules/lazyDHondt.c > CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/lazyDHondt.c.i

CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/lazyDHondt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/lazyDHondt.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/include/rules/lazyDHondt.c -o CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/lazyDHondt.c.s

# Object files for target dynamicRankingsWithAttributes
dynamicRankingsWithAttributes_OBJECTS = \
"CMakeFiles/dynamicRankingsWithAttributes.dir/simulation.c.o" \
"CMakeFiles/dynamicRankingsWithAttributes.dir/include/setting.c.o" \
"CMakeFiles/dynamicRankingsWithAttributes.dir/include/inputOutput.c.o" \
"CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/dynDHondt.c.o" \
"CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/lazyDHondt.c.o"

# External object files for target dynamicRankingsWithAttributes
dynamicRankingsWithAttributes_EXTERNAL_OBJECTS =

dynamicRankingsWithAttributes: CMakeFiles/dynamicRankingsWithAttributes.dir/simulation.c.o
dynamicRankingsWithAttributes: CMakeFiles/dynamicRankingsWithAttributes.dir/include/setting.c.o
dynamicRankingsWithAttributes: CMakeFiles/dynamicRankingsWithAttributes.dir/include/inputOutput.c.o
dynamicRankingsWithAttributes: CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/dynDHondt.c.o
dynamicRankingsWithAttributes: CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/lazyDHondt.c.o
dynamicRankingsWithAttributes: CMakeFiles/dynamicRankingsWithAttributes.dir/build.make
dynamicRankingsWithAttributes: CMakeFiles/dynamicRankingsWithAttributes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable dynamicRankingsWithAttributes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dynamicRankingsWithAttributes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dynamicRankingsWithAttributes.dir/build: dynamicRankingsWithAttributes

.PHONY : CMakeFiles/dynamicRankingsWithAttributes.dir/build

CMakeFiles/dynamicRankingsWithAttributes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dynamicRankingsWithAttributes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dynamicRankingsWithAttributes.dir/clean

CMakeFiles/dynamicRankingsWithAttributes.dir/depend:
	cd /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/CMakeFiles/dynamicRankingsWithAttributes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dynamicRankingsWithAttributes.dir/depend

