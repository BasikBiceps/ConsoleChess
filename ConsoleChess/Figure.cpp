#include <iostream>

#include "Figure.h"
#include "GameBoardConfiguration.h"

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

void Figure::setName(const std::string& name)
{
	m_name = name;
}

void Figure::setBeatBehavior(std::shared_ptr<IFigureBeatBehavior> beatBehavior)
{
	m_beatBehavior = beatBehavior;
}

void Figure::setMoveBehavior(std::shared_ptr<IFigureMoveBehavior> moveBehavior)
{
	m_moveBehavior = moveBehavior;
}

std::string Figure::getIndicator() const
{
	std::string colorIndicator;

	if (m_color == FigureColor::White)
	{
		colorIndicator = ColorIndicator::kWhiteFigureIndicator;
	}
	else
	{
		colorIndicator = ColorIndicator::kBlackFigureIndicator;
	}

	return colorIndicator + m_name;
}

const std::string& Figure::getName() const
{
	return m_name;
}

const FigureColor& Figure::getColor() const
{
	return m_color;
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
	std::cout << getIndicator();
}

bool Figure::isValidPosition(const FigurePosition& whereIs)
{
	return (whereIs.x >= BoardBorders::kXLeftEndPosition && whereIs.x <= BoardBorders::kXRightEndPosition) &&
		(whereIs.y >= BoardBorders::kBlackYEndPosition && whereIs.y <= BoardBorders::kWhiteYEndPosition);
}
