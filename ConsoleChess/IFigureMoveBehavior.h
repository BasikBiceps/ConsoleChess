#pragma once
#include <vector>
#include <memory>

#include "FigurePosition.h"
#include "FigureColor.h"

class IFigureMoveBehavior
{
public:
	virtual std::shared_ptr<std::vector<FigurePosition>> move(const FigurePosition& whereIs, const FigureColor& color) const = 0;
};
