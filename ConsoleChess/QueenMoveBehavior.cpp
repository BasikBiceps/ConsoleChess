#include "QueenMoveBehavior.h"
#include "BishopMoveBehavior.h"
#include "RookMoveBehavior.h"

std::shared_ptr<std::vector<FigurePosition>> QueenMoveBehavior::move(const FigurePosition& whereIs, const FigureColor& color) const
{
	BishopMoveBehavior bishopMB;
	RookMoveBehavior rookMB;
	auto bishopTrace = bishopMB.move(whereIs, color);
	auto rookTrace = rookMB.move(whereIs, color);

	std::copy(rookTrace->begin(), rookTrace->end(), std::back_inserter(*bishopTrace));

	return bishopTrace;
}
