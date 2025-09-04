#include "../include/magic_bitboards.hpp"

namespace chess
{

uint64_t rookMasks[64];
uint64_t bishopMasks[64];

void generateRookMasks() {
  for (int i = 0; i <= 63; i++) {
    int rank = i / 8;
    int file = i % 8;
    uint64_t mask = 0ULL;

    // Rank
    for (int f = file + 1; f <= 7; f++) {
      mask |= (1ULL << (rank * 8 + f));
    }
    for (int f = file - 1; f >= 0; f--) {
      mask |= (1ULL << (rank * 8 + f));
    }
    
    // File
    for (int r = rank + 1; r <= 7; r++) {
      mask |= (1ULL << (r * 8 + file));
    }
    for (int r = rank - 1; r >= 0; r--) {
      mask |= (1ULL << (r * 8 + file));
    }
    
    rookMasks[i] = mask;
  }
}

void generateBishopMasks() {
  for (int i = 0; i <= 63; i++) {
    int rank = i / 8;
    int file = i % 8;
    uint64_t mask = 0ULL;

    int r, f;
    // North-East diagonal
    r = rank + 1; f = file + 1;
    while (r <= 7 && f <= 7) {
      mask |= (1ULL << (r * 8 + f));
      r++; f++;
    }

    // South-East diagonal
    r = rank - 1; f = file + 1;
    while (r >= 0 && f <= 7) {
      mask |= (1ULL << (r * 8 + f));
      r--; f++;
    }

    // South-West diagonal
    r = rank - 1; f = file - 1;
    while (r >= 0 && f >= 0) {
      mask |= (1ULL << (r * 8 + f));
      r--; f--;
    }

    // North-West diagonal
    r = rank + 1; f = file - 1;
    while (r <= 7 && f >= 0) {
      mask |= (1ULL << (r * 8 + f));
      r++; f--;
    }
    
    bishopMasks[i] = mask;
  }
}
} //namespace chess