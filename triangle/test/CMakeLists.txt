cmake_minimum_required(VERSION 3.8)

set(PROJECT triangle_test)

set(SOURCES
    triangle_test
)

add_executable(${PROJECT} ${SOURCES})
target_link_libraries(${PROJECT} PUBLIC
    gtest
    gtest_main
    triangle
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)