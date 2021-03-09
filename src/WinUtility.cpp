#include "WinUtility.h"

namespace TheRoyalFamily_v2
{


void SetCursorPos(int x, int y)
{
	COORD c;
	c.X = x, c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}



}