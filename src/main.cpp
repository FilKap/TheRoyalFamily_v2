#include "Utility.h"

using namespace TheRoyalFamily_v2;

auto board = Board::GetBoard();


int main()
{
	ProgramConfig();
	NewGame();

	bool game_process{ };

	do
	{
		game_process = GameProcess();
	} while (game_process);
	
	


	return 0;
}