cmake_minimum_required(VERSION 3.21)
project(Test_1)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest-main)
include_directories(googletest-main/googletest/include)
include_directories(googletest-main/googlemock/include)

add_executable(Test_1 main.cpp)

target_link_libraries(Test_1 gtest gtest_main)