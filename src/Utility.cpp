#include "Utility.h"

#include <array>
#include <cassert>
#include <string>

using std::array, std::ostream, std::cout, std::endl, std::copy, std::cin, std::string;

extern TheRoyalFamily_v2::Board board;



namespace TheRoyalFamily_v2
{

void printEmpty() {
	const array<int, 8> kNumbers{ 8, 7, 6, 5, 4, 3, 2, 1 };
	const array<char, 8> kLetters{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

	setCursorPos(0, 0);
	setTextColor(black);

	copy(kNumbers.begin(), kNumbers.end(), std::ostream_iterator<int>(cout, " _ _ _ _ _ _ _ _\n"));
	cout << "  ";
	copy(kLetters.begin(), kLetters.end(), std::ostream_iterator<char>(cout, " "));
}


std::ostream& operator<< (std::ostream& o, const TPiece& p) {
	auto [file, rank] = p.fPos;
	setCursorPos(((file - 'A' + 1) * 2), 8 - rank);
	setTextColor(p.fColor);
	cout << p.fCode << endl;
	return o;
}


void printPieces() {
	auto& pieces = board.getPieces();

	for (const auto& piece : pieces) {
		assert(piece.get() != nullptr);
		cout << *piece;
	}
}


void consoleInit() {
	setBackground();
}


void newGame() {
	board.createNewGamePieces();
}


bool gameProcess() {
	string sCur_pos, sTar_pos;
	TPiece::PiecePos cur_pos, tar_pos;

	while (1)
	{
		// Preparing console
		EColor turn = board.getTurn();
		board.print();
		cmdClear();
		setTextColor(turn);

		// Entering needed data to move piece
		cout << ">> ";
		cin >> sCur_pos;
		setCursorPos(7, 10);
		cout << "-> ";
		cin >> sTar_pos;

		// Data conversion
		cur_pos = std::make_tuple(sCur_pos[0], sCur_pos[1] - '0');
		tar_pos = std::make_tuple(sTar_pos[0], sTar_pos[1] - '0');

		// Try move
		if (board.tryMove(cur_pos, tar_pos)) 
			board.toggleTurn();
	}

	return true;
}


void cmdClear() {
	for (auto i = 0; i < 10; i++)
	{
		for (auto i = 0; i < 40; i++)
			cout << " ";

		cout << endl;
	}
	setCursorPos(1, 10);
}


bool isOnBoard(const TPiece::PiecePos& tar_pos) {
	auto [file, rank] = tar_pos;

	if ( (file >= 'A' && file <= 'H') && (rank >= 1 && rank <= 8) )
		return true;
	else 
		return false;
}


bool isEnemy(const TPiece::PiecePos& tar_pos) {
	for (const auto& piece : board.getPieces()) {
		if (piece->getPos() == tar_pos && !piece->getColor() == board.getTurn())
			return true;
	}
	return false;
}


#ifdef __linux__


#elif _WIN32

#include <Windows.h>

void setCursorPos(int x, int y) {
	COORD c;
	c.X = x, c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


void setBackground(void) {
	system("Color 30");
}


void setTextColor(EColor color) {
	switch (color)
	{
	case white:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 63);
		break;
	case black:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 48);
		break;
	}
}

#endif

}