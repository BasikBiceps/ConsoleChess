#include "Figure.h"

Figure::Figure(std::string name, FigurePosition position, std::shared_ptr<IFigureBehavior> behavior, FigureColor color) :
	m_name(name), m_position(position), m_behavior(behavior), m_color(color)
{
}

bool Figure::move(FigurePosition whereTo)
{
	return m_behavior->move(m_position, whereTo, m_color);
}
