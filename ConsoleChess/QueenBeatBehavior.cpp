#include "QueenBeatBehavior.h"
#include "QueenMoveBehavior.h"

std::shared_ptr<std::vector<FigurePosition>> QueenBeatBehavior::beat(const FigurePosition& whereIs, const FigureColor& color) const
{
	QueenMoveBehavior queenMB;

	return queenMB.move(whereIs, color);
}
