#pragma once
#include "Step.h"
#include "GameBoard.h"

class GameRules
{
public:
	static bool checkPositionMove(GameBoard& gameboard, Step& step);
	static bool checkPositionBeat(GameBoard& gameboard, Step& step);
	static bool isCheck(GameBoard& gameboard, FigureColor& figureColor);
	static bool isCheckmate(GameBoard& gameboard, FigureColor& figureColor);
	static bool isStalemate(GameBoard& gameboard, FigureColor& figureColor);
};

