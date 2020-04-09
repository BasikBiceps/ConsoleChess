#include "BishopBeatBehavior.h"
#include "BishopMoveBehavior.h"

std::shared_ptr<std::vector<FigurePosition>> BishopBeatBehavior::beat(const FigurePosition& whereIs, const FigureColor& color) const
{
	BishopMoveBehavior bishopMB;
	return bishopMB.move(whereIs, color);
}
