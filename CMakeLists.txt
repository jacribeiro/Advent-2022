cmake_minimum_required(VERSION 3.22)
project(advent_2022)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(advent_2022 main.cpp day_1/day_1.cpp day_2/day_2.cpp)
