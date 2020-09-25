cmake_minimum_required(VERSION 3.8)
set(PROJECT triangle)

project(${PROJECT} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

set(HEADERS
    triangle.h
)

set(SOURCES
    triangle.cpp
)

add_library(${PROJECT} STATIC ${SOURCES} ${HEADERS})

add_subdirectory(test)