#include "Utility.h"

using namespace TheRoyalFamily_v2;

auto board = Board::GetBoard();		/*Global object*/


int main() {
	ConsoleInit();				/*Console config*/

	NewGame();

	while (GameProcess());

	return 0;
}