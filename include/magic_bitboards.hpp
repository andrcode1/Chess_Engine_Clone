#include <cstdint>

namespace chess
{
	void generateRookMasks(uint64_t square);
	void generateBishopMasks(uint64_t square);
	
	uint64_t rookMasks[64];
	uint64_t bishopMasks[64];
} //namespace chess