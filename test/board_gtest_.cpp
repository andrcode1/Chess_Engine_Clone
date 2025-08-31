#include "../include/Position.hpp"
#include "gtest/gtest.h"

namespace chess
{

TEST(Position_getPieceColorAt, ReturnsNoColorForEmptySquare) {
  BoardArray<uint64_t, 2, 6> board{};
  Position pos(board, Color::WHITE, 0, 0, 0);
  ASSERT_EQ(pos.getPieceColorAt(static_cast<uint64_t>(Square::a1)), Color::NO_COLOR);
}
TEST(Position_getPieceColorAt, ReturnsBlackForBlackPiece) {
  BoardArray<uint64_t, 2, 6> board{};
  board[1][0] |= 1ULL << static_cast<uint64_t>(Square::a1);
  Position pos(board, Color::WHITE, 0, 0, 0);
  ASSERT_EQ(pos.getPieceColorAt(static_cast<uint64_t>(Square::a1)), Color::BLACK);
}
TEST(Position_getPieceColorAt, ReturnsWhiteForWhitePiece) {
  BoardArray<uint64_t, 2, 6> board{};
  board[0][0] |= 1ULL << static_cast<uint64_t>(Square::a1);
  Position pos(board, Color::WHITE, 0, 0, 0);
  ASSERT_EQ(pos.getPieceColorAt(static_cast<uint64_t>(Square::a1)), Color::WHITE);
}

TEST(Position_getAllWhitePieces, ReturnsZeroForEmptyBoardAndOnlyBlackBoard) {
  BoardArray<uint64_t, 2, 6> board{};
  Position pos(board, Color::WHITE, 0, 0, 0);
  uint64_t emptyBoard = 0;

  ASSERT_EQ(pos.getAllWhitePieces(), emptyBoard);

  BoardArray<uint64_t, 2, 6> boardWithOnlyBlackPiece{};
  boardWithOnlyBlackPiece[1][0] = 1ULL << static_cast<uint64_t>(Square::a1);
  Position posOnlyBlackPieces(boardWithOnlyBlackPiece, Color::WHITE, 0, 0, 0);
  
  ASSERT_EQ(posOnlyBlackPieces.getAllWhitePieces(), emptyBoard);
}
TEST(Position_getAllWhitePieces, IgnoresBlackPieceAndCountsWhitePiece) {
  BoardArray<uint64_t, 2, 6> board{};
  board[0][1] |= 1ULL << static_cast<uint64_t>(Square::a1);
  board[0][1] |= 1ULL << static_cast<uint64_t>(Square::a2);
  board[1][5] |= 1ULL << static_cast<uint64_t>(Square::b4);
  Position pos(board, Color::WHITE, 0, 0, 0);

  uint64_t boardOfWhitePieces = 0;
  boardOfWhitePieces |= 1ULL << static_cast<uint64_t>(Square::a1);
  boardOfWhitePieces |= 1ULL << static_cast<uint64_t>(Square::a2);

  ASSERT_EQ(pos.getAllWhitePieces(), boardOfWhitePieces);
}

TEST(Position_getAllBlackPieces, ReturnsZeroForEmptyBoardAndOnlyWhiteBoard) {
  BoardArray<uint64_t, 2, 6> board{};
  Position pos(board, Color::WHITE, 0, 0, 0);
  uint64_t emptyBoard = 0;
  ASSERT_EQ(pos.getAllBlackPieces(), emptyBoard);

  BoardArray<uint64_t, 2, 6> boardWithOnlyWhitePiece{};
  boardWithOnlyWhitePiece[0][0] = 1ULL << static_cast<uint64_t>(Square::a1);
  Position posOnlyWhitePiece(boardWithOnlyWhitePiece, Color::WHITE, 0, 0, 0);
  ASSERT_EQ(posOnlyWhitePiece.getAllBlackPieces(), emptyBoard);
}
TEST(Position_getAllBlackPieces, IgnoresWhitePieceAndCountsBlackPiece) {
  BoardArray<uint64_t, 2, 6> board{};
  board[0][1] |= 1ULL << static_cast<uint64_t>(Square::a1);
  board[0][1] |= 1ULL << static_cast<uint64_t>(Square::a2);
  board[1][5] |= 1ULL << static_cast<uint64_t>(Square::b4);
  Position pos(board, Color::WHITE, 0, 0, 0);

  uint64_t boardOfBlackPieces = 0;
  boardOfBlackPieces |= 1ULL << static_cast<uint64_t>(Square::b4);

  ASSERT_EQ(pos.getAllBlackPieces(), boardOfBlackPieces);
}

} // namespace chess