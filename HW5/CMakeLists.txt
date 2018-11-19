cmake_minimum_required(VERSION 3.12)
project(HW3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
include_directories(.)

add_executable(HW5
	build_test2.cpp
		build.hpp build.cpp)
