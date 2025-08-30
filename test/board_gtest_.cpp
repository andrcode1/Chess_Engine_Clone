#include "../include/Position.hpp"
#include "gtest/gtest.h"

namespace chess
{

TEST(Position_getPieceColorAt, ReturnsNoColorForEmptySquare) {
  chess::BoardArray<uint64_t, 2, 6> board{};
  chess::Position pos(board, chess::Color::WHITE, 0, 0, 0);
  ASSERT_EQ(pos.getPieceColorAt(static_cast<uint64_t>(Square::a1)), chess::Color::NO_COLOR);
}
TEST(Position_getPieceColorAt, ReturnsBlackForBlackPiece) {
  chess::BoardArray<uint64_t, 2, 6> board{};
  board[1][0] |= static_cast<uint64_t>(Square::a1);
  chess::Position pos(board, chess::Color::WHITE, 0, 0, 0);
  ASSERT_EQ(pos.getPieceColorAt(static_cast<uint64_t>(Square::a1)), chess::Color::BLACK);
}
TEST(Position_getPieceColorAt, ReturnsWhiteForWhitePiece) {
  chess::BoardArray<uint64_t, 2, 6> board{};
  board[0][0] |= static_cast<uint64_t>(Square::a1);
  chess::Position pos(board, chess::Color::WHITE, 0, 0, 0);
  ASSERT_EQ(pos.getPieceColorAt(static_cast<uint64_t>(Square::a1)), chess::Color::WHITE);
}

TEST(Position_getAllWhitePieces, ReturnsZeroForEmptyBoardAndOnlyBlackBoard) {
  chess::BoardArray<uint64_t, 2, 6> board{};
  uint64_t emptyBoard = 0;
  uint64_t boardWithOnlyBlackPiece = static_cast<uint64_t>(Square::a1);
  chess::Position pos(board, chess::Color::WHITE, 0, 0, 0);
  
  ASSERT_EQ(pos.getAllWhitePieces(), emptyBoard);
  ASSERT_EQ(pos.getAllWhitePieces(), emptyBoard);
}
TEST(Position_getAllWhitePieces, IgnoresBlackPieceAndCountsWhitePiece) {
  chess::BoardArray<uint64_t, 2, 6> board{};
  board[0][1] |= static_cast<uint64_t>(Square::a1);
  board[0][1] |= static_cast<uint64_t>(Square::a2);
  board[1][5] |= static_cast<uint64_t>(Square::b4);

  uint64_t boardOfWhitePieces = 0;
  boardOfWhitePieces |= static_cast<uint64_t>(Square::a1);
  boardOfWhitePieces |= static_cast<uint64_t>(Square::a2);

  chess::Position pos(board, chess::Color::WHITE, 0, 0, 0);
  ASSERT_EQ(pos.getAllWhitePieces(), boardOfWhitePieces);
}

TEST(Position_getAllBlackPieces, ReturnsZeroForEmptyBoardAndOnlyWhiteBoard) {
  chess::BoardArray<uint64_t, 2, 6> board{};
  uint64_t emptyBoard = 0;
  uint64_t boardWithOnlyWhitekPiece = static_cast<uint64_t>(Square::a1);
  chess::Position pos(board, chess::Color::WHITE, 0, 0, 0);
  ASSERT_EQ(pos.getAllBlackPieces(), emptyBoard);
}
TEST(Position_getAllBlackPieces, IgnoresWhitePieceAndCountsBlackPiece) {
  chess::BoardArray<uint64_t, 2, 6> board{};
  board[0][1] |= static_cast<uint64_t>(Square::a1);
  board[0][1] |= static_cast<uint64_t>(Square::a2);
  board[1][5] |= static_cast<uint64_t>(Square::b4);

  uint64_t boardOfBlackPieces = 0;
  boardOfBlackPieces |= static_cast<uint64_t>(Square::b4);

  chess::Position pos(board, chess::Color::WHITE, 0, 0, 0);
  ASSERT_EQ(pos.getAllBlackPieces(), boardOfBlackPieces);
}

} // namespace chess