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
CMAKE_BINARY_DIR = /home/xiaosa/XiaosaClusterChatServer/bin

# Include any dependencies generated for this target.
include src/CMakeFiles/server_main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/server_main.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/server_main.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/server_main.dir/flags.make

src/CMakeFiles/server_main.dir/Server/ChatServer.cpp.o: src/CMakeFiles/server_main.dir/flags.make
src/CMakeFiles/server_main.dir/Server/ChatServer.cpp.o: ../src/Server/ChatServer.cpp
src/CMakeFiles/server_main.dir/Server/ChatServer.cpp.o: src/CMakeFiles/server_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaosa/XiaosaClusterChatServer/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/server_main.dir/Server/ChatServer.cpp.o"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/server_main.dir/Server/ChatServer.cpp.o -MF CMakeFiles/server_main.dir/Server/ChatServer.cpp.o.d -o CMakeFiles/server_main.dir/Server/ChatServer.cpp.o -c /home/xiaosa/XiaosaClusterChatServer/src/Server/ChatServer.cpp

src/CMakeFiles/server_main.dir/Server/ChatServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_main.dir/Server/ChatServer.cpp.i"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaosa/XiaosaClusterChatServer/src/Server/ChatServer.cpp > CMakeFiles/server_main.dir/Server/ChatServer.cpp.i

src/CMakeFiles/server_main.dir/Server/ChatServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_main.dir/Server/ChatServer.cpp.s"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaosa/XiaosaClusterChatServer/src/Server/ChatServer.cpp -o CMakeFiles/server_main.dir/Server/ChatServer.cpp.s

src/CMakeFiles/server_main.dir/Server/ChatService.cpp.o: src/CMakeFiles/server_main.dir/flags.make
src/CMakeFiles/server_main.dir/Server/ChatService.cpp.o: ../src/Server/ChatService.cpp
src/CMakeFiles/server_main.dir/Server/ChatService.cpp.o: src/CMakeFiles/server_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaosa/XiaosaClusterChatServer/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/server_main.dir/Server/ChatService.cpp.o"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/server_main.dir/Server/ChatService.cpp.o -MF CMakeFiles/server_main.dir/Server/ChatService.cpp.o.d -o CMakeFiles/server_main.dir/Server/ChatService.cpp.o -c /home/xiaosa/XiaosaClusterChatServer/src/Server/ChatService.cpp

src/CMakeFiles/server_main.dir/Server/ChatService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_main.dir/Server/ChatService.cpp.i"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaosa/XiaosaClusterChatServer/src/Server/ChatService.cpp > CMakeFiles/server_main.dir/Server/ChatService.cpp.i

src/CMakeFiles/server_main.dir/Server/ChatService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_main.dir/Server/ChatService.cpp.s"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaosa/XiaosaClusterChatServer/src/Server/ChatService.cpp -o CMakeFiles/server_main.dir/Server/ChatService.cpp.s

src/CMakeFiles/server_main.dir/Server/Database.cpp.o: src/CMakeFiles/server_main.dir/flags.make
src/CMakeFiles/server_main.dir/Server/Database.cpp.o: ../src/Server/Database.cpp
src/CMakeFiles/server_main.dir/Server/Database.cpp.o: src/CMakeFiles/server_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaosa/XiaosaClusterChatServer/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/server_main.dir/Server/Database.cpp.o"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/server_main.dir/Server/Database.cpp.o -MF CMakeFiles/server_main.dir/Server/Database.cpp.o.d -o CMakeFiles/server_main.dir/Server/Database.cpp.o -c /home/xiaosa/XiaosaClusterChatServer/src/Server/Database.cpp

src/CMakeFiles/server_main.dir/Server/Database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_main.dir/Server/Database.cpp.i"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaosa/XiaosaClusterChatServer/src/Server/Database.cpp > CMakeFiles/server_main.dir/Server/Database.cpp.i

src/CMakeFiles/server_main.dir/Server/Database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_main.dir/Server/Database.cpp.s"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaosa/XiaosaClusterChatServer/src/Server/Database.cpp -o CMakeFiles/server_main.dir/Server/Database.cpp.s

src/CMakeFiles/server_main.dir/Server/Redis.cpp.o: src/CMakeFiles/server_main.dir/flags.make
src/CMakeFiles/server_main.dir/Server/Redis.cpp.o: ../src/Server/Redis.cpp
src/CMakeFiles/server_main.dir/Server/Redis.cpp.o: src/CMakeFiles/server_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaosa/XiaosaClusterChatServer/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/server_main.dir/Server/Redis.cpp.o"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/server_main.dir/Server/Redis.cpp.o -MF CMakeFiles/server_main.dir/Server/Redis.cpp.o.d -o CMakeFiles/server_main.dir/Server/Redis.cpp.o -c /home/xiaosa/XiaosaClusterChatServer/src/Server/Redis.cpp

