/******************************************************************************
 * This file is a part of the TheRoyalFamily_v2 console chess game.           *
 ******************************************************************************/

/**
 * @file pawn.h
 * @author Kaplunow
 * @date Nov 2021
 * @brief File containing declarations and definitions of pawn class.
 * @ver 2.0
 */

#pragma once

#include "piece.h"
#include "utility.h"


namespace TheRoyalFamily_v2
{

class Pawn :
	public TPiece {

public:

	// Constructor
	Pawn(char file, int rank, EColor color, char code = 'p') : TPiece(file, rank, color, code) {}


// Public methods
public:
	/**
	* @brief Check if piece can move to tar_pos.
	*
	* @param Target squre.
	*/
	bool canMove(const PiecePos& tar_pos);
};
}


using namespace TheRoyalFamily_v2;

/******************************************************************************
* Utility function introduction
******************************************************************************/
extern bool isOnBoard(const TPiece::PiecePos& tar_pos);
extern bool isEnemy(const TPiece::PiecePos& tar_pos);


inline bool Pawn::canMove(const TPiece::PiecePos& tar_pos) {
	
	if (isOnBoard(tar_pos)) {
		auto [cur_file, cur_rank] = getPos();
		auto [tar_file, tar_rank] = tar_pos;

		if (getColor() == white) {
			if (tar_rank == cur_rank + 1 && tar_file == cur_file && !isEnemy(tar_pos))			/*Regular move*/
				return true;
		}

		else {				/* if black*/
			if (tar_rank == cur_rank - 1 && tar_file == cur_file && !isEnemy(tar_pos))			/*Regular move*/
				return true;
		}

	}
	return false;
}
