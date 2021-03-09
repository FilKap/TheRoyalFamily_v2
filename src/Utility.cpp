#include "Utility.h"
#include "WinUtility.h"

#include <array>

using std::array, std::ostream, std::cout, std::endl;


namespace TheRoyalFamily_v2
{
	

void PrintEmpty()
{
	const array<int, 8> kNumbers	{ 8, 7, 6, 5, 4, 3, 2, 1 };
	const array<char, 8> kLetters	{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

	SetCursorPos(0, 0);
	std::copy(kNumbers.begin(), kNumbers.end(), std::ostream_iterator<int>(cout, " _ _ _ _ _ _ _ _\n"));
	cout << "  ";
	std::copy(kLetters.begin(), kLetters.end(), std::ostream_iterator<char>(cout, " "));
}


ostream& operator<< (ostream& o, const TPiece& p)
{
	return o;
}



}