#pragma once
#include <memory>

#include "Figure.h"
#include "FigurePosition.h"
#include "GameBoard.h"
#include "Step.h"

class BeatStep : public Step
{
public:
	BeatStep(std::shared_ptr<Figure> moveFigure,
		std::shared_ptr<Figure> beatFigure,
		const FigurePosition& startPosition,
		const FigurePosition& endPosition);

	void undo(GameBoard& gameBoard) override;

private:
	std::shared_ptr<Figure> m_beatFigure;
};
