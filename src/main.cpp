/******************************************************************************
 * This file is a part of the TheRoyalFamily_v2 console chess game.           *
 ******************************************************************************/

/**
 * @file board.h
 * @author Kaplunow
 * @date Nov 2021
 * @brief Main of TheRoyalFamily_v2 console chess game.
 * @ver 2.0
 */

#include "utility.h"

using namespace TheRoyalFamily_v2;

auto board = Board::getBoard();		/*Global object*/


int main() {
	consoleInit();				    /*Console config*/

	newGame();

	while (gameProcess());

	return 0;
}