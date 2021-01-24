cmake_minimum_required(VERSION 3.19)
project(algorithms)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(benchmark REQUIRED)
find_package(GTest REQUIRED)

add_subdirectory(sorting)
add_subdirectory(utility)

