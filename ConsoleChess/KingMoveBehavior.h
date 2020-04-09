#pragma once
#include <vector>
#include <memory>

#include "IFigureMoveBehavior.h"

class KingMoveBehavior : public IFigureMoveBehavior
{
public:
	std::shared_ptr<std::vector<FigurePosition>> move(const FigurePosition& whereIs, const FigureColor& color) const override final;

private:
	bool isValidPosition(const FigurePosition& whereIs) const;
};
