#pragma once

#include <tuple>
#include <iostream>


namespace TheRoyalFamily_v2
{

enum EColor { white, black };

class TPiece
{

public:

	using PiecePos = std::tuple<char, int>;

private:

	const EColor	fColor;
	PiecePos		fPos; 
	const char		fCode{};

public:

	TPiece(char file, int rank, EColor color, char code) : fPos{ std::make_tuple(file, rank) }, fColor{ color }, fCode{ code } {}
	virtual ~TPiece() = default;

public:

	virtual bool Move( PiecePos& curr_pos, PiecePos& target_pos ) = 0;

	friend std::ostream& operator<< (std::ostream& o, const TPiece& p);
};




}