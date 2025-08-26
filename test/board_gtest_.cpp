#include "../include/Position.hpp"
#include "gtest/gtest.h"

TEST(Position_getPieceColorAt, ReturnsNoColorForEmptySquare) {
  chess::BoardArray<uint64_t, 2, 6> board{};
  chess::Position pos(board, chess::Color::WHITE, 0, 0, 0);
  ASSERT_EQ(pos.getPieceColorAt(1ULL), chess::Color::NO_COLOR);
}
TEST(Position_getPieceColorAt, ReturnsBlackForBlackPiece) {
  chess::BoardArray<uint64_t, 2, 6> board{};
  board[1][0] |= 1ULL;
  chess::Position pos(board, chess::Color::WHITE, 0, 0, 0);
  ASSERT_EQ(pos.getPieceColorAt(1ULL), chess::Color::BLACK);
}
TEST(Position_getPieceColorAt, ReturnsWhiteForWhitePiece) {
  chess::BoardArray<uint64_t, 2, 6> board{};
  board[0][0] |= 1ULL;
  chess::Position pos(board, chess::Color::WHITE, 0, 0, 0);
  ASSERT_EQ(pos.getPieceColorAt(1ULL), chess::Color::WHITE);
}
