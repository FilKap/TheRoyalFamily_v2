/******************************************************************************
 * This file is a part of the TheRoyalFamily_v2 console chess game.           *
 ******************************************************************************/

/**
 * @file board.h
 * @author Kaplunow
 * @date Nov 2021
 * @brief File containing declaration of board singleton class.
 * @ver 2.0
 */

#pragma once

#include "pawn.h"

#include <vector>
#include <memory>


namespace TheRoyalFamily_v2
{
/**
* @brief Singleton board class containing and managing information about pieces on board, and turn.
*/
class Board {


// Fields
private:

	EColor									fTurn{ white };
	std::vector<std::shared_ptr<TPiece>>    fPieces;


// Private members	
private:
	
	/**
	* @brief Try capture enemy piece on tar_pos square.
	* 
	* @param Target squre.
	*/
	void tryCapture(const TPiece::PiecePos& tar_pos);


// Special functions
private:

	// Private constructor
	Board() {}							


// Getters & setters
public:

	static Board& getBoard(void);
	auto& getPieces(void) const { return fPieces; }
	auto  getTurn(void) const { return fTurn; }


// Interface
public:
	/*
	* @brief Create pieces for new game.
	*/
	void createNewGamePieces(void);
	/*
	* @brief Try to move piece from cur_pos to tar_pos square.
	* 
	* @param Current squre.
	* @param Target square.
	* 
	* @return bool - has it moved?
	*/
	bool tryMove(const TPiece::PiecePos& cur_pos, const TPiece::PiecePos& tar_pos);
	/*
	* @brief Change turn.
	*/
	void toggleTurn(void);
};
}
