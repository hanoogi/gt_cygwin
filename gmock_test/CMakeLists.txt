cmake_minimum_required(VERSION 3.8)
set(PROJECT gmock_frm)

project(${PROJECT} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

set(SOURCES
    gmock_frm.cc
)

add_library(${PROJECT} STATIC ${SOURCES})

add_subdirectory(test)