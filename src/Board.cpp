#include "../include/Board.hpp"

namespace chess {

bool Position::isFriendlyPiece(uint64_t squareToCheck) {
  for (const auto& piece : board_[static_cast<size_t>(sideToMove_)]) {
    if (piece & squareToCheck) {
      return true;
    }
  }
  return false;
}

bool Position::isEnemyPiece(uint64_t squareToCheck) {
  return !isFriendlyPiece(squareToCheck);
}

};  // namespace chess