#include "MoveStep.h"

MoveStep::MoveStep(std::shared_ptr<Figure> moveFigure,
	const FigurePosition& startPosition,
	const FigurePosition& endPosition) : 
	Step(moveFigure, startPosition, endPosition)
{
}

void MoveStep::undo(GameBoard& gameBoard)
{
	gameBoard.moveFigure(m_endPosition, m_startPosition);
}
