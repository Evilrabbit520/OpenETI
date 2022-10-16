cmake_minimum_required(VERSION 3.0)

project(client)

SET(CMAKE_BUILD_TYPE "Debug")
add_compile_options(-std=c++11)
include_directories(include)

aux_source_directory(. ROOT)
aux_source_directory(include INCLUDE)
aux_source_directory(src SRCDIR)

#add_executable(CPPLearn source/main.cpp)

IF (WIN32)
	MESSAGE(STATUS "Currently compiled on Windows platform.")
ELSEIF (APPLE)
	MESSAGE(STATUS "Currently compiled on Apple MacOS platform.")
ELSEIF (UNIX)
	MESSAGE(STATUS "Currently compiled on UNIX-like OS's platform.")
ENDIF ()

add_executable(client ${ROOT} ${SRCDIR} ${INCLUDE})

