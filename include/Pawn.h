#pragma once

#include "Piece.h"

namespace TheRoyalFamily_v2
{


class Pawn :
	public TPiece
{

public:
	
	Pawn(char file, int rank, EColor color, char code = 'p') : TPiece(file, rank, color, code) {}
	~Pawn() = default;

public:

	bool Move(PiecePos& cur_pos, PiecePos& tar_pos);

};





inline bool Pawn::Move(PiecePos& curr_pos, PiecePos& target_pos)
{
	return true;
}



}