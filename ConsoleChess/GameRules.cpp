#include "GameRules.h"

bool GameRules::isCheck(GameBoard& gameboard, FigureColor& figureColor)
{
	auto kingPosition = gameboard.getKingPosition(figureColor);
	auto king = gameboard.findFigureByPosition(kingPosition);
	std::vector<FigurePosition>::iterator result;

	if (figureColor == FigureColor::White)
	{
		auto beatTraces = gameboard.getBlackFigureBeatTraces();

		result = std::find(beatTraces.begin(), beatTraces.end(), (*king).getPosition());

		return result != beatTraces.end();
	}
	else
	{
		auto beatTraces = gameboard.getWhiteFigureBeatTraces();

		result = std::find(beatTraces.begin(), beatTraces.end(), (*king).getPosition());

		return result != beatTraces.end();
	}
}

bool GameRules::isCheckmate(GameBoard& gameboard, FigureColor& figureColor)
{
	return isCheck(gameboard, figureColor) && !isCorrectStep(gameboard, figureColor);
}

bool GameRules::isStalemate(GameBoard& gameboard, FigureColor& figureColor)
{
	return !isCheck(gameboard, figureColor) && !isCorrectStep(gameboard, figureColor);
}

bool GameRules::isCorrectStep(GameBoard& gameboard, FigureColor& figureColor)
{
	for (auto& figure : gameboard.getFigures())
	{
		if (figure.getColor() == figureColor)
		{
			auto moveTrace = gameboard.getDependentOnOtherFiguresFigureMoveTrace(figure);
			auto beatTrace = gameboard.getDependentOnOtherFiguresFigureBeatTrace(figure);

			for (auto whereToPoint : *moveTrace)
			{
				GameBoard tempGB(gameboard.getFigures());

				tempGB.moveFigure(figure.getPosition(), whereToPoint);

				if (!isCheck(tempGB, figureColor))
				{
					return true;
				}
			}

			for (auto whereToPoint : *beatTrace)
			{
				GameBoard tempGB(gameboard.getFigures());

				tempGB.beatFigure(figure.getPosition(), whereToPoint);

				if (!isCheck(tempGB, figureColor))
				{
					return true;
				}
			}
		}
	}

	return false;
}
