#include "PawnMoveBehavior.h"
#include "FigureColor.h"

constexpr std::size_t kWhiteYStartPosition = 1;
constexpr std::size_t kBlackYStartPosition = 6;
constexpr std::size_t kWhiteYEndPosition = 7;
constexpr std::size_t kBlackYEndPosition = 0;

std::shared_ptr<std::vector<FigurePosition>> PawnMoveBehavior::move(const FigurePosition& whereIs, const FigureColor& color) const
{
	auto resultTrace = std::make_shared<std::vector<FigurePosition>>();

	if (whereIs.y == kWhiteYEndPosition || whereIs.y == kBlackYEndPosition)
	{
		return resultTrace;
	}

	if (color == FigureColor::White)
	{
		resultTrace->push_back({ whereIs.x, whereIs.y + 1 });

		if (whereIs.y == kWhiteYStartPosition)
		{
			resultTrace->push_back({ whereIs.x, whereIs.y + 2 });
		} 
	} 
	else
	{
		resultTrace->push_back({ whereIs.x, whereIs.y - 1 });

		if (whereIs.y == kBlackYStartPosition)
		{
			resultTrace->push_back({ whereIs.x, whereIs.y - 2 });
		}
	}

	return resultTrace;
}
