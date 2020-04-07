#include <iostream>

#include "Figure.h"

constexpr std::size_t kNameHeight = 1;

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

bool Figure::move(const FigurePosition& whereTo) const
{
	return m_moveBehavior->move(m_position, whereTo, m_color);
}

bool Figure::beat(const FigurePosition& whereTo) const
{
	return m_beatBehavior->beat(m_position, whereTo, m_color);
}

void Figure::draw() const
{
	std::cout << m_name;
}

std::size_t Figure::getPixelWidth() const
{
	return m_name.length();
}

std::size_t Figure::getPixelHeight() const
{
	return kNameHeight;
}
