#pragma once

#include "Pawn.h"

#include <vector>
#include <memory>


namespace TheRoyalFamily_v2
{
	

class Board
{
// Fields
private:

	EColor fTurn{ white };
	std::vector<std::shared_ptr<TPiece>> fPieces;


// Private members	
private:

	


// Private constructor
private:

	Board() { }
	

// Getters & setters
public:

	static Board& GetBoard(void);
	auto& GetPieces(void) const { return fPieces; }
	auto GetTurn(void) const   { return fTurn; }

// Interface
public:

	void Print(void);
	void CreateNewGamePieces(void);

};


}