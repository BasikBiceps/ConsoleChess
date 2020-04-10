#include "KnightBeatBehavior.h"
#include "KnightMoveBehavior.h"

std::shared_ptr<std::vector<FigurePosition>> KnightBeatBehavior::beat(const FigurePosition& whereIs, const FigureColor& color) const
{
	KnightMoveBehavior knightMB;
	return knightMB.move(whereIs, color);
}
