#include "Board.h"
#include "Utility.h"

using std::make_shared;



namespace TheRoyalFamily_v2
{

TBoard& TBoard::GetBoard()
{
	static TBoard board;
	return board;
}


void TBoard::Print()
{
	PrintEmpty();
}


void TBoard::InitPieces()
{
	fPieces.push_back(make_shared<TPawn>('A', 7, TPiece::black));
	fPieces.push_back(make_shared<TPawn>('A', 2, TPiece::white));
}



}