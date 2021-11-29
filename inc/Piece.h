#pragma once

#include <tuple>
#include <iostream>
#include <memory>


namespace TheRoyalFamily_v2
{


enum EColor { white, black };


class TPiece {


// Helper
public:

	using PiecePos = std::tuple<char, int>;


// Fields
private:

	EColor	        fColor;
	PiecePos		fPos;
	char		    fCode;


// Special functions
public:

	// Copy asigment constructor
	TPiece(char file, int rank, EColor color, char code) :
		fPos{ std::make_tuple(file, rank) },
		fColor{ color },
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

	virtual bool canMove(const PiecePos& tar_pos) = 0;

	friend std::ostream& operator<< (std::ostream& o, const TPiece& p);
};


}
