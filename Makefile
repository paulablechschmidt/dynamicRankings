# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/snap/clion/138/bin/cmake/linux/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/snap/clion/138/bin/cmake/linux/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/CMakeFiles /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/paula/Documents/NewSetting/dynamicRankingsWithAttributes/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named dynamicRankingsWithAttributes

# Build rule for target.
dynamicRankingsWithAttributes: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 dynamicRankingsWithAttributes
.PHONY : dynamicRankingsWithAttributes

# fast build rule for target.
dynamicRankingsWithAttributes/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dynamicRankingsWithAttributes.dir/build.make CMakeFiles/dynamicRankingsWithAttributes.dir/build
.PHONY : dynamicRankingsWithAttributes/fast

include/inputOutput.o: include/inputOutput.c.o

.PHONY : include/inputOutput.o

# target to build an object file
include/inputOutput.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dynamicRankingsWithAttributes.dir/build.make CMakeFiles/dynamicRankingsWithAttributes.dir/include/inputOutput.c.o
.PHONY : include/inputOutput.c.o

include/inputOutput.i: include/inputOutput.c.i

.PHONY : include/inputOutput.i

# target to preprocess a source file
include/inputOutput.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dynamicRankingsWithAttributes.dir/build.make CMakeFiles/dynamicRankingsWithAttributes.dir/include/inputOutput.c.i
.PHONY : include/inputOutput.c.i

include/inputOutput.s: include/inputOutput.c.s

.PHONY : include/inputOutput.s

# target to generate assembly for a file
include/inputOutput.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dynamicRankingsWithAttributes.dir/build.make CMakeFiles/dynamicRankingsWithAttributes.dir/include/inputOutput.c.s
.PHONY : include/inputOutput.c.s

include/rules/dynDHondt.o: include/rules/dynDHondt.c.o

.PHONY : include/rules/dynDHondt.o

# target to build an object file
include/rules/dynDHondt.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dynamicRankingsWithAttributes.dir/build.make CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/dynDHondt.c.o
.PHONY : include/rules/dynDHondt.c.o

include/rules/dynDHondt.i: include/rules/dynDHondt.c.i

.PHONY : include/rules/dynDHondt.i

# target to preprocess a source file
include/rules/dynDHondt.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dynamicRankingsWithAttributes.dir/build.make CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/dynDHondt.c.i
.PHONY : include/rules/dynDHondt.c.i

include/rules/dynDHondt.s: include/rules/dynDHondt.c.s

.PHONY : include/rules/dynDHondt.s

# target to generate assembly for a file
include/rules/dynDHondt.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dynamicRankingsWithAttributes.dir/build.make CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/dynDHondt.c.s
.PHONY : include/rules/dynDHondt.c.s

include/rules/lazyDHondt.o: include/rules/lazyDHondt.c.o

.PHONY : include/rules/lazyDHondt.o

# target to build an object file
include/rules/lazyDHondt.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dynamicRankingsWithAttributes.dir/build.make CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/lazyDHondt.c.o
.PHONY : include/rules/lazyDHondt.c.o

include/rules/lazyDHondt.i: include/rules/lazyDHondt.c.i

.PHONY : include/rules/lazyDHondt.i

# target to preprocess a source file
include/rules/lazyDHondt.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dynamicRankingsWithAttributes.dir/build.make CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/lazyDHondt.c.i
.PHONY : include/rules/lazyDHondt.c.i

include/rules/lazyDHondt.s: include/rules/lazyDHondt.c.s

.PHONY : include/rules/lazyDHondt.s

# target to generate assembly for a file
include/rules/lazyDHondt.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dynamicRankingsWithAttributes.dir/build.make CMakeFiles/dynamicRankingsWithAttributes.dir/include/rules/lazyDHondt.c.s
.PHONY : include/rules/lazyDHondt.c.s

include/setting.o: include/setting.c.o

.PHONY : include/setting.o

# target to build an object file
include/setting.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dynamicRankingsWithAttributes.dir/build.make CMakeFiles/dynamicRankingsWithAttributes.dir/include/setting.c.o
.PHONY : include/setting.c.o

include/setting.i: include/setting.c.i

.PHONY : include/setting.i

# target to preprocess a source file
include/setting.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dynamicRankingsWithAttributes.dir/build.make CMakeFiles/dynamicRankingsWithAttributes.dir/include/setting.c.i
.PHONY : include/setting.c.i

include/setting.s: include/setting.c.s

.PHONY : include/setting.s

# target to generate assembly for a file
include/setting.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dynamicRankingsWithAttributes.dir/build.make CMakeFiles/dynamicRankingsWithAttributes.dir/include/setting.c.s
.PHONY : include/setting.c.s

simulation.o: simulation.c.o

.PHONY : simulation.o

# target to build an object file
simulation.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dynamicRankingsWithAttributes.dir/build.make CMakeFiles/dynamicRankingsWithAttributes.dir/simulation.c.o
.PHONY : simulation.c.o

simulation.i: simulation.c.i

.PHONY : simulation.i

# target to preprocess a source file
simulation.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dynamicRankingsWithAttributes.dir/build.make CMakeFiles/dynamicRankingsWithAttributes.dir/simulation.c.i
.PHONY : simulation.c.i

simulation.s: simulation.c.s

.PHONY : simulation.s

# target to generate assembly for a file
simulation.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dynamicRankingsWithAttributes.dir/build.make CMakeFiles/dynamicRankingsWithAttributes.dir/simulation.c.s
.PHONY : simulation.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... dynamicRankingsWithAttributes"
	@echo "... include/inputOutput.o"
	@echo "... include/inputOutput.i"
	@echo "... include/inputOutput.s"
	@echo "... include/rules/dynDHondt.o"
	@echo "... include/rules/dynDHondt.i"
	@echo "... include/rules/dynDHondt.s"
	@echo "... include/rules/lazyDHondt.o"
	@echo "... include/rules/lazyDHondt.i"
	@echo "... include/rules/lazyDHondt.s"
	@echo "... include/setting.o"
	@echo "... include/setting.i"
	@echo "... include/setting.s"
	@echo "... simulation.o"
	@echo "... simulation.i"
	@echo "... simulation.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
