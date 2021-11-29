#pragma once

#include "Pawn.h"

#include <vector>
#include <memory>



namespace TheRoyalFamily_v2
{



class Board {


// Fields
private:

	EColor fTurn{ white };
	std::vector<std::shared_ptr<TPiece>> fPieces;


// Private members	
private:

	bool isSameOnSquare(const TPiece::PiecePos& tar_pos) const;
	void tryCapture(const TPiece::PiecePos& tar_pos);


// Special functions
private:

	Board() {}							/*Private constructor*/


// Getters & setters
public:

	static Board& getBoard(void);
	auto& getPieces(void) const { return fPieces; }
	auto  getTurn(void) const { return fTurn; }


// Interface
public:

	void print(void);
	void createNewGamePieces(void);
	bool tryMove(const TPiece::PiecePos& cur_pos, const TPiece::PiecePos& tar_pos);
	void toggleTurn(void);

};


}