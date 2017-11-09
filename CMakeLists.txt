cmake_minimum_required(VERSION 3.8)
project(OK_Projekt)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp map.cpp map.h route.h route.cpp)
add_executable(OK_Projekt ${SOURCE_FILES})