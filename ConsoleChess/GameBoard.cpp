#include "GameBoard.h"
#include "GameBoardConfiguration.h"

#include <iostream>

const std::string kIncorrectTraceError = "Incorrect trace!";
const std::string kGameWithoutKingError = "Game without king!";

GameBoard::GameBoard()
{
	m_figures = GameBoardConfiguration::getStartFigurePositions();
	updateFigureTraces();
}

GameBoard::GameBoard(std::unique_ptr<std::vector<Figure>> figures) : m_figures(std::move(figures))
{
	updateFigureTraces();
}

GameBoard::GameBoard(const std::vector<Figure>& figures)
{
	m_figures = std::make_unique<std::vector<Figure>>(figures);
	updateFigureTraces();
}

void GameBoard::addFigureOnBoard(Figure& figure)
{
	m_figures->push_back(figure);
}

const std::vector<Figure>& GameBoard::getFigures() const
{
	return *(m_figures.get());
}

std::shared_ptr<std::vector<FigurePosition>> GameBoard::getDependentOnOtherFiguresFigureMoveTrace(const Figure& figure) const
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

std::shared_ptr<std::vector<FigurePosition>> GameBoard::getDependentOnOtherFiguresFigureBeatTrace(const Figure& figure) const
{
	auto trace = figure.getBeatTrace();
	auto result = std::make_shared<std::vector<FigurePosition>>();

	if (figure.getName() == NameOfFigures::Knight)
	{
		for (auto position : *trace)
		{
			if (isFigureOnPosition(position))
			{
				if (findFigureByPosition(position)->getColor() != figure.getColor())
				{
					result->push_back(position);
				}
			}
		}

		return result;
	}

	for (auto position : *trace)
	{
		if (isFigureOnPosition(position))
		{
			if (findFigureByPosition(position)->getColor() != figure.getColor())
			{
				if (!isFigureOnTrace(figure.getPosition(), position))
				{
					result->push_back(position);
				}
			}
		}
	}

	return result;
}

const std::vector<FigurePosition>& GameBoard::getWhiteFigureMoveTraces() const
{
	return m_whiteFigureMoveTraces;
}

const std::vector<FigurePosition>& GameBoard::getBlackFigureMoveTraces() const
{
	return m_blackFigureMoveTraces;
}

const std::vector<FigurePosition>& GameBoard::getWhiteFigureBeatTraces() const
{
	return m_whiteFigureBeatTraces;
}

const std::vector<FigurePosition>& GameBoard::getBlackFigureBeatTraces() const
{
	return m_blackFigureBeatTraces;
}

const FigurePosition& GameBoard::getKingPosition(const FigureColor& color) const
{
	std::string indicator;

	if (color == FigureColor::White)
	{
		indicator += ColorIndicator::kWhiteFigureIndicator;
	}
	else
	{
		indicator += ColorIndicator::kBlackFigureIndicator;
	}

	indicator += NameOfFigures::King;

	for (auto figure : *m_figures)
	{
		if (figure.getIndicator() == indicator)
		{
			return figure.getPosition();
		}
	}

	throw std::runtime_error(kGameWithoutKingError);
}

std::vector<Figure>::iterator GameBoard::findFigureByPosition(const FigurePosition& position)
{
	auto resultIterator = m_figures->begin();

	for (; resultIterator != getFigures().end(); ++resultIterator)
	{
		if ((*resultIterator).getPosition() == position)
		{
			return resultIterator;
		}
	}

	return resultIterator;
}

std::vector<Figure>::const_iterator GameBoard::findFigureByPosition(const FigurePosition& position) const
{
	auto resultIterator = m_figures->begin();

	for (; resultIterator != getFigures().end(); ++resultIterator)
	{
		if ((*resultIterator).getPosition() == position)
		{
			return resultIterator;
		}
	}

	return resultIterator;
}

void GameBoard::moveFigure(const FigurePosition& whereIs, const FigurePosition& whereTo)
{
	auto figureIter = findFigureByPosition(whereIs);

	if (figureIter != m_figures->end())
	{
		figureIter->setPosition(whereTo);
	}

	updateFigureTraces();
}

void GameBoard::beatFigure(const FigurePosition& whereIs, const FigurePosition& whereTo)
{
	auto moveFigureIter = findFigureByPosition(whereIs);
	auto beatFigureIter = findFigureByPosition(whereTo);

	if (moveFigureIter == m_figures->end() || beatFigureIter == m_figures->end())
	{
		return;
	}

	moveFigureIter->setPosition(whereTo);
	removeFigure(beatFigureIter);

	updateFigureTraces();
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

void GameBoard::updateFigureTraces()
{
	updateBeatFigureTraces();
	updateMoveFigureTraces();
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

	throw std::runtime_error(kIncorrectTraceError);
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
		for (auto x = from.x + 1, y = from.y - 1; FigurePosition({ x,y }) != to; ++x, --y)
		{
			if (isFigureOnPosition({ x, y }))
			{
				return true;
			}
		}
	}
	else
	{
		for (auto x = from.x + 1, y = from.y + 1; FigurePosition({ x,y }) != to; ++x, ++y)
		{
			if (isFigureOnPosition({ x, y }))
			{
				return true;
			}
		}
	}

	return false;
}

void GameBoard::updateMoveFigureTraces()
{
	m_whiteFigureMoveTraces.clear();
	m_blackFigureMoveTraces.clear();

	for (auto figure : *m_figures)
	{
		auto moveTrace = getDependentOnOtherFiguresFigureMoveTrace(figure);

		if (figure.getColor() == FigureColor::White)
		{
			std::copy(moveTrace->begin(), moveTrace->end(), std::back_inserter(m_whiteFigureMoveTraces));
		}
		else
		{
			std::copy(moveTrace->begin(), moveTrace->end(), std::back_inserter(m_blackFigureMoveTraces));
		}
	}
}

void GameBoard::updateBeatFigureTraces()
{
	m_blackFigureBeatTraces.clear();
	m_whiteFigureBeatTraces.clear();

	for (auto figure : *m_figures)
	{
		auto beatTrace = getDependentOnOtherFiguresFigureBeatTrace(figure);

		if (figure.getColor() == FigureColor::White)
		{
			std::copy(beatTrace->begin(), beatTrace->end(), std::back_inserter(m_whiteFigureBeatTraces));
		}
		else
		{
			std::copy(beatTrace->begin(), beatTrace->end(), std::back_inserter(m_blackFigureBeatTraces));
		}
	}
}
