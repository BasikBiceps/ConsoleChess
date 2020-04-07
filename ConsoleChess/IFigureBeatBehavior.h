#pragma once
#include "FigurePosition.h"
#include "FigureColor.h"

class IFigureBeatBehavior
{
public:
	virtual bool beat(const FigurePosition& whereIs, const FigurePosition& whereTo, const FigureColor& color) const = 0;
};