src/CMakeFiles/server_main.dir/Server/Redis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_main.dir/Server/Redis.cpp.i"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaosa/XiaosaClusterChatServer/src/Server/Redis.cpp > CMakeFiles/server_main.dir/Server/Redis.cpp.i

src/CMakeFiles/server_main.dir/Server/Redis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_main.dir/Server/Redis.cpp.s"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaosa/XiaosaClusterChatServer/src/Server/Redis.cpp -o CMakeFiles/server_main.dir/Server/Redis.cpp.s

src/CMakeFiles/server_main.dir/Server/public.cpp.o: src/CMakeFiles/server_main.dir/flags.make
src/CMakeFiles/server_main.dir/Server/public.cpp.o: ../src/Server/public.cpp
src/CMakeFiles/server_main.dir/Server/public.cpp.o: src/CMakeFiles/server_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaosa/XiaosaClusterChatServer/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/server_main.dir/Server/public.cpp.o"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/server_main.dir/Server/public.cpp.o -MF CMakeFiles/server_main.dir/Server/public.cpp.o.d -o CMakeFiles/server_main.dir/Server/public.cpp.o -c /home/xiaosa/XiaosaClusterChatServer/src/Server/public.cpp

src/CMakeFiles/server_main.dir/Server/public.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_main.dir/Server/public.cpp.i"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaosa/XiaosaClusterChatServer/src/Server/public.cpp > CMakeFiles/server_main.dir/Server/public.cpp.i

src/CMakeFiles/server_main.dir/Server/public.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_main.dir/Server/public.cpp.s"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaosa/XiaosaClusterChatServer/src/Server/public.cpp -o CMakeFiles/server_main.dir/Server/public.cpp.s

src/CMakeFiles/server_main.dir/Server/server_main.cpp.o: src/CMakeFiles/server_main.dir/flags.make
src/CMakeFiles/server_main.dir/Server/server_main.cpp.o: ../src/Server/server_main.cpp
src/CMakeFiles/server_main.dir/Server/server_main.cpp.o: src/CMakeFiles/server_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaosa/XiaosaClusterChatServer/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/server_main.dir/Server/server_main.cpp.o"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/server_main.dir/Server/server_main.cpp.o -MF CMakeFiles/server_main.dir/Server/server_main.cpp.o.d -o CMakeFiles/server_main.dir/Server/server_main.cpp.o -c /home/xiaosa/XiaosaClusterChatServer/src/Server/server_main.cpp

src/CMakeFiles/server_main.dir/Server/server_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_main.dir/Server/server_main.cpp.i"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaosa/XiaosaClusterChatServer/src/Server/server_main.cpp > CMakeFiles/server_main.dir/Server/server_main.cpp.i

src/CMakeFiles/server_main.dir/Server/server_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_main.dir/Server/server_main.cpp.s"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaosa/XiaosaClusterChatServer/src/Server/server_main.cpp -o CMakeFiles/server_main.dir/Server/server_main.cpp.s

# Object files for target server_main
server_main_OBJECTS = \
"CMakeFiles/server_main.dir/Server/ChatServer.cpp.o" \
"CMakeFiles/server_main.dir/Server/ChatService.cpp.o" \
"CMakeFiles/server_main.dir/Server/Database.cpp.o" \
"CMakeFiles/server_main.dir/Server/Redis.cpp.o" \
"CMakeFiles/server_main.dir/Server/public.cpp.o" \
"CMakeFiles/server_main.dir/Server/server_main.cpp.o"

# External object files for target server_main
server_main_EXTERNAL_OBJECTS =

src/server_main: src/CMakeFiles/server_main.dir/Server/ChatServer.cpp.o
src/server_main: src/CMakeFiles/server_main.dir/Server/ChatService.cpp.o
src/server_main: src/CMakeFiles/server_main.dir/Server/Database.cpp.o
src/server_main: src/CMakeFiles/server_main.dir/Server/Redis.cpp.o
src/server_main: src/CMakeFiles/server_main.dir/Server/public.cpp.o
src/server_main: src/CMakeFiles/server_main.dir/Server/server_main.cpp.o
src/server_main: src/CMakeFiles/server_main.dir/build.make
src/server_main: src/CMakeFiles/server_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xiaosa/XiaosaClusterChatServer/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable server_main"
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/server_main.dir/build: src/server_main
.PHONY : src/CMakeFiles/server_main.dir/build

src/CMakeFiles/server_main.dir/clean:
	cd /home/xiaosa/XiaosaClusterChatServer/bin/src && $(CMAKE_COMMAND) -P CMakeFiles/server_main.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/server_main.dir/clean

src/CMakeFiles/server_main.dir/depend:
	cd /home/xiaosa/XiaosaClusterChatServer/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xiaosa/XiaosaClusterChatServer /home/xiaosa/XiaosaClusterChatServer/src /home/xiaosa/XiaosaClusterChatServer/bin /home/xiaosa/XiaosaClusterChatServer/bin/src /home/xiaosa/XiaosaClusterChatServer/bin/src/CMakeFiles/server_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/server_main.dir/depend

