#include "KnightMoveBehavior.h"
#include "GameBoardConfiguration.h"

constexpr std::size_t kShortStep = 1;
constexpr std::size_t kLongStep = 2;

std::shared_ptr<std::vector<FigurePosition>> KnightMoveBehavior::move(const FigurePosition& whereIs, const FigureColor& color) const
{
	auto resultTrace = std::make_shared<std::vector<FigurePosition>>();

	std::vector<FigurePosition> steps({
		{ whereIs.x - kShortStep, whereIs.y + kLongStep },
		{ whereIs.x + kShortStep, whereIs.y + kLongStep },
		{ whereIs.x + kLongStep, whereIs.y + kShortStep },
		{ whereIs.x - kLongStep, whereIs.y + kShortStep },
		{ whereIs.x + kLongStep, whereIs.y - kShortStep },
		{ whereIs.x - kLongStep, whereIs.y - kShortStep },
		{ whereIs.x + kShortStep, whereIs.y - kLongStep },
		{ whereIs.x - kShortStep, whereIs.y - kLongStep }
		});

	for (auto step : steps)
	{
		if (Figure::isValidPosition(step))
		{
			resultTrace->push_back(step);
		}
	}

	return resultTrace;
}