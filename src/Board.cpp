#include "Board.h"
#include "Utility.h"
#include "WinUtility.h"

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
	PrintPieces();
	SetCursorPos(0, 10);
}


void TBoard::CreatePieces()
{
	fPieces.push_back(make_shared<TPawn>('A', 7, black));
	fPieces.push_back(make_shared<TPawn>('A', 2, white));
}



}