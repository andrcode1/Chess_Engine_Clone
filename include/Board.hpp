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

  static constexpr size_t NumTypes = static_cast<size_t>(PieceType::NO_PIECE_TYPE);
  static constexpr size_t NumColors = static_cast<size_t>(Color::NO_COLOR);

  Array2d<uint64_t, NumColors, NumTypes> bitboards_;
  Color sideToMove_;
  uint8_t castlingRights_;
  int enPassantSquare_;
  int halfmoveClock_;  // for 50-move draw rule

 public:
  Position(
      Array2d<uint64_t, NumColors, NumTypes> bitboards,
      Color sideToMove,
      uint8_t castlingRights,
      int enPassantSquare,
      int halfmoveClock)
      : bitboards_(bitboards),
        sideToMove_(sideToMove),
        castlingRights_(castlingRights),
        enPassantSquare_(enPassantSquare),
        halfmoveClock_(halfmoveClock) {}
};

}  // namespace chess