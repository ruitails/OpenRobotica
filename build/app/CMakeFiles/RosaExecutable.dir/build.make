# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xhockware/Desktop/OpenRobotica

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xhockware/Desktop/OpenRobotica/build

# Include any dependencies generated for this target.
include app/CMakeFiles/RosaExecutable.dir/depend.make

# Include the progress variables for this target.
include app/CMakeFiles/RosaExecutable.dir/progress.make

# Include the compile flags for this target's objects.
include app/CMakeFiles/RosaExecutable.dir/flags.make

app/CMakeFiles/RosaExecutable.dir/main.c.obj: app/CMakeFiles/RosaExecutable.dir/flags.make
app/CMakeFiles/RosaExecutable.dir/main.c.obj: ../app/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xhockware/Desktop/OpenRobotica/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object app/CMakeFiles/RosaExecutable.dir/main.c.obj"
	cd /home/xhockware/Desktop/OpenRobotica/build/app && /usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RosaExecutable.dir/main.c.obj   -c /home/xhockware/Desktop/OpenRobotica/app/main.c

app/CMakeFiles/RosaExecutable.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RosaExecutable.dir/main.c.i"
	cd /home/xhockware/Desktop/OpenRobotica/build/app && /usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/xhockware/Desktop/OpenRobotica/app/main.c > CMakeFiles/RosaExecutable.dir/main.c.i

app/CMakeFiles/RosaExecutable.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RosaExecutable.dir/main.c.s"
	cd /home/xhockware/Desktop/OpenRobotica/build/app && /usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/xhockware/Desktop/OpenRobotica/app/main.c -o CMakeFiles/RosaExecutable.dir/main.c.s

# Object files for target RosaExecutable
RosaExecutable_OBJECTS = \
"CMakeFiles/RosaExecutable.dir/main.c.obj"

# External object files for target RosaExecutable
RosaExecutable_EXTERNAL_OBJECTS =

app/RosaExecutable.elf: app/CMakeFiles/RosaExecutable.dir/main.c.obj
app/RosaExecutable.elf: app/CMakeFiles/RosaExecutable.dir/build.make
app/RosaExecutable.elf: src/movements/libuno_CORE.a
app/RosaExecutable.elf: src/movements/libmovements_lib.a
app/RosaExecutable.elf: src/movements/libuno_movements.a
app/RosaExecutable.elf: src/movements/libuno_CORE.a
app/RosaExecutable.elf: app/CMakeFiles/RosaExecutable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xhockware/Desktop/OpenRobotica/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable RosaExecutable.elf"
	cd /home/xhockware/Desktop/OpenRobotica/build/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RosaExecutable.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating EEP image"
	cd /home/xhockware/Desktop/OpenRobotica/build/app && /usr/bin/avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 /home/xhockware/Desktop/OpenRobotica/build/app/RosaExecutable.elf /home/xhockware/Desktop/OpenRobotica/build/app/RosaExecutable.eep
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating HEX image"
	cd /home/xhockware/Desktop/OpenRobotica/build/app && /usr/bin/avr-objcopy -O ihex -R .eeprom /home/xhockware/Desktop/OpenRobotica/build/app/RosaExecutable.elf /home/xhockware/Desktop/OpenRobotica/build/app/RosaExecutable.hex
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Calculating image size"
	cd /home/xhockware/Desktop/OpenRobotica/build/app && /usr/bin/cmake -DFIRMWARE_IMAGE=/home/xhockware/Desktop/OpenRobotica/build/app/RosaExecutable.elf -DMCU=atmega328p -DEEPROM_IMAGE=/home/xhockware/Desktop/OpenRobotica/build/app/RosaExecutable.eep -P /home/xhockware/Desktop/OpenRobotica/build/CMakeFiles/FirmwareSize.cmake

# Rule to build all files generated by this target.
app/CMakeFiles/RosaExecutable.dir/build: app/RosaExecutable.elf

.PHONY : app/CMakeFiles/RosaExecutable.dir/build

app/CMakeFiles/RosaExecutable.dir/clean:
	cd /home/xhockware/Desktop/OpenRobotica/build/app && $(CMAKE_COMMAND) -P CMakeFiles/RosaExecutable.dir/cmake_clean.cmake
.PHONY : app/CMakeFiles/RosaExecutable.dir/clean

app/CMakeFiles/RosaExecutable.dir/depend:
	cd /home/xhockware/Desktop/OpenRobotica/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xhockware/Desktop/OpenRobotica /home/xhockware/Desktop/OpenRobotica/app /home/xhockware/Desktop/OpenRobotica/build /home/xhockware/Desktop/OpenRobotica/build/app /home/xhockware/Desktop/OpenRobotica/build/app/CMakeFiles/RosaExecutable.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app/CMakeFiles/RosaExecutable.dir/depend

