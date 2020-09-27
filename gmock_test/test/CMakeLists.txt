cmake_minimum_required(VERSION 3.8)

set(PROJECT gmock_test)

set(SOURCES
    gmock_test
)

add_executable(${PROJECT} ${SOURCES})
target_link_libraries(${PROJECT} PUBLIC
    gtest
    gmock
    gmock_main
    gmock_frm
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)