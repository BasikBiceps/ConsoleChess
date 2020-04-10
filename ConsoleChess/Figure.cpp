#include <iostream>

#include "Figure.h"
#include "GameBoardConfiguration.h"

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

std::string Figure::getIndicator() const
{
	std::string colorIndicator;

	if (m_color == FigureColor::White)
	{
		colorIndicator = kWhiteFigureIndicator;
	}
	else
	{
		colorIndicator = kBlackFigureIndicator;
	}

	return colorIndicator + m_name;
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
