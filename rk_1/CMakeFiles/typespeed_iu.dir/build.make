# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/grigorygusev/bmstu_inf_hw/rk_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/grigorygusev/bmstu_inf_hw/rk_1

# Include any dependencies generated for this target.
include CMakeFiles/typespeed_iu.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/typespeed_iu.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/typespeed_iu.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/typespeed_iu.dir/flags.make

CMakeFiles/typespeed_iu.dir/src/game_logic.c.o: CMakeFiles/typespeed_iu.dir/flags.make
CMakeFiles/typespeed_iu.dir/src/game_logic.c.o: src/game_logic.c
CMakeFiles/typespeed_iu.dir/src/game_logic.c.o: CMakeFiles/typespeed_iu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/grigorygusev/bmstu_inf_hw/rk_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/typespeed_iu.dir/src/game_logic.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/typespeed_iu.dir/src/game_logic.c.o -MF CMakeFiles/typespeed_iu.dir/src/game_logic.c.o.d -o CMakeFiles/typespeed_iu.dir/src/game_logic.c.o -c /Users/grigorygusev/bmstu_inf_hw/rk_1/src/game_logic.c

CMakeFiles/typespeed_iu.dir/src/game_logic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/typespeed_iu.dir/src/game_logic.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/grigorygusev/bmstu_inf_hw/rk_1/src/game_logic.c > CMakeFiles/typespeed_iu.dir/src/game_logic.c.i

CMakeFiles/typespeed_iu.dir/src/game_logic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/typespeed_iu.dir/src/game_logic.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/grigorygusev/bmstu_inf_hw/rk_1/src/game_logic.c -o CMakeFiles/typespeed_iu.dir/src/game_logic.c.s

CMakeFiles/typespeed_iu.dir/src/main.c.o: CMakeFiles/typespeed_iu.dir/flags.make
CMakeFiles/typespeed_iu.dir/src/main.c.o: src/main.c
CMakeFiles/typespeed_iu.dir/src/main.c.o: CMakeFiles/typespeed_iu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/grigorygusev/bmstu_inf_hw/rk_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/typespeed_iu.dir/src/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/typespeed_iu.dir/src/main.c.o -MF CMakeFiles/typespeed_iu.dir/src/main.c.o.d -o CMakeFiles/typespeed_iu.dir/src/main.c.o -c /Users/grigorygusev/bmstu_inf_hw/rk_1/src/main.c

CMakeFiles/typespeed_iu.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/typespeed_iu.dir/src/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/grigorygusev/bmstu_inf_hw/rk_1/src/main.c > CMakeFiles/typespeed_iu.dir/src/main.c.i

CMakeFiles/typespeed_iu.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/typespeed_iu.dir/src/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/grigorygusev/bmstu_inf_hw/rk_1/src/main.c -o CMakeFiles/typespeed_iu.dir/src/main.c.s

CMakeFiles/typespeed_iu.dir/src/text_loader.c.o: CMakeFiles/typespeed_iu.dir/flags.make
CMakeFiles/typespeed_iu.dir/src/text_loader.c.o: src/text_loader.c
CMakeFiles/typespeed_iu.dir/src/text_loader.c.o: CMakeFiles/typespeed_iu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/grigorygusev/bmstu_inf_hw/rk_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/typespeed_iu.dir/src/text_loader.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/typespeed_iu.dir/src/text_loader.c.o -MF CMakeFiles/typespeed_iu.dir/src/text_loader.c.o.d -o CMakeFiles/typespeed_iu.dir/src/text_loader.c.o -c /Users/grigorygusev/bmstu_inf_hw/rk_1/src/text_loader.c

CMakeFiles/typespeed_iu.dir/src/text_loader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/typespeed_iu.dir/src/text_loader.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/grigorygusev/bmstu_inf_hw/rk_1/src/text_loader.c > CMakeFiles/typespeed_iu.dir/src/text_loader.c.i

CMakeFiles/typespeed_iu.dir/src/text_loader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/typespeed_iu.dir/src/text_loader.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/grigorygusev/bmstu_inf_hw/rk_1/src/text_loader.c -o CMakeFiles/typespeed_iu.dir/src/text_loader.c.s

CMakeFiles/typespeed_iu.dir/src/timer.c.o: CMakeFiles/typespeed_iu.dir/flags.make
CMakeFiles/typespeed_iu.dir/src/timer.c.o: src/timer.c
CMakeFiles/typespeed_iu.dir/src/timer.c.o: CMakeFiles/typespeed_iu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/grigorygusev/bmstu_inf_hw/rk_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/typespeed_iu.dir/src/timer.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/typespeed_iu.dir/src/timer.c.o -MF CMakeFiles/typespeed_iu.dir/src/timer.c.o.d -o CMakeFiles/typespeed_iu.dir/src/timer.c.o -c /Users/grigorygusev/bmstu_inf_hw/rk_1/src/timer.c

CMakeFiles/typespeed_iu.dir/src/timer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/typespeed_iu.dir/src/timer.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/grigorygusev/bmstu_inf_hw/rk_1/src/timer.c > CMakeFiles/typespeed_iu.dir/src/timer.c.i

CMakeFiles/typespeed_iu.dir/src/timer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/typespeed_iu.dir/src/timer.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/grigorygusev/bmstu_inf_hw/rk_1/src/timer.c -o CMakeFiles/typespeed_iu.dir/src/timer.c.s

# Object files for target typespeed_iu
typespeed_iu_OBJECTS = \
"CMakeFiles/typespeed_iu.dir/src/game_logic.c.o" \
"CMakeFiles/typespeed_iu.dir/src/main.c.o" \
"CMakeFiles/typespeed_iu.dir/src/text_loader.c.o" \
"CMakeFiles/typespeed_iu.dir/src/timer.c.o"

# External object files for target typespeed_iu
typespeed_iu_EXTERNAL_OBJECTS =

typespeed_iu: CMakeFiles/typespeed_iu.dir/src/game_logic.c.o
typespeed_iu: CMakeFiles/typespeed_iu.dir/src/main.c.o
typespeed_iu: CMakeFiles/typespeed_iu.dir/src/text_loader.c.o
typespeed_iu: CMakeFiles/typespeed_iu.dir/src/timer.c.o
typespeed_iu: CMakeFiles/typespeed_iu.dir/build.make
typespeed_iu: /opt/local/lib/libcurses.dylib
typespeed_iu: CMakeFiles/typespeed_iu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/grigorygusev/bmstu_inf_hw/rk_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable typespeed_iu"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/typespeed_iu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/typespeed_iu.dir/build: typespeed_iu
.PHONY : CMakeFiles/typespeed_iu.dir/build

CMakeFiles/typespeed_iu.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/typespeed_iu.dir/cmake_clean.cmake
.PHONY : CMakeFiles/typespeed_iu.dir/clean

CMakeFiles/typespeed_iu.dir/depend:
	cd /Users/grigorygusev/bmstu_inf_hw/rk_1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/grigorygusev/bmstu_inf_hw/rk_1 /Users/grigorygusev/bmstu_inf_hw/rk_1 /Users/grigorygusev/bmstu_inf_hw/rk_1 /Users/grigorygusev/bmstu_inf_hw/rk_1 /Users/grigorygusev/bmstu_inf_hw/rk_1/CMakeFiles/typespeed_iu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/typespeed_iu.dir/depend

