#pragma once
#include <memory>

#include "Figure.h"
#include "FigurePosition.h"
#include "GameBoard.h"

class Step
{
public:
	Step(std::shared_ptr<Figure> moveFigure,
		std::shared_ptr<Figure> beatFigure,
		const FigurePosition& startPosition,
		const FigurePosition& endPosition);

	void undo(GameBoard& gameBoard);

private:
	std::shared_ptr<Figure> m_moveFigure;
	std::shared_ptr<Figure> m_beatFigure;
	FigurePosition m_startPosition;
	FigurePosition m_endPosition;
};

