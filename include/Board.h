#pragma once

#include <vector>
#include <memory>

#include "Pawn.h"
#include "Piece.h"


namespace TheRoyalFamily_v2
{

class TBoard
{

private:

	TPiece::Color turn{ TPiece::white };
	std::vector<std::shared_ptr<TPiece>> fPieces;


// Private members	
private:

	void InitPieces(void);


// Private constructor
private:

	TBoard() { InitPieces(); }
	


public:

	static TBoard& GetBoard(void);


// Interface
public:

	void Print(void);

};


}