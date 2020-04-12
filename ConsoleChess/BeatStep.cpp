#include "BeatStep.h"

BeatStep::BeatStep(std::shared_ptr<Figure> moveFigure,
	std::shared_ptr<Figure> beatFigure,
	const FigurePosition& startPosition,
	const FigurePosition& endPosition) :
	Step(moveFigure, startPosition, endPosition),
	m_beatFigure(beatFigure)
{
}

void BeatStep::undo(GameBoard& gameBoard)
{
	gameBoard.moveFigure(m_endPosition, m_startPosition);
	gameBoard.addFigureOnBoard(*m_beatFigure);
}
