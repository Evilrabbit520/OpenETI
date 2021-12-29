cmake_minimum_required(VERSION 3.0)

project(CPPDylibTest)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

aux_source_directory(. ROOT)
aux_source_directory(src SRCDIR)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#add_executable(CPPLearn source/main.cpp)

#message("tests----------------------")

add_library(CppDylibTest SHARED ${ROOT} ${SRCDIR})