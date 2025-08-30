#include <array>
#include <cstddef>
#include <cstdint>

namespace chess 
{

template <typename T, std::size_t Row, std::size_t Col>
using BoardArray = std::array<std::array<T, Col>, Row>;

enum class PieceType {
  PAWN,
  KNIGHT,
  BISHOP,
  ROOK,
  QUEEN,
  KING,
  NO_PIECE_TYPE
};

enum class Color {
  WHITE,
  BLACK,
  NO_COLOR
};

enum class Square {
  a1 = 1, b1, c1, d1, e1, f1, g1, h1,
  a2, b2, c2, d2, e2, f2, g2, h2,
  a3, b3, c3, d3, e3, f3, g3, h3,
  a4, b4, c4, d4, e4, f4, g4, h4,
  a5, b5, c5, d5, e5, f5, g5, h5,
  a6, b6, c6, d6, e6, f6, g6, h6,
  a7, b7, c7, d7, e7, f7, g7, h7,
  a8, b8, c8, d8, e8, f8, g8, h8,
};

struct Move {
  PieceType movedPiece;
  uint64_t squareFrom;
  uint64_t squareTo;
};

class Position {
 private:
  // Castling rights
  static constexpr uint8_t WK = 1 << 0;
  static constexpr uint8_t WQ = 1 << 1;
  static constexpr uint8_t BK = 1 << 2;
  static constexpr uint8_t BQ = 1 << 3;

  static constexpr size_t NumPieces = static_cast<size_t>(PieceType::NO_PIECE_TYPE);
  static constexpr size_t NumColors = static_cast<size_t>(Color::NO_COLOR);

  BoardArray<uint64_t, NumColors, NumPieces> board_;
  Color sideToMove_;
  uint8_t castlingRights_;
  uint8_t halfmoveClock_;     // for 50-move draw rule
  uint64_t enPassantSquare_;  // square which a pawn will move to after en passant

 public:
  Position(
      BoardArray<uint64_t, NumColors, NumPieces> board,
      Color sideToMove,
      uint8_t castlingRights,
      uint8_t halfmoveClock,
      uint64_t enPassantSquare)
      : board_(board),
        sideToMove_(sideToMove),
        castlingRights_(castlingRights),
        halfmoveClock_(halfmoveClock),
        enPassantSquare_(enPassantSquare) {}
  Color getPieceColorAt(uint64_t square);
  uint64_t getAllWhitePieces();
  uint64_t getAllBlackPieces();
  uint64_t getOccupancy();
};

}  // namespace chess