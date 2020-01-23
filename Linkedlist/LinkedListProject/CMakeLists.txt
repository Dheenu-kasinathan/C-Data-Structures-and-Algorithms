#cmake version to be used
#check by using "cmake --version"
cmake_minimum_required( VERSION 3.0 )

#project_name
project( LinkedListProject )

#set c++ version (optional)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include
include_directories ( ./include )

#target
add_executable( program ./src/main.cpp ./src/linkedlist.cpp )
