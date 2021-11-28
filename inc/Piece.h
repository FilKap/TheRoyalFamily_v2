#pragma once

#include <tuple>
#include <iostream>
#include <memory>


namespace TheRoyalFamily_v2
{


enum EColor { white, black };


class TPiece {

public:

	using PiecePos = std::tuple<char, int>;

private:

	EColor	        fColor;
	PiecePos		fPos;
	char		    fCode;

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

public:

	virtual bool Move(PiecePos& curr_pos, PiecePos& target_pos) = 0;

	friend std::ostream& operator<< (std::ostream& o, const TPiece& p);
};




}