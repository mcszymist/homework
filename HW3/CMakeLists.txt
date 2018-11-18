cmake_minimum_required(VERSION 3.12)
project(HW3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
include_directories(.)

add_executable(HW3
        contigsum.hpp
        contigsum_test.cpp
        inversions.hpp
        inversions_test.cpp
        )
