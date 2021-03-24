#include "WinUtility.h"

namespace TheRoyalFamily_v2
{


void SetCursorPos(int x, int y)
{
	COORD c;
	c.X = x, c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


void SetBackground(void)
{
	system("Color 30");
}


void SetTextColor(EColor color)
{
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




}