#pragma once

#include "Piece.h"
#include "Utility.h"


namespace TheRoyalFamily_v2
{


class Pawn :
	public TPiece {


public:

	// Constructor
	Pawn(char file, int rank, EColor color, char code = 'p') : TPiece(file, rank, color, code) {}


// Public methods
public:
	bool canMove(const PiecePos& tar_pos);
};
}


using namespace TheRoyalFamily_v2;

extern bool isOnBoard(const TPiece::PiecePos& tar_pos);
extern bool isEnemy(const TPiece::PiecePos& tar_pos);


inline bool Pawn::canMove(const PiecePos& tar_pos) {
	
	if (isOnBoard(tar_pos)) {
		
		if (getColor() == white) {
			auto [cur_file, cur_rank] = getPos();
			auto [tar_file, tar_rank] = tar_pos;
			
			if (tar_rank == cur_rank + 1 && tar_file == cur_file && true)			/*Regular move*/
				return true;
		}

		else {				/* if black*/

		}

	}
	


	return false;
}

