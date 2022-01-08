cmake_minimum_required(VERSION 3.21)
project(Test_3)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest-main)
include_directories(googletest-main/googletest/include)
include_directories(googletest-main/googlemock/include)

add_executable(Test_3 main.cpp main.h)

target_link_libraries(Test_3 gtest gtest_main)