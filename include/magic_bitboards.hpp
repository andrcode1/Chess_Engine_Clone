#include <cstdint>

namespace chess
{
	void generateRookMasks();
	void generateBishopMasks();
	
	extern uint64_t rookMasks[64];
	extern uint64_t bishopMasks[64];
} //namespace chess