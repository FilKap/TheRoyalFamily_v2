#include "Utility.h"

#include <array>
#include <cassert>
#include <string>

using std::array, std::ostream, std::cout, std::endl, std::copy, std::cin, std::string;

extern TheRoyalFamily_v2::Board board;



namespace TheRoyalFamily_v2
{

void PrintEmpty() {
	const array<int, 8> kNumbers{ 8, 7, 6, 5, 4, 3, 2, 1 };
	const array<char, 8> kLetters{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

	SetCursorPosition(0, 0);
	SetTextColor(black);

	copy(kNumbers.begin(), kNumbers.end(), std::ostream_iterator<int>(cout, " _ _ _ _ _ _ _ _\n"));
	cout << "  ";
	copy(kLetters.begin(), kLetters.end(), std::ostream_iterator<char>(cout, " "));
}


std::ostream& operator<< (std::ostream& o, const TPiece& p) {
	auto [file, rank] = p.fPos;
	SetCursorPosition(((file - 'A' + 1) * 2), 8 - rank);
	SetTextColor(p.fColor);
	cout << p.fCode << endl;
	return o;
}


void PrintPieces() {
	auto& pieces = board.GetPieces();

	for (const auto& piece : pieces) {
		assert(piece.get() != nullptr);
		cout << *piece;
	}
}


void ConsoleInit() {
	SetBackground();
}


void NewGame() {
	board.CreateNewGamePieces();
}


bool GameProcess() {
	EColor turn = board.GetTurn();
	string sCur_pos, sTar_pos;
	TPiece::PiecePos cur_pos, tar_pos;

	while (1)
	{
		// Preparing console
		board.Print();
		CmdClear();
		SetTextColor(turn);

		// Entering needed data to move piece
		cout << ">> ";
		cin >> sCur_pos;
		SetCursorPosition(7, 10);
		cout << "-> ";
		cin >> sTar_pos;

		// Data conversion
		cur_pos = std::make_tuple(sCur_pos[0], sCur_pos[1] - '0');
		tar_pos = std::make_tuple(sTar_pos[0], sCur_pos[1] - '0');

		// Try move
		if (board.TryMove(cur_pos, tar_pos))
			board.ToggleTurn();
	}

	return true;
}


void CmdClear() {
	for (auto i = 0; i < 10; i++)
	{
		for (auto i = 0; i < 40; i++)
			cout << " ";

		cout << endl;
	}
	SetCursorPosition(1, 10);
}


#ifdef __linux__


#elif _WIN32

#include <Windows.h>

void SetCursorPosition(int x, int y) {
	COORD c;
	c.X = x, c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


void SetBackground(void) {
	system("Color 30");
}


void SetTextColor(EColor color) {
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