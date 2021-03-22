#include "Utility.h"

#include <array>
#include <cassert>

using std::array, std::ostream, std::cout, std::endl, std::copy, std::cin;

extern TheRoyalFamily_v2::Board board;



namespace TheRoyalFamily_v2
{

void PrintEmpty()
{
	const array<int, 8> kNumbers	{ 8, 7, 6, 5, 4, 3, 2, 1 };
	const array<char, 8> kLetters	{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

	SetCursorPos(0, 0);
	SetTextColor(black);

	copy(kNumbers.begin(), kNumbers.end(), std::ostream_iterator<int>(cout, " _ _ _ _ _ _ _ _\n"));
	cout << "  ";
	copy(kLetters.begin(), kLetters.end(), std::ostream_iterator<char>(cout, " "));
}


std::ostream& operator<< (std::ostream& o, const TPiece& p)
{
	auto [file, rank] = p.fPos;
	SetCursorPos( ((file - 'A' + 1) * 2), 8 - rank );
	SetTextColor(p.fColor);
	cout << p.fCode << endl;
	return o;
}


void PrintPieces()
{
	auto pieces = board.GetPieces();

	for (const auto& piece : pieces)
	{
		assert(piece.get() != nullptr);

		cout << *piece;
	}
}


void ProgramConfig()
{	
	SetBackground();
}


void NewGame()
{
	board.CreateNewGamePieces();
}



}