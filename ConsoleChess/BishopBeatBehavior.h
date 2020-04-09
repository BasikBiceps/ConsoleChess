#pragma once
#include <vector>
#include <memory>

#include "IFigureBeatBehavior.h"

class BishopBeatBehavior : public IFigureBeatBehavior
{
public:
	std::shared_ptr<std::vector<FigurePosition>> beat(const FigurePosition& whereIs, const FigureColor& color) const override final;
};
