cmake_minimum_required(VERSION 3.21)
project(Lab6_1)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(LibGTests/googletest-main)
include_directories(LibGTests/googletest-main/googletest/include)
include_directories(LibGTests/googletest-main/googlemock/include)
add_executable(Lab6_1 Lab6_1.cpp Test1/Test1.cpp Test1/Test1.h)
target_link_libraries(Lab6_1 gtest gtest_main)
