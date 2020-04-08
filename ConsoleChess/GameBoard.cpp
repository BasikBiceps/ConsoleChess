#include "GameBoard.h"
#include "GameBoardConfiguration.h"

#include <iostream>

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

std::shared_ptr<Figure> GameBoard::findFigureByPosition(const FigurePosition& position) const
{
	for (auto& el : *m_figures) 
	{
		if (el.getPosition() == position)
		{
			return std::make_shared<Figure>(el);
		}
	}

	return nullptr;
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

			if (figure == nullptr)
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
