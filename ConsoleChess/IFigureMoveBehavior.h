#pragma once
#include "FigurePosition.h"
#include "FigureColor.h"

class IFigureMoveBehavior
{
public:
	virtual bool move(const FigurePosition& whereIs, const FigurePosition& whereTo, const FigureColor& color) const = 0;
};
