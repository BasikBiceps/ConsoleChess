#include "BishopMoveBehavior.h"
#include "GameBoardConfiguration.h"

std::shared_ptr<std::vector<FigurePosition>> BishopMoveBehavior::move(const FigurePosition& whereIs, const FigureColor& color) const
{
	auto resultTrace = std::make_shared<std::vector<FigurePosition>>();
	auto kXLeftEndPosition = static_cast<int>(BoardBorders::kXLeftEndPosition);
	auto kBlackYEndPosition = static_cast<int>(BoardBorders::kBlackYEndPosition);
	auto kXRightEndPosition = static_cast<int>(BoardBorders::kXRightEndPosition);
	auto kWhiteYEndPosition = static_cast<int>(BoardBorders::kWhiteYEndPosition);

	for (int x = whereIs.x - 1, y = whereIs.y - 1; (x >= kXLeftEndPosition) && (y >= kBlackYEndPosition); --x, --y)
	{
		resultTrace->push_back({ static_cast<std::size_t>(x), static_cast<std::size_t>(y) });
	}

	for (std::size_t x = whereIs.x + 1, y = whereIs.y + 1; (x <= kXRightEndPosition) && (y <= kWhiteYEndPosition); ++x, ++y)
	{
		resultTrace->push_back({ static_cast<std::size_t>(x), static_cast<std::size_t>(y) });
	}

	for (std::size_t x = whereIs.x - 1, y = whereIs.y + 1; (x >= kXLeftEndPosition) && (y <= kWhiteYEndPosition); --x, ++y)
	{
		resultTrace->push_back({ static_cast<std::size_t>(x), static_cast<std::size_t>(y) });
	}

	for (std::size_t x = whereIs.x + 1, y = whereIs.y - 1; (x <= kXRightEndPosition) && (y >= kBlackYEndPosition); ++x, --y)
	{
		resultTrace->push_back({ static_cast<std::size_t>(x), static_cast<std::size_t>(y) });
	}

	return resultTrace;
}
