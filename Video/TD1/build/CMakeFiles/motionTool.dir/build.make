# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.4.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.4.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kaanyagci/Documents/isf/Video/1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kaanyagci/Documents/isf/Video/1/build

# Include any dependencies generated for this target.
include CMakeFiles/motionTool.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/motionTool.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/motionTool.dir/flags.make

CMakeFiles/motionTool.dir/main.cpp.o: CMakeFiles/motionTool.dir/flags.make
CMakeFiles/motionTool.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kaanyagci/Documents/isf/Video/1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/motionTool.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motionTool.dir/main.cpp.o -c /Users/kaanyagci/Documents/isf/Video/1/main.cpp

CMakeFiles/motionTool.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motionTool.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kaanyagci/Documents/isf/Video/1/main.cpp > CMakeFiles/motionTool.dir/main.cpp.i

CMakeFiles/motionTool.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motionTool.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kaanyagci/Documents/isf/Video/1/main.cpp -o CMakeFiles/motionTool.dir/main.cpp.s

CMakeFiles/motionTool.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/motionTool.dir/main.cpp.o.requires

CMakeFiles/motionTool.dir/main.cpp.o.provides: CMakeFiles/motionTool.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/motionTool.dir/build.make CMakeFiles/motionTool.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/motionTool.dir/main.cpp.o.provides

CMakeFiles/motionTool.dir/main.cpp.o.provides.build: CMakeFiles/motionTool.dir/main.cpp.o


CMakeFiles/motionTool.dir/videoframes.cpp.o: CMakeFiles/motionTool.dir/flags.make
CMakeFiles/motionTool.dir/videoframes.cpp.o: ../videoframes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kaanyagci/Documents/isf/Video/1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/motionTool.dir/videoframes.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motionTool.dir/videoframes.cpp.o -c /Users/kaanyagci/Documents/isf/Video/1/videoframes.cpp

CMakeFiles/motionTool.dir/videoframes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motionTool.dir/videoframes.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kaanyagci/Documents/isf/Video/1/videoframes.cpp > CMakeFiles/motionTool.dir/videoframes.cpp.i

CMakeFiles/motionTool.dir/videoframes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motionTool.dir/videoframes.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kaanyagci/Documents/isf/Video/1/videoframes.cpp -o CMakeFiles/motionTool.dir/videoframes.cpp.s

CMakeFiles/motionTool.dir/videoframes.cpp.o.requires:

.PHONY : CMakeFiles/motionTool.dir/videoframes.cpp.o.requires

CMakeFiles/motionTool.dir/videoframes.cpp.o.provides: CMakeFiles/motionTool.dir/videoframes.cpp.o.requires
	$(MAKE) -f CMakeFiles/motionTool.dir/build.make CMakeFiles/motionTool.dir/videoframes.cpp.o.provides.build
.PHONY : CMakeFiles/motionTool.dir/videoframes.cpp.o.provides

CMakeFiles/motionTool.dir/videoframes.cpp.o.provides.build: CMakeFiles/motionTool.dir/videoframes.cpp.o


CMakeFiles/motionTool.dir/motiontools.cpp.o: CMakeFiles/motionTool.dir/flags.make
CMakeFiles/motionTool.dir/motiontools.cpp.o: ../motiontools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kaanyagci/Documents/isf/Video/1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/motionTool.dir/motiontools.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motionTool.dir/motiontools.cpp.o -c /Users/kaanyagci/Documents/isf/Video/1/motiontools.cpp

CMakeFiles/motionTool.dir/motiontools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motionTool.dir/motiontools.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kaanyagci/Documents/isf/Video/1/motiontools.cpp > CMakeFiles/motionTool.dir/motiontools.cpp.i

CMakeFiles/motionTool.dir/motiontools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motionTool.dir/motiontools.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kaanyagci/Documents/isf/Video/1/motiontools.cpp -o CMakeFiles/motionTool.dir/motiontools.cpp.s

CMakeFiles/motionTool.dir/motiontools.cpp.o.requires:

.PHONY : CMakeFiles/motionTool.dir/motiontools.cpp.o.requires

CMakeFiles/motionTool.dir/motiontools.cpp.o.provides: CMakeFiles/motionTool.dir/motiontools.cpp.o.requires
	$(MAKE) -f CMakeFiles/motionTool.dir/build.make CMakeFiles/motionTool.dir/motiontools.cpp.o.provides.build
.PHONY : CMakeFiles/motionTool.dir/motiontools.cpp.o.provides

CMakeFiles/motionTool.dir/motiontools.cpp.o.provides.build: CMakeFiles/motionTool.dir/motiontools.cpp.o


# Object files for target motionTool
motionTool_OBJECTS = \
"CMakeFiles/motionTool.dir/main.cpp.o" \
"CMakeFiles/motionTool.dir/videoframes.cpp.o" \
"CMakeFiles/motionTool.dir/motiontools.cpp.o"

# External object files for target motionTool
motionTool_EXTERNAL_OBJECTS =

motionTool: CMakeFiles/motionTool.dir/main.cpp.o
motionTool: CMakeFiles/motionTool.dir/videoframes.cpp.o
motionTool: CMakeFiles/motionTool.dir/motiontools.cpp.o
motionTool: CMakeFiles/motionTool.dir/build.make
motionTool: /usr/local/lib/libopencv_videostab.2.4.12.dylib
motionTool: /usr/local/lib/libopencv_ts.a
motionTool: /usr/local/lib/libopencv_superres.2.4.12.dylib
motionTool: /usr/local/lib/libopencv_stitching.2.4.12.dylib
motionTool: /usr/local/lib/libopencv_contrib.2.4.12.dylib
motionTool: /usr/local/lib/libopencv_nonfree.2.4.12.dylib
motionTool: /usr/local/lib/libopencv_ocl.2.4.12.dylib
motionTool: /usr/local/lib/libopencv_gpu.2.4.12.dylib
motionTool: /usr/local/lib/libopencv_photo.2.4.12.dylib
motionTool: /usr/local/lib/libopencv_objdetect.2.4.12.dylib
motionTool: /usr/local/lib/libopencv_legacy.2.4.12.dylib
motionTool: /usr/local/lib/libopencv_video.2.4.12.dylib
motionTool: /usr/local/lib/libopencv_ml.2.4.12.dylib
motionTool: /usr/local/lib/libopencv_calib3d.2.4.12.dylib
motionTool: /usr/local/lib/libopencv_features2d.2.4.12.dylib
motionTool: /usr/local/lib/libopencv_highgui.2.4.12.dylib
motionTool: /usr/local/lib/libopencv_imgproc.2.4.12.dylib
motionTool: /usr/local/lib/libopencv_flann.2.4.12.dylib
motionTool: /usr/local/lib/libopencv_core.2.4.12.dylib
motionTool: CMakeFiles/motionTool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kaanyagci/Documents/isf/Video/1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable motionTool"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/motionTool.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/motionTool.dir/build: motionTool

.PHONY : CMakeFiles/motionTool.dir/build

CMakeFiles/motionTool.dir/requires: CMakeFiles/motionTool.dir/main.cpp.o.requires
CMakeFiles/motionTool.dir/requires: CMakeFiles/motionTool.dir/videoframes.cpp.o.requires
CMakeFiles/motionTool.dir/requires: CMakeFiles/motionTool.dir/motiontools.cpp.o.requires

.PHONY : CMakeFiles/motionTool.dir/requires

CMakeFiles/motionTool.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/motionTool.dir/cmake_clean.cmake
.PHONY : CMakeFiles/motionTool.dir/clean

CMakeFiles/motionTool.dir/depend:
	cd /Users/kaanyagci/Documents/isf/Video/1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kaanyagci/Documents/isf/Video/1 /Users/kaanyagci/Documents/isf/Video/1 /Users/kaanyagci/Documents/isf/Video/1/build /Users/kaanyagci/Documents/isf/Video/1/build /Users/kaanyagci/Documents/isf/Video/1/build/CMakeFiles/motionTool.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/motionTool.dir/depend
