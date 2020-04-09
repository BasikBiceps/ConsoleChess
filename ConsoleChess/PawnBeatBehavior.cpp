#include "PawnBeatBehavior.h"
#include "GameBoardConfiguration.h"

std::shared_ptr<std::vector<FigurePosition>> PawnBeatBehavior::beat(const FigurePosition& whereIs, const FigureColor& color) const
{
	auto resultTrace = std::make_shared<std::vector<FigurePosition>>();

	if (whereIs.y == BoardBorders::kWhiteYEndPosition || whereIs.y == BoardBorders::kBlackYEndPosition)
	{
		return resultTrace;
	}

	if (color == FigureColor::White)
	{
		if (whereIs.x == BoardBorders::kXLeftEndPosition)
		{
			resultTrace->push_back({ whereIs.x + 1, whereIs.y + 1 });
		}
		else if (whereIs.x == BoardBorders::kXRightEndPosition)
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
		if (whereIs.x == BoardBorders::kXLeftEndPosition)
		{
			resultTrace->push_back({ whereIs.x + 1, whereIs.y - 1 });
		}
		else if (whereIs.x == BoardBorders::kXRightEndPosition)
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