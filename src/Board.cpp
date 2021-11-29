/******************************************************************************
 * This file is a part of the TheRoyalFamily_v2 console chess game.           *
 ******************************************************************************/

/**
 * @file board.cpp
 * @author Kaplunow
 * @date Nov 2021
 * @brief File containing definition of board class.
 * @ver 2.0
 */

#include "board.h"

using std::make_shared;



namespace TheRoyalFamily_v2
{

Board& Board::getBoard() {
	static Board board;
	return board;
}

void Board::createNewGamePieces() {
	fPieces.push_back(make_shared<Pawn>('A', 7, black));
	fPieces.push_back(make_shared<Pawn>('A', 2, white));
	fPieces.push_back(make_shared<Pawn>('A', 6, black));
}

bool Board::tryMove(const TPiece::PiecePos& cur_pos, const TPiece::PiecePos& tar_pos) {
	for (const auto& piece : fPieces) {
		if (piece->getColor() == fTurn && piece->getPos() == cur_pos) {
			if (piece->canMove(tar_pos) && !isSameOnSquare(tar_pos)) {
				tryCapture(tar_pos);
				piece->setPos(tar_pos);
				return true;
			}
		}
	}
	return false;
}

void Board::tryCapture(const TPiece::PiecePos& tar_pos) {
}

void Board::toggleTurn() {
	if (fTurn == white)
		fTurn = black;
	else
		fTurn = white;
}
}
