#pragma once
#include "IFigureMoveBehavior.h"

class PawnBehavior : public IFigureMoveBehavior
{
public:
	bool move(const FigurePosition& whereIs, const FigurePosition& whereTo, const FigureColor& color) const override final;
};

