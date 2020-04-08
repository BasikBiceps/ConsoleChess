#pragma once
#include <vector>
#include <memory>

#include "FigurePosition.h"
#include "FigureColor.h"

class IFigureBeatBehavior
{
public:
	virtual std::shared_ptr<std::vector<FigurePosition>> beat(const FigurePosition& whereIs, const FigureColor& color) const = 0;
};
