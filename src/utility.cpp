/******************************************************************************
 * This file is a part of the TheRoyalFamily_v2 console chess game.           *
 ******************************************************************************/

/**
 * @file utility.cpp
 * @author Kaplunow
 * @date Nov 2021
 * @brief File containing definitions of utility functions.
 * @ver 2.0
 */

#include "utility.h"

#include <array>
#include <cassert>
#include <string>
#include <iterator>

using std::array, std::ostream, std::cout, std::endl, std::copy, std::cin, std::string;


/******************************************************************************
* Global variables										 
******************************************************************************/
extern TheRoyalFamily_v2::Board board;


namespace TheRoyalFamily_v2
{
/******************************************************************************
* Private prototpyes 
******************************************************************************/
void printEmpty(void);
void printPieces(void);
void print(void);
void cmdClear(void);
void setCursorPos(int x, int y);
void setBackground(void);
void setTextColor(EColor color);

/**
 * @brief Print empty board.
 */
void printEmpty() {
	const array<int, 8> kNumbers{ 8, 7, 6, 5, 4, 3, 2, 1 };
	const array<char, 8> kLetters{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

	setCursorPos(0, 0);
	setTextColor(black);

	copy(kNumbers.begin(), kNumbers.end(), std::ostream_iterator<int>(cout, " _ _ _ _ _ _ _ _\n"));
	cout << "  ";
	copy(kLetters.begin(), kLetters.end(), std::ostream_iterator<char>(cout, " "));
}

std::ostream& operator<< (std::ostream& o, const TPiece& p) {
	auto [file, rank] = p.fPos;
	setCursorPos(((file - 'A' + 1) * 2), 8 - rank);
	setTextColor(p.fColor);
	cout << p.fCode << endl;
	return o;
}
/**
 * @brief Print pieces(letters) on board.
 */
void printPieces() {
	auto& pieces = board.getPieces();

	for (const auto& piece : pieces) {
		assert(piece.get() != nullptr);
		cout << *piece;
	}
}
/*
* @brief Print everrything.
*/
void print() {
	printEmpty();
	printPieces();
	setCursorPos(1, 10);
}

void consoleInit() {
	setBackground();
}

void newGame() {
	board.createNewGamePieces();
}

bool gameProcess() {
	string sCur_pos, sTar_pos;
	TPiece::PiecePos cur_pos, tar_pos;

	while (1)
	{
		// Preparing console
		EColor turn = board.getTurn();
		print();
		cmdClear();
		setTextColor(turn);

		// Entering needed data to move piece
		cout << ">> ";
		cin >> sCur_pos;
		setCursorPos(7, 10);
		cout << "-> ";
		cin >> sTar_pos;

		// Data conversion
		cur_pos = std::make_tuple(sCur_pos[0], sCur_pos[1] - '0');
		tar_pos = std::make_tuple(sTar_pos[0], sTar_pos[1] - '0');

		// Try move
		if (board.tryMove(cur_pos, tar_pos)) 
			board.toggleTurn();
	}

	return true;
}
/**
 * @brief Clearing the command line.
 */
void cmdClear() {
	for (auto i = 0; i < 10; i++)
	{
		for (auto i = 0; i < 40; i++)
			cout << " ";

		cout << endl;
	}
	setCursorPos(1, 10);
}

bool isOnBoard(const TPiece::PiecePos& tar_pos) {
	auto [file, rank] = tar_pos;

	if ( (file >= 'A' && file <= 'H') && (rank >= 1 && rank <= 8) )
		return true;
	else 
		return false;
}

bool isEnemy(const TPiece::PiecePos& tar_pos) {
	for (const auto& piece : board.getPieces()) {
		if (piece->getPos() == tar_pos && !(piece->getColor() == board.getTurn()))
			return true;
	}
	return false;
}

bool isSameOnSquare(const TPiece::PiecePos& tar_pos) {
	for (const auto& piece : board.getPieces()) {
		if (piece->getPos() == tar_pos && piece->getColor() == board.getTurn())
			return true;
	}
	return false;
}


/*************************************
*  	OS dependence functions		     *
**************************************/
#ifdef __linux__

/**
 * @brief Set cursor position in terminal.
 *
 * @param Column.
 * @param Row.
 */
void setCursorPos(int x, int y) {
	cout << "\033[" << y+1 << ";" << x+1 << 'f';
}
/**
 * @brief Set the lightblue backgorund color.
 */
void setBackground(void) {
	cout << "\033[37;46m";
	cout << "\033[2J";
}
/**
 * @brief Set the color of the text.
 *
 * @param Color (blue/white).
 */
void setTextColor(EColor color) {
	switch (color)
	{
	case white:
		cout << "\033[37;46m";
		break;
	case black:
		cout << "\033[30;46m";
		break;
	}
}

#elif _WIN32
#include <Windows.h>

/**
 * @brief Set cursor position in terminal.
 *
 * @param Column.
 * @param Row.
 */
void setCursorPos(int x, int y) {
	COORD c;
	c.X = x, c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
/**
 * @brief Set the lightblue backgorund color.
 */
void setBackground(void) {
	system("Color 30");
}
/**
 * @brief Set the color of the text.
 *
 * @param Color (blue/white).
 */
void setTextColor(EColor color) {
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
