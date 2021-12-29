cmake_minimum_required(VERSION 3.0)

project(OpenETIUnitTests)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_BUILD_TYPE "Debug")


include_directories(include)


aux_source_directory(. ROOT)
aux_source_directory(src SRCDIR)

link_directories(../../build/lib)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})

#add_executable(CPPLearn source/main.cpp)

add_executable(OpenETIUnitTests ${ROOT} ${SRCDIR})
TARGET_LINK_LIBRARIES(OpenETIUnitTests libOpenETI.dylib)
