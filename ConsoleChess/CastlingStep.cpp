#include "CastlingStep.h"

CastlingStep::CastlingStep(
	std::shared_ptr<Figure> king, 
	std::shared_ptr<Figure> rook, 
	const FigurePosition& startPositionKing, 
	const FigurePosition& endPositionKing, 
	const FigurePosition& startPositionRook, 
	const FigurePosition& endPositionRook) :
	Step(king, startPositionKing, endPositionKing),
	m_rook(rook),
	m_startPositionRook(startPositionRook),
	m_endPositionRook(endPositionRook)
{
}

void CastlingStep::undo(GameBoard& gameBoard)
{
	gameBoard.moveFigure(m_endPosition, m_startPosition);
	gameBoard.moveFigure(m_endPositionRook, m_startPositionRook);
}
