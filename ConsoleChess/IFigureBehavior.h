#pragma once
#include "FigurePosition.h"
#include "FigureColor.h"

class IFigureBehavior
{
public:
	virtual bool move(FigurePosition whereIs, FigurePosition whereTo, FigureColor color) = 0;
};
