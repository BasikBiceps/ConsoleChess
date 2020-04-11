#include "GameBoard.h"
#include "GameBoardConfiguration.h"

#include <iostream>

const std::string kIncorrectTraceMessage = "Incorrect trace!";

GameBoard::GameBoard()
{
	m_figures = GameBoardConfiguration::getStartFigurePositions();
}

GameBoard::GameBoard(std::unique_ptr<std::vector<Figure>> figures) : m_figures(std::move(figures))
{
}

void GameBoard::addFigureOnBoard(Figure& figure)
{
	m_figures->push_back(figure);
}

const std::vector<Figure>& GameBoard::getFigures() const
{
	return *(m_figures.get());
}

std::shared_ptr<std::vector<FigurePosition>> GameBoard::getDependentOnOtherFiguresFigureMoveTrace(const Figure& figure)
{
	auto trace = figure.getMoveTrace();
	auto result = std::make_shared<std::vector<FigurePosition>>();

	if (figure.getName() == NameOfFigures::Knight)
	{
		for (auto position : *trace)
		{
			if (!isFigureOnPosition(position))
			{
				result->push_back(position);
			}
		}

		return result;
	}

	for (auto position : *trace)
	{
		if (!isFigureOnPosition(position))
		{
			if (!isFigureOnTrace(figure.getPosition(), position))
			{
				result->push_back(position);
			}
		}
	}

	return result;
}

std::vector<Figure>::iterator GameBoard::findFigureByPosition(const FigurePosition& position)
{
	auto resultIteartor = m_figures->begin();

	for (; resultIteartor != getFigures().end(); ++resultIteartor)
	{
		if ((*resultIteartor).getPosition() == position)
		{
			return resultIteartor;
		}
	}

	return resultIteartor;
}

std::vector<Figure>::const_iterator GameBoard::findFigureByPosition(const FigurePosition& position) const
{
	auto resultIteartor = m_figures->begin();

	for (; resultIteartor != getFigures().end(); ++resultIteartor)
	{
		if ((*resultIteartor).getPosition() == position)
		{
			return resultIteartor;
		}
	}

	return resultIteartor;
}

void GameBoard::moveFigure(const FigurePosition& whereIs, const FigurePosition& whereTo)
{
	auto figureIter = findFigureByPosition(whereIs);

	if (figureIter != m_figures->end())
	{
		figureIter->setPosition(whereTo);
	}
}

void GameBoard::beatFigure(const FigurePosition& whereIs, const FigurePosition& whereTo)
{
	auto moveFigureIter = findFigureByPosition(whereIs);
	auto beatFigureIter = findFigureByPosition(whereIs);

	if (moveFigureIter == m_figures->end() || beatFigureIter == m_figures->end())
	{
		return;
	}

	moveFigureIter->setPosition(whereTo);
	removeFigure(beatFigureIter);
}

void GameBoard::draw() const
{
	std::cout << GameBoardConfiguration::getBoardPanel() << std::endl;
	std::cout << GameBoardConfiguration::getLineSeparator() << std::endl;

	for (std::size_t i = 0; i < GameBoardConfiguration::kBoardHeight; ++i)
	{
		std::cout << i + 1 << GameBoardConfiguration::getCellSeparator();
		for (std::size_t j = 0; j < GameBoardConfiguration::kBoardWidth; ++j)
		{
			auto figure = findFigureByPosition(FigurePosition({ j, i }));

			if (figure == m_figures->end())
			{
				std::cout << GameBoardConfiguration::getEmptyCell() << GameBoardConfiguration::getCellSeparator();
			}
			else
			{
				figure->draw();
				std::cout << GameBoardConfiguration::getCellSeparator();
			}

		}
		std::cout << i + 1 << std::endl;
		std::cout << GameBoardConfiguration::getLineSeparator() << std::endl;
	}
	std::cout << GameBoardConfiguration::getBoardPanel() << std::endl;
}

void GameBoard::reset()
{
	m_figures = GameBoardConfiguration::getStartFigurePositions();
}

bool GameBoard::isValidPosition(const FigurePosition& position) const
{
	return (position.x < GameBoardConfiguration::kBoardWidth && position.x >= 0) &&
		(position.y < GameBoardConfiguration::kBoardHeight && position.y >= 0);
}

bool GameBoard::isFigureOnPosition(const FigurePosition& position) const
{
	for (auto figure : *m_figures)
	{
		if (figure.getPosition() == position)
		{
			return true;
		}
	}

	return false;
}

bool GameBoard::isFigureOnTrace(const FigurePosition& whereIs, const FigurePosition& whereTo) const
{
	if (whereIs.x == whereTo.x)
	{
		return isFigureOnVertical(whereIs, whereTo);
	}

	if (whereIs.y == whereTo.y)
	{
		return isFigureOnHorizontal(whereIs, whereTo);
	}

	if (std::abs(static_cast<int>(whereIs.x) - static_cast<int>(whereTo.x)) ==
		std::abs(static_cast<int>(whereIs.y) - static_cast<int>(whereTo.y)))
	{
		return isFigureOnDiagonal(whereIs, whereTo);
	}

	throw std::runtime_error(kIncorrectTraceMessage);
}

void GameBoard::removeFigure(std::vector<Figure>::iterator elementIter)
{
	m_figures->erase(elementIter);
}

bool GameBoard::isFigureOnVertical(const FigurePosition& whereIs, const FigurePosition& whereTo) const
{
	auto from = whereIs.y < whereTo.y ? whereIs.y : whereTo.y;
	auto to = whereIs.y > whereTo.y ? whereIs.y : whereTo.y;

	for (auto y = from + 1; y < to; ++y)
	{
		if (isFigureOnPosition({ whereIs.x, y }))
		{
			return true;
		}
	}

	return false;
}

bool GameBoard::isFigureOnHorizontal(const FigurePosition& whereIs, const FigurePosition& whereTo) const
{
	auto from = whereIs.x < whereTo.x ? whereIs.x : whereTo.x;
	auto to = whereIs.x > whereTo.x ? whereIs.x : whereTo.x;

	for (auto x = from + 1; x < to; ++x)
	{
		if (isFigureOnPosition({ x, whereIs.y }))
		{
			return true;
		}
	}

	return false;
}

bool GameBoard::isFigureOnDiagonal(const FigurePosition& whereIs, const FigurePosition& whereTo) const
{
	auto from = whereIs.x < whereTo.x ? whereIs : whereTo;
	auto to = whereIs.x > whereTo.x ? whereIs : whereTo;

	if (from.y > to.y)
	{
		for (auto x = from.x + 1, y = from.y - 1; from != to; ++x, --y)
		{
			if (isFigureOnPosition({ x, y }))
			{
				return true;
			}
		}
	}
	else
	{
		for (auto x = from.x + 1, y = from.y + 1; from != to; ++x, ++y)
		{
			if (isFigureOnPosition({ x, y }))
			{
				return true;
			}
		}
	}

	return false;
}
