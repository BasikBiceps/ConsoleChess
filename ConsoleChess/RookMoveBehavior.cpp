#include "RookMoveBehavior.h"
#include "GameBoardConfiguration.h"

std::shared_ptr<std::vector<FigurePosition>> RookMoveBehavior::move(const FigurePosition& whereIs, const FigureColor& color) const
{
	auto resultTrace = std::make_shared<std::vector<FigurePosition>>();

	for (std::size_t x = whereIs.x, y = 0; y <= BoardBorders::kWhiteYEndPosition; ++y)
	{
		if (y != whereIs.y)
		{
			resultTrace->push_back({ x,y });
		}
	}

	for (std::size_t x = 0, y = whereIs.y; x <= BoardBorders::kXRightEndPosition; ++x)
	{
		if (x != whereIs.x)
		{
			resultTrace->push_back({ x,y });
		}
	}

	return resultTrace;
}
