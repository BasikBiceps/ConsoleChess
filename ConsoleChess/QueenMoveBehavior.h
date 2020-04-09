#pragma once
#include <vector>
#include <memory>

#include "IFigureMoveBehavior.h"

class QueenMoveBehavior : public IFigureMoveBehavior
{
public:
	std::shared_ptr<std::vector<FigurePosition>> move(const FigurePosition& whereIs, const FigureColor& color) const override final;
};
