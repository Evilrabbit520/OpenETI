cmake_minimum_required(VERSION 3.0)

project(OpenETI)

set(CMAKE_CXX_STANDARD 20)

message(STATUS "root This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "root This is SOURCE dir " ${PROJECT_SOURCE_DIR})

add_subdirectory(ETISrc)
