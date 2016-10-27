cmake_minimum_required(VERSION 3.6)
project(Alghoritms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES selection_sort.cpp)
add_executable(Alghoritms ${SOURCE_FILES})