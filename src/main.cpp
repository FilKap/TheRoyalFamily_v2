#include <iostream>

#include "Board.h"
#include "Utility.h"

using namespace TheRoyalFamily_v2;

int main()
{
	auto board = TBoard::GetBoard();
	
	board.Print();
	


	return 0;
}