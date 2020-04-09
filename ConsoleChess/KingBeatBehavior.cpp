#include "KingBeatBehavior.h"
#include "KingMoveBehavior.h"

std::shared_ptr<std::vector<FigurePosition>> KingBeatBehavior::beat(const FigurePosition& whereIs, const FigureColor& color) const
{
	KingMoveBehavior kingMB;
	return kingMB.move(whereIs, color);
}
