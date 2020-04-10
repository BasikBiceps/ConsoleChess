#include "KingMoveBehavior.h"
#include "GameBoardConfiguration.h"

constexpr std::size_t kStepLength = 1;

std::shared_ptr<std::vector<FigurePosition>> KingMoveBehavior::move(const FigurePosition& whereIs, const FigureColor& color) const
{
	auto resultTrace = std::make_shared<std::vector<FigurePosition>>();

	std::vector<FigurePosition> steps({ 
		{ whereIs.x + kStepLength, whereIs.y + kStepLength },
		{ whereIs.x - kStepLength, whereIs.y - kStepLength },
		{ whereIs.x + kStepLength, whereIs.y - kStepLength },
		{ whereIs.x - kStepLength, whereIs.y + kStepLength },
		{ whereIs.x, whereIs.y + kStepLength },
		{ whereIs.x, whereIs.y - kStepLength },
		{ whereIs.x + kStepLength, whereIs.y },
		{ whereIs.x - kStepLength, whereIs.y }
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