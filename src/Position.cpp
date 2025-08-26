#include "../include/Position.hpp"

namespace chess {

Color Position::getPieceColorAt(uint64_t squareToCheck) {
  for (const auto& piece : board_[static_cast<size_t>(Color::WHITE)]) {
    if (piece & squareToCheck) {
      return Color::WHITE;
    }
  }
  for (const auto& piece : board_[static_cast<size_t>(Color::BLACK)]) {
    if (piece & squareToCheck) {
      return Color::BLACK;
    }
  }
  return Color::NO_COLOR;
}
uint64_t Position::getAllWhitePieces() {
  uint64_t allWhitePieces = 0;
  for (const auto& pieces : board_[static_cast<size_t>(Color::WHITE)]) {
    allWhitePieces |= pieces;
  }
  return allWhitePieces;
}
uint64_t Position::getAllBlackPieces() {
  uint64_t allBlackPieces = 0;
  for (const auto& pieces : board_[static_cast<size_t>(Color::BLACK)]) {
    allBlackPieces |= pieces;
  }
  return allBlackPieces;
}
uint64_t Position::getOccupancy() {
  return getAllWhitePieces() | getAllBlackPieces();
}

};  // namespace chess