#include "Board.h"

using std::make_shared;



namespace TheRoyalFamily_v2
{

void printEmpty(void);
void printPieces(void);
void setCursorPos(int x, int y);


Board& Board::getBoard() {
	static Board board;
	return board;
}


void Board::print() {
	printEmpty();
	printPieces();
	setCursorPos(1, 10);
}

void Board::createNewGamePieces() {
	fPieces.push_back(make_shared<Pawn>('A', 7, black));
	fPieces.push_back(make_shared<Pawn>('A', 2, white));
}


bool Board::tryMove(const TPiece::PiecePos& cur_pos, const TPiece::PiecePos& tar_pos) {
	for (const auto& piece : fPieces) {
		if (piece->getColor() == fTurn && piece->getPos() == cur_pos) {
			if (piece->canMove(tar_pos) && !isSameOnSquare(tar_pos)) {
				tryCapture(tar_pos);
				piece->setPos(tar_pos);
				return true;
			}
		}
	}
	return false;
}

void Board::tryCapture(const TPiece::PiecePos& tar_pos) {
}

bool Board::isSameOnSquare(const TPiece::PiecePos& tar_pos) const {
	return false;
}
void Board::toggleTurn() {
	if (fTurn == white)
		fTurn = black;
	else
		fTurn = white;
}



}