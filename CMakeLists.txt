cmake_minimum_required(VERSION 3.16)
project(chess_engine_clone VERSION 1.0)

enable_testing()

add_library(position
    src/Position.cpp
    include/Position.hpp
    src/magic_bitboards.cpp
    include/magic_bitboards.hpp
)

target_include_directories(position PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(chess_engine_clone
    src/main.cpp
)

target_link_libraries(chess_engine_clone PUBLIC position)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(board_tests
    test/board_gtest_.cpp
)

target_link_libraries(board_tests
    PRIVATE
    position
    GTest::gtest
    GTest::gtest_main
)

gtest_discover_tests(board_tests)