/******************************************************************************
 * This file is a part of the TheRoyalFamily_v2 console chess game.           *
 ******************************************************************************/

/**
 * @file piece.h
 * @author Kaplunow
 * @date Nov 2021
 * @brief File containing declarations and definitions of abstract basic class for all pieces that would derived from.
 * @ver 2.0
 */

#pragma once

#include <tuple>
#include <iostream>
#include <memory>

namespace TheRoyalFamily_v2
{

/**
* @brief Enumerate type of color for the pieces, and player's turn.
*/
enum EColor { white, black };

/**
* @brief Abstract bacis class for future pieces.
*/
class TPiece {


// Helper
public:

	using PiecePos = std::tuple<char, int>;			/* Square on board, for example 'A1'*/


// Fields
private:

	EColor	        fColor;			/* Color of piece*/
	PiecePos		fPos;			/* Square where the piece is*/
	char		    fCode;			/* Code for displaying letter in console */


// Special functions
public:

	// Copy asigment constructor
	TPiece(char file, int rank, EColor color, char code) :
		fColor{ color },
		fPos{ std::make_tuple(file, rank) },
		fCode{ code }
	{ }

	// Copy constructor
	TPiece(const TPiece& piece) = default;

	// Copy constructor operator 
	TPiece& operator= (const TPiece& piece) = default;

	// Destructor
	virtual ~TPiece() = default;


// Getters & Setters
public:

	virtual EColor getColor(void) const { return fColor; }
	virtual PiecePos getPos(void) const { return fPos; }
	virtual void setPos(const TPiece::PiecePos& tar_pos) { fPos = tar_pos; }


// Interface
public:

	/**
	* @brief Check if piece can move to tar_pos.
	* 
	* @param Target squre.
	*/
	virtual bool canMove(const PiecePos& tar_pos) = 0;


// Friend functions
public:
	friend std::ostream& operator<< (std::ostream& o, const TPiece& p);
};


}
