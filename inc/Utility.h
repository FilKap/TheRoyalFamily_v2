#pragma once

#include "Board.h"


namespace TheRoyalFamily_v2
{

void PrintEmpty(void);
void PrintPieces(void);
void ConsoleInit(void);
void NewGame(void);
bool GameProcess(void);
void CmdClear(void);

// OS utility
void SetCursorPosition(int x, int y);
void SetBackground(void);
void SetTextColor(EColor color);

}