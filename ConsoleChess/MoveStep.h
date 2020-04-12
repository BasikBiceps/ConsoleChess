#pragma once
#include <memory>

#include "Figure.h"
#include "FigurePosition.h"
#include "GameBoard.h"
#include "Step.h"

class MoveStep : public Step
{
public:
	MoveStep(std::shared_ptr<Figure> moveFigure,
		const FigurePosition& startPosition,
		const FigurePosition& endPosition);

	void undo(GameBoard& gameBoard) override;
};
