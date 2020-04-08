#pragma once
#include <string>

#include "FigureColor.h"

class Player
{
public:
	Player(const std::string& name, const FigureColor& figureColor);

	const std::string& getName() const;
	const FigureColor& getFigureColor() const;

private:
	std::string m_name;
	FigureColor m_figureColor;
};
