#include "../include/Position.hpp"
#include "../include/magic_bitboards.hpp"
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

TEST(Position_getAllWhitePieces, ReturnsZeroWhenNoWhitePiecesExist) {
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

TEST(Position_getAllBlackPieces, ReturnsZeroWhenNoBlackPiecesExist) {
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

TEST(MagicBitboards_RookMasks, RookMaskA1_IgnoresTwoFiles) {
  uint64_t maskRookOnA1 = 0;
  for(uint64_t sq_a_file = 8; sq_a_file <= 56; sq_a_file += 8) {
    maskRookOnA1 |= 1ULL << sq_a_file;
  }
  for(uint64_t sq_rank_one = 1; sq_rank_one <= 7; sq_rank_one++) {
    maskRookOnA1 |= 1ULL << sq_rank_one;
  }
  generateRookMasks();
  ASSERT_EQ(rookMasks[0], maskRookOnA1);
};

TEST(MagicBitboards_RookMasks, RookMaskD4_ReturnsAllFourFiles) {
  uint64_t maskRookOnD4 = 0;
  for(uint64_t sq_d_file = 3; sq_d_file <= 59; sq_d_file += 8) {
    if(sq_d_file == static_cast<uint64_t>(Square::d4)){
      continue;
    } 
    maskRookOnD4 |= 1ULL << sq_d_file;
  }
  for(uint64_t sq_rank_four = 24; sq_rank_four <= 31; sq_rank_four++) {
    if(sq_rank_four == static_cast<uint64_t>(Square::d4)){
      continue;
    } 
    maskRookOnD4 |= 1ULL << sq_rank_four;
  }
  generateRookMasks();
  ASSERT_EQ(rookMasks[27], maskRookOnD4);
};

TEST(MagicBitboards_BishopMasks, BishopMaskA1_IgnoresThreeDiagonols) {
  uint64_t maskBishopOnA1 = 0;
  for(uint64_t sq_diagonol = 9; sq_diagonol <= 63; sq_diagonol += 9) {
    maskBishopOnA1 |= 1ULL << sq_diagonol;
  }
  generateBishopMasks();
  ASSERT_EQ(bishopMasks[static_cast<uint64_t>(Square::a1)], maskBishopOnA1);
};

TEST(MagicBitboards_BishopMasks, BishopMaskC2_ReturnsAllFourDiagonals) {
  uint64_t maskBishopOnC2 = 0;

  //Diagonol (b1-h7)
  for(uint64_t sq_diagonol = 1; sq_diagonol <= 55; sq_diagonol += 9) {
    if(sq_diagonol == static_cast<uint64_t>(Square::c2)){
      continue;
    } 
    maskBishopOnC2 |= 1ULL << sq_diagonol;
  }
  //Diagonol (d1-a4)
  for(uint64_t sq_diagonol = 3; sq_diagonol <= 24; sq_diagonol += 7) {
    if(sq_diagonol == static_cast<uint64_t>(Square::c2)){
      continue;
    } 
    maskBishopOnC2 |= 1ULL << sq_diagonol;
  }
  generateBishopMasks();
  ASSERT_EQ(bishopMasks[static_cast<uint64_t>(Square::c2)], maskBishopOnC2);
};

} // namespace chess