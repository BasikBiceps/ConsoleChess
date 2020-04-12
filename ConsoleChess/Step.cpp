#include "Step.h"

Step::Step(std::shared_ptr<Figure> moveFigure,
	const FigurePosition& startPosition,
	const FigurePosition& endPosition) :
	m_moveFigure(moveFigure),
	m_startPosition(startPosition),
	m_endPosition(endPosition)
{
}

const FigurePosition& Step::getStartPosition() const
{
	return m_startPosition;
}

const FigurePosition& Step::getEndPosition() const
{
	return m_endPosition;
}

std::shared_ptr<Figure> Step::getMoveFigure() const
{
	return m_moveFigure;
}
