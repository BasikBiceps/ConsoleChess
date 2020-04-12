#pragma once
#include <memory>

#include "Figure.h"
#include "FigurePosition.h"
#include "GameBoard.h"

class Step
{
public:
	Step(std::shared_ptr<Figure> moveFigure,
		const FigurePosition& startPosition,
		const FigurePosition& endPosition);

	const FigurePosition& getStartPosition() const;
	const FigurePosition& getEndPosition() const;
	std::shared_ptr<Figure> getMoveFigure() const;

	virtual void undo(GameBoard& gameBoard) = 0;

protected:
	std::shared_ptr<Figure> m_moveFigure;
	FigurePosition m_startPosition;
	FigurePosition m_endPosition;
};

