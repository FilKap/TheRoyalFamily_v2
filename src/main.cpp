#include "Utility.h"

using namespace TheRoyalFamily_v2;

auto board = Board::getBoard();		/*Global object*/


int main() {
	consoleInit();				/*Console config*/

	newGame();

	while (gameProcess());

	return 0;
}