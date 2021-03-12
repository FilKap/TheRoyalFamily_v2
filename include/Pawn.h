#pragma once

#include "Piece.h"

namespace TheRoyalFamily_v2
{


class TPawn :
	public TPiece
{

public:
	
	TPawn(char file, int rank, EColor color, char code = 'p') : TPiece(file, rank, color, code) {}
	~TPawn() = default;

public:

	bool Move(PiecePos& curr_pos, PiecePos& target_pos);

};





inline bool TPawn::Move(PiecePos& curr_pos, PiecePos& target_pos)
{
	return true;
}



}