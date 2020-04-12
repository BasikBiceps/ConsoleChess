#pragma once
#include <vector>
#include <memory>

#include "IFigureMoveBehavior.h"

namespace PawnSteps
{
	constexpr int kShort = 1;
	constexpr int kLong = 2;
}

class PawnMoveBehavior : public IFigureMoveBehavior
{
public:
	std::shared_ptr<std::vector<FigurePosition>> move(const FigurePosition& whereIs, const FigureColor& color) const override final;
};

