/******************************************************************************
 * This file is a part of the TheRoyalFamily_v2 console chess game.           *
 ******************************************************************************/

/**
 * @file utility.h
 * @author Kaplunow
 * @date Nov 2021
 * @brief File containing declarations of utility functions.
 * @ver 2.0
 */

#pragma once

#include "board.h"


namespace TheRoyalFamily_v2
{
/**
 * @brief Console initialization.
 */
void consoleInit(void);
/**
 * @brief Starting new game by creating new set of pieces.
 */
void newGame(void);
/**
 * @brief Game processing loop.
 */
bool gameProcess(void);
/**
 * @brief Check if square tar_pos is on board.
 *
 * @param Square. 
 */
bool isOnBoard(const TPiece::PiecePos& tar_pos);
/**
 * @brief Check if on square tar_pos is an enemy.
 *
 * @param Square.
 */
bool isEnemy(const TPiece::PiecePos& tar_pos);
/**
* @brief Check if on square is the same color piece.
* 
* @param Square.
*/
bool isSameOnSquare(const TPiece::PiecePos& tar_pos);

}
