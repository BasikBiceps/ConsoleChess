#pragma once
#include <memory>

#include "Figure.h"
#include "FigurePosition.h"
#include "GameBoard.h"
#include "Step.h"

class CastlingStep : public Step
{
public:
	CastlingStep(std::shared_ptr<Figure> king,
		std::shared_ptr<Figure> rook,
		const FigurePosition& startPositionKing,
		const FigurePosition& endPositionKing,
		const FigurePosition& startPositionRook,
		const FigurePosition& endPositionRook);

	void undo(GameBoard& gameBoard) override;

private:
	std::shared_ptr<Figure> m_rook;
	FigurePosition m_startPositionRook;
	FigurePosition m_endPositionRook;
};
