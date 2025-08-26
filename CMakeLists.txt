cmake_minimum_required(VERSION 3.16)
project(chess_engine_clone VERSION 1.0)

enable_testing()

add_library(board
    src/Position.cpp
    include/Position.hpp
)

target_include_directories(board PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(chess_engine_clone
    src/main.cpp
)

target_link_libraries(chess_engine_clone PUBLIC board)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(board_tests
    test/board_gtest_.cpp
)

target_link_libraries(board_tests
    PRIVATE
    board
    GTest::gtest
    GTest::gtest_main
)

gtest_discover_tests(board_tests)