#include "../include/Board.hpp"
#include "gtest/gtest.h"

TEST(Position_getPieceColor, ReturnsNoColorForEmptySquare) {
  chess::BoardArray<uint64_t, 2, 6> board{};
  chess::Position pos(board, chess::Color::WHITE, 0, 0, 0);
  ASSERT_EQ(pos.getPieceColor(1ULL), chess::Color::NO_COLOR);
}