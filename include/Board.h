#pragma once

#include <vector>
#include <memory>

#include "Pawn.h"
#include "Piece.h"


namespace TheRoyalFamily_v2
{

class TBoard
{
// Fields
private:

	EColor fTurn{ white };
	std::vector<std::shared_ptr<TPiece>> fPieces;


// Private members	
private:

	void CreatePieces(void);


// Private constructor
private:

	TBoard() { CreatePieces(); }
	

// Getters & setters
public:

	static TBoard& GetBoard(void);
	auto& GetPieces(void) const { return fPieces; }
	auto GetTurn(void) const   { return fTurn; }

// Interface
public:

	void Print(void);

};


}