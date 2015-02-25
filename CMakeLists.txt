# module swap intel/13.1.0 gcc/4.7.1
# Use cmake -DCMAKE_CXX_COMPILER=g++ -std=c++0x . 
# compile with g++
cmake_minimum_required (VERSION 2.6)
project (LeetcodeTest)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
# configure_file (
#   "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
#   "${PROJECT_BINARY_DIR}/TutorialConfig.h"
#   )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add the executable
add_executable(LeetcodeTest src/LRUCache.cpp)
