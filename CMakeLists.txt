cmake_minimum_required(VERSION 3.16)
project(chess_engine_clone VERSION 1.0)

add_library(board
    src/Board.cpp
    include/Position.hpp
)

target_include_directories(board PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(chess_engine_clone
    src/main.cpp
)

target_link_libraries(chess_engine_clone PUBLIC board)