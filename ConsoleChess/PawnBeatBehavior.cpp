#include "PawnBeatBehavior.h"

constexpr std::size_t kXLeftEndPosition = 0;
constexpr std::size_t kXRightEndPosition = 7;
constexpr std::size_t kWhiteYEndPosition = 7;
constexpr std::size_t kBlackYEndPosition = 0;

std::shared_ptr<std::vector<FigurePosition>> PawnBeatBehavior::beat(const FigurePosition& whereIs, const FigureColor& color) const
{
	auto resultTrace = std::make_shared<std::vector<FigurePosition>>();

	if (whereIs.y == kWhiteYEndPosition || whereIs.y == kBlackYEndPosition)
	{
		return resultTrace;
	}

	if (color == FigureColor::White)
	{
		if (whereIs.x == kXLeftEndPosition)
		{
			resultTrace->push_back({ whereIs.x + 1, whereIs.y + 1 });
		}
		else if (whereIs.x == kXRightEndPosition)
		{
			resultTrace->push_back({ whereIs.x - 1, whereIs.y + 1 });
		}
		else
		{
			resultTrace->push_back({ whereIs.x + 1, whereIs.y + 1 });
			resultTrace->push_back({ whereIs.x - 1, whereIs.y + 1 });
		}
	}
	else
	{
		if (whereIs.x == kXLeftEndPosition)
		{
			resultTrace->push_back({ whereIs.x + 1, whereIs.y - 1 });
		}
		else if (whereIs.x == kXRightEndPosition)
		{
			resultTrace->push_back({ whereIs.x - 1, whereIs.y - 1 });
		}
		else
		{
			resultTrace->push_back({ whereIs.x + 1, whereIs.y - 1 });
			resultTrace->push_back({ whereIs.x - 1, whereIs.y - 1 });
		}
	}

	return resultTrace;
}