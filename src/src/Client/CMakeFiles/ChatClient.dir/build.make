# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xiaosa/XiaosaClusterChatServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xiaosa/XiaosaClusterChatServer/src

# Include any dependencies generated for this target.
include src/Client/CMakeFiles/ChatClient.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/Client/CMakeFiles/ChatClient.dir/compiler_depend.make

# Include the progress variables for this target.
include src/Client/CMakeFiles/ChatClient.dir/progress.make

# Include the compile flags for this target's objects.
include src/Client/CMakeFiles/ChatClient.dir/flags.make

src/Client/CMakeFiles/ChatClient.dir/client_main.cpp.o: src/Client/CMakeFiles/ChatClient.dir/flags.make
src/Client/CMakeFiles/ChatClient.dir/client_main.cpp.o: Client/client_main.cpp
src/Client/CMakeFiles/ChatClient.dir/client_main.cpp.o: src/Client/CMakeFiles/ChatClient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaosa/XiaosaClusterChatServer/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Client/CMakeFiles/ChatClient.dir/client_main.cpp.o"
	cd /home/xiaosa/XiaosaClusterChatServer/src/src/Client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Client/CMakeFiles/ChatClient.dir/client_main.cpp.o -MF CMakeFiles/ChatClient.dir/client_main.cpp.o.d -o CMakeFiles/ChatClient.dir/client_main.cpp.o -c /home/xiaosa/XiaosaClusterChatServer/src/Client/client_main.cpp

src/Client/CMakeFiles/ChatClient.dir/client_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChatClient.dir/client_main.cpp.i"
	cd /home/xiaosa/XiaosaClusterChatServer/src/src/Client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaosa/XiaosaClusterChatServer/src/Client/client_main.cpp > CMakeFiles/ChatClient.dir/client_main.cpp.i

src/Client/CMakeFiles/ChatClient.dir/client_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChatClient.dir/client_main.cpp.s"
	cd /home/xiaosa/XiaosaClusterChatServer/src/src/Client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaosa/XiaosaClusterChatServer/src/Client/client_main.cpp -o CMakeFiles/ChatClient.dir/client_main.cpp.s

# Object files for target ChatClient
ChatClient_OBJECTS = \
"CMakeFiles/ChatClient.dir/client_main.cpp.o"

# External object files for target ChatClient
ChatClient_EXTERNAL_OBJECTS =

../bin/ChatClient: src/Client/CMakeFiles/ChatClient.dir/client_main.cpp.o
../bin/ChatClient: src/Client/CMakeFiles/ChatClient.dir/build.make
../bin/ChatClient: src/Client/CMakeFiles/ChatClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xiaosa/XiaosaClusterChatServer/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../bin/ChatClient"
	cd /home/xiaosa/XiaosaClusterChatServer/src/src/Client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ChatClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Client/CMakeFiles/ChatClient.dir/build: ../bin/ChatClient
.PHONY : src/Client/CMakeFiles/ChatClient.dir/build

src/Client/CMakeFiles/ChatClient.dir/clean:
	cd /home/xiaosa/XiaosaClusterChatServer/src/src/Client && $(CMAKE_COMMAND) -P CMakeFiles/ChatClient.dir/cmake_clean.cmake
.PHONY : src/Client/CMakeFiles/ChatClient.dir/clean

src/Client/CMakeFiles/ChatClient.dir/depend:
	cd /home/xiaosa/XiaosaClusterChatServer/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xiaosa/XiaosaClusterChatServer /home/xiaosa/XiaosaClusterChatServer/src/Client /home/xiaosa/XiaosaClusterChatServer/src /home/xiaosa/XiaosaClusterChatServer/src/src/Client /home/xiaosa/XiaosaClusterChatServer/src/src/Client/CMakeFiles/ChatClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Client/CMakeFiles/ChatClient.dir/depend

