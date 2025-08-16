#include <array>
#include <cstddef>
#include <cstdint>

namespace chess {

template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

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

class Position {
 private:
  // Castling rights
  static constexpr uint8_t WK = 1 << 0;
  static constexpr uint8_t WQ = 1 << 1;
  static constexpr uint8_t BK = 1 << 2;
  static constexpr uint8_t BQ = 1 << 3;

  static constexpr size_t NumPieces = static_cast<size_t>(PieceType::NO_PIECE_TYPE) - 1;
  static constexpr size_t NumColors = static_cast<size_t>(Color::NO_COLOR) - 1;

  Array2d<uint64_t, NumColors, NumPieces> board_;
  Color sideToMove_;
  uint8_t castlingRights_;
  uint8_t halfmoveClock_;     // for 50-move draw rule
  uint64_t enPassantSquare_;  // square which a pawn will move to after en passant

 public:
  Position(
      Array2d<uint64_t, NumColors, NumPieces> board,
      Color sideToMove,
      uint8_t castlingRights,
      int enPassantSquare,
      int halfmoveClock)
      : board_(board),
        sideToMove_(sideToMove),
        castlingRights_(castlingRights),
        enPassantSquare_(enPassantSquare),
        halfmoveClock_(halfmoveClock) {}
  Color getPieceColor(uint64_t square);
};

}  // namespace chess