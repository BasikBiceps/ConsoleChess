#include "RookBeatBehavior.h"
#include "RookMoveBehavior.h"

std::shared_ptr<std::vector<FigurePosition>> RookBeatBehavior::beat(const FigurePosition& whereIs, const FigureColor& color) const
{
	RookMoveBehavior rookMB;
	return rookMB.move(whereIs,color);
}
