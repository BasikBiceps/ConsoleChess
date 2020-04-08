#include <iostream>

#include "GameBoardConfiguration.h"
#include "PawnBeatBehavior.h"
#include "PawnMoveBehavior.h"

constexpr std::size_t kWhiteYStartPosition = 1;
constexpr std::size_t kBlackYStartPosition = 6;

std::unique_ptr<std::vector<Figure>> GameBoardConfiguration::getStartFigurePositions()
{
	auto result = std::make_unique<std::vector<Figure>>();

	for (std::size_t i = 0; i < kBoardWidth; ++i)
	{
		result->push_back(Figure("WP", 
			{i,kWhiteYStartPosition},
			FigureColor::White,
			std::make_shared<PawnBeatBehavior>(),
			std::make_shared<PawnMoveBehavior>()));
	}

	for (std::size_t i = 0; i < kBoardWidth; ++i)
	{
		result->push_back(Figure("WP",
			{ i,kBlackYStartPosition },
			FigureColor::Black,
			std::make_shared<PawnBeatBehavior>(),
			std::make_shared<PawnMoveBehavior>()));
	}

	return result;
}

std::string GameBoardConfiguration::getBoardPanel()
{
	return "  a  b  c  d  e  f  g  h  ";
}

std::string GameBoardConfiguration::getCellSeparator()
{
	return "|";
}

std::string GameBoardConfiguration::getLineSeparator()
{
	return " ------------------------- ";
}

std::string GameBoardConfiguration::getEmptyCell()
{
	return "  ";
}
