#include "../include/Board.hpp"

namespace chess {

Color Position::getPieceColor(uint64_t squareToCheck) {
  for (const auto& piece : board_[static_cast<size_t>(static_cast<size_t>(Color::WHITE))]) {
    if (piece & squareToCheck) {
      return Color::WHITE;
    }
  }
  for (const auto& piece : board_[static_cast<size_t>(static_cast<size_t>(Color::BLACK))]) {
    if (piece & squareToCheck) {
      return Color::BLACK;
    }
  }
  return Color::NO_COLOR;
}

};  // namespace chess