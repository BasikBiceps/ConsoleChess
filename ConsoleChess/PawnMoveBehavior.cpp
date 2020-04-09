#include "PawnMoveBehavior.h"
#include "FigureColor.h"
#include "GameBoardConfiguration.h"

constexpr std::size_t kWhitePawnYStartPosition = 1;
constexpr std::size_t kBlackPawnYStartPosition = 6;

std::shared_ptr<std::vector<FigurePosition>> PawnMoveBehavior::move(const FigurePosition& whereIs, const FigureColor& color) const
{
	auto resultTrace = std::make_shared<std::vector<FigurePosition>>();

	if (whereIs.y == BoardBorders::kWhiteYEndPosition || whereIs.y == BoardBorders::kBlackYEndPosition)
	{
		return resultTrace;
	}

	if (color == FigureColor::White)
	{
		resultTrace->push_back({ whereIs.x, whereIs.y + 1 });

		if (whereIs.y == kWhitePawnYStartPosition)
		{
			resultTrace->push_back({ whereIs.x, whereIs.y + 2 });
		} 
	} 
	else
	{
		resultTrace->push_back({ whereIs.x, whereIs.y - 1 });

		if (whereIs.y == kBlackPawnYStartPosition)
		{
			resultTrace->push_back({ whereIs.x, whereIs.y - 2 });
		}
	}

	return resultTrace;
}
