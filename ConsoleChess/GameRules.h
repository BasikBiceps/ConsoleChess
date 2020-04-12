#pragma once
#include "Step.h"
#include "GameBoard.h"
#include "Game.h"

class GameRules
{
public:
	static bool isCheck(GameBoard& gameboard, const FigureColor& figureColor);
	static bool isCheckmate(GameBoard& gameboard, const FigureColor& figureColor);
	static bool isStalemate(GameBoard& gameboard, const FigureColor& figureColor);
	static bool isCastlingPossible(GameBoard& gameboard, Step& step);

private:
	static bool isCorrectStep(GameBoard& gameboard, const FigureColor& figureColor);
};

