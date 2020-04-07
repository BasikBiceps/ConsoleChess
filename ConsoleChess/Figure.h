#pragma once
#include "FigurePosition.h"
#include "IDrawn.h"
#include "IFigureBehavior.h"
#include "FigureColor.h"

#include <string>
#include <memory>

class Figure : public IDrawn
{
public:
	Figure(std::string name, FigurePosition position, std::shared_ptr<IFigureBehavior> behavior, FigureColor color);

	bool move(FigurePosition whereTo);

private:
	std::string m_name;
	FigurePosition m_position;
	std::shared_ptr<IFigureBehavior> m_behavior;
	FigureColor m_color;
};
