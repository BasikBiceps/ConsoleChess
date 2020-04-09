#include <iostream>

#include "Figure.h"

const std::string kWhiteFigureIndicator = "W";
const std::string kBlackFigureIndicator = "B";

Figure::Figure(const std::string& name,
	const FigurePosition& position,
	const FigureColor& color,
	std::shared_ptr<IFigureBeatBehavior> beatBehavior,
	std::shared_ptr<IFigureMoveBehavior> moveBehavior) :
	m_name(name), 
	m_position(position),
	m_color(color),
	m_moveBehavior(moveBehavior),
	m_beatBehavior(beatBehavior)
{
}

void Figure::setPosition(const FigurePosition& position)
{
	m_position = position;
}

std::shared_ptr<std::vector<FigurePosition>> Figure::getMoveTrace() const
{
	return m_moveBehavior->move(m_position, m_color);
}

std::shared_ptr<std::vector<FigurePosition>> Figure::getBeatTrace() const
{
	return m_beatBehavior->beat(m_position, m_color);
}

const FigurePosition& Figure::getPosition() const
{
	return m_position;
}

void Figure::draw() const
{
	if (m_color == FigureColor::White)
	{
		std::cout << kWhiteFigureIndicator << m_name;
	}
	else
	{
		std::cout << kBlackFigureIndicator << m_name;
	}
}