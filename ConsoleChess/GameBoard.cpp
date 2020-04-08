#include "GameBoard.h"
#include "GameBoardConfiguration.h"

#include <iostream>
#include <algorithm>

GameBoard::GameBoard()
{
	m_figures = GameBoardConfiguration::getStartFigurePositions();
}

GameBoard::GameBoard(std::unique_ptr<std::vector<Figure>> figures) : m_figures(std::move(figures))
{
}

const std::vector<Figure>& GameBoard::getFigures() const
{
	return *(m_figures.get());
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

void GameBoard::removeFigure(std::vector<Figure>::iterator elementIter)
{
	m_figures->erase(elementIter);
}