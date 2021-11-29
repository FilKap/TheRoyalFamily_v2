#pragma once

#include "Board.h"


namespace TheRoyalFamily_v2
{

void printEmpty(void);
void printPieces(void);
void consoleInit(void);
void newGame(void);
bool gameProcess(void);
void cmdClear(void);
bool isOnBoard(const TPiece::PiecePos& tar_pos);
bool isEnemy(const TPiece::PiecePos& tar_pos);

// OS utility
void setCursorPos(int x, int y);
void setBackground(void);
void setTextColor(EColor color);

}