#include "Board.h"

using std::make_shared;



namespace TheRoyalFamily_v2
{

void PrintEmpty(void);
void PrintPieces(void);
void SetCursorPos(int x, int y);


Board& Board::GetBoard()
{
	static Board board;
	return board;
}


void Board::Print()
{
	PrintEmpty();
	PrintPieces();
	SetCursorPos(1, 10);
}

void Board::CreateNewGamePieces()
{
	fPieces.push_back(make_shared<Pawn>('A', 7, black));
	fPieces.push_back(make_shared<Pawn>('A', 2, white));
}


bool Board::TryMove(const TPiece::PiecePos& cur_pos, const TPiece::PiecePos& tar_pos)
{
	return false;
}


void Board::ToggleTurn()
{
	if (fTurn == white)
		fTurn = black;
	else
		fTurn = white;
}



}