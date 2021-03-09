#pragma once

#include "Piece.h"

namespace TheRoyalFamily_v2
{
	void PrintEmpty(void);
	std::ostream& operator<< (std::ostream& o, const TPiece& p);
}