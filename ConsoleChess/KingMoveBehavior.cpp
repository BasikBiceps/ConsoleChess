#include "KingMoveBehavior.h"
#include "GameBoardConfiguration.h"

std::shared_ptr<std::vector<FigurePosition>> KingMoveBehavior::move(const FigurePosition& whereIs, const FigureColor& color) const
{
	auto resultTrace = std::make_shared<std::vector<FigurePosition>>();

	std::vector<FigurePosition> steps({ 
		{ whereIs.x + 1, whereIs.y + 1 },
		{ whereIs.x - 1, whereIs.y - 1 },
		{ whereIs.x + 1, whereIs.y - 1 },
		{ whereIs.x - 1, whereIs.y + 1 },
		{ whereIs.x, whereIs.y + 1 },
		{ whereIs.x, whereIs.y - 1 },
		{ whereIs.x + 1, whereIs.y },
		{ whereIs.x - 1, whereIs.y }
		});

	for (auto step : steps)
	{
		if (isValidPosition(step))
		{
			resultTrace->push_back(step);
		}
	}

	return resultTrace;
}

bool KingMoveBehavior::isValidPosition(const FigurePosition& whereIs) const
{
	return (whereIs.x >= BoardBorders::kXLeftEndPosition && whereIs.x <= BoardBorders::kXRightEndPosition) &&
		(whereIs.y >= BoardBorders::kBlackYEndPosition && whereIs.y <= BoardBorders::kWhiteYEndPosition);
}
