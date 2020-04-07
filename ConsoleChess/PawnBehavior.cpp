#include "PawnBehavior.h"
#include "FigureColor.h"

constexpr std::size_t kWhiteYStartPosition = 1;
constexpr std::size_t kBlackYStartPosition = 6;
constexpr std::size_t kMaxYPawnStep = 2;
constexpr std::size_t kMinYPawnStep = 1;

bool PawnBehavior::move(const FigurePosition& whereIs, const FigurePosition& whereTo, const FigureColor& color) const
{
	if (whereIs.x != whereTo.x)
	{
		return false;
	}

	if (color == FigureColor::White)
	{
		auto step = whereTo.y - whereIs.y;

		if (step > kMaxYPawnStep || step < kMinYPawnStep)
		{
			return false;
		}

		if (step == kMaxYPawnStep && whereIs.y != kWhiteYStartPosition)
		{
			return false;
		}
	}
	else
	{
		auto step = whereIs.y - whereTo.y;

		if (step > kMaxYPawnStep || step < kMinYPawnStep)
		{
			return false;
		}

		if (step == kMaxYPawnStep && whereIs.y != kBlackYStartPosition)
		{
			return false;
		}
	}

	return true;
}
