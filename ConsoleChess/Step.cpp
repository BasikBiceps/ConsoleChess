#include "Step.h"

Step::Step(std::shared_ptr<Figure> moveFigure,
	std::shared_ptr<Figure> beatFigure,
	const FigurePosition& startPosition,
	const FigurePosition& endPosition) :
	m_moveFigure(moveFigure),
	m_beatFigure(beatFigure),
	m_startPosition(startPosition),
	m_endPosition(endPosition)
{
}

void Step::undo(GameBoard& gameBoard)
{
	gameBoard.moveFigure(m_endPosition, m_startPosition);

	if (m_beatFigure != nullptr)
	{
		gameBoard.addFigureOnBoard(*m_beatFigure);
	}
}
