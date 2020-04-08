#include "Player.h"

Player::Player(const std::string& name, const FigureColor& figureColor) : m_name(name), m_figureColor(figureColor)
{
}

const std::string& Player::getName() const
{
	return m_name;
}

const FigureColor& Player::getFigureColor() const
{
	return m_figureColor;
}
