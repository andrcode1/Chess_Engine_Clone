#include "../include/magic_bitboards.hpp"

namespace chess
{
  void generateRookMasks(uint64_t square) {
    for (int i = 0; i <= 63; i++) {
      int rank = i / 8;
      int file = i % 8;
      uint64_t mask = 0ULL;

      // Rank
      for (int f = file + 1; f < 7; f++) {
        mask |= (1ULL << (rank * 8 + f));
      }
      for (int f = file - 1; f > 0; f--) {
        mask |= (1ULL << (rank * 8 + f));
      }
      
      // File
      for (int r = rank + 1; r < 7; r++) {
        mask |= (1ULL << (r * 8 + file));
      }
      for (int r = rank - 1; r > 0; r--) {
        mask |= (1ULL << (r * 8 + file));
      }
      
      rookMasks[i] = mask;
    }
  }

	void generateBishopMasks(uint64_t square) {
    for (int i = 0; i <= 63; i++) {
      int rank = i / 8;
      int file = i % 8;
      uint64_t mask = 0ULL;

      // North-East diagonal
      for (int r = rank + 1, f = file + 1; r < 7 && f < 7; r++, f++) {
        mask |= (1ULL << (r * 8 + f));
      }
      
      // South-East diagonal
      for (int r = rank - 1, f = file + 1; r > 0 && f < 7; r--, f++) {
        mask |= (1ULL << (r * 8 + f));
      }
      
      // South-West diagonal
      for (int r = rank - 1, f = file - 1; r > 0 && f > 0; r--, f--) {
        mask |= (1ULL << (r * 8 + f));
      }
      
      // North-West diagonal
      for (int r = rank + 1, f = file - 1; r < 7 && f > 0; r++, f--) {
        mask |= (1ULL << (r * 8 + f));
      }
      
      bishopMasks[i] = mask;
    }
  }
} //namespace chess