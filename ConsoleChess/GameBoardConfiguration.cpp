#include <iostream>

#include "GameBoardConfiguration.h"
#include "PawnBeatBehavior.h"
#include "PawnMoveBehavior.h"
#include "BishopBeatBehavior.h"
#include "BishopMoveBehavior.h"

const std::string kBoardPanel = "  a  b  c  d  e  f  g  h  ";
const std::string kCellSeparator = "|";
const std::string kEmptyCell = "  ";
const std::string kLineSeparator = " ------------------------- ";

constexpr std::size_t kWhitePawnYStartPosition = 1;
constexpr std::size_t kBlackPawnYStartPosition = 6;

constexpr FigurePosition kBishopWhiteLeftStandartPosition = { 2, 0 };
constexpr FigurePosition kBishopWhiteRightStandartPosition = { 5, 0 };

constexpr FigurePosition kBishopBlackLeftStandartPosition = { 2, 7 };
constexpr FigurePosition kBishopBlackRightStandartPosition = { 5, 7 };

std::unique_ptr<std::vector<Figure>> GameBoardConfiguration::getStartFigurePositions()
{
	auto result = std::make_unique<std::vector<Figure>>();

	for (std::size_t i = 0; i < kBoardWidth; ++i)
	{
		result->push_back(Figure(NameOfFigures::Pawn, 
			{i,kWhitePawnYStartPosition},
			FigureColor::White,
			std::make_shared<PawnBeatBehavior>(),
			std::make_shared<PawnMoveBehavior>()));
	}

	for (std::size_t i = 0; i < kBoardWidth; ++i)
	{
		result->push_back(Figure(NameOfFigures::Pawn,
			{ i,kBlackPawnYStartPosition },
			FigureColor::Black,
			std::make_shared<PawnBeatBehavior>(),
			std::make_shared<PawnMoveBehavior>()));
	}

	result->push_back(Figure(NameOfFigures::Bishop,
		kBishopWhiteLeftStandartPosition,
		FigureColor::White,
		std::make_shared<BishopBeatBehavior>(),
		std::make_shared<BishopMoveBehavior>()));

	result->push_back(Figure(NameOfFigures::Bishop,
		kBishopWhiteRightStandartPosition,
		FigureColor::White,
		std::make_shared<BishopBeatBehavior>(),
		std::make_shared<BishopMoveBehavior>()));

	result->push_back(Figure(NameOfFigures::Bishop,
		kBishopBlackLeftStandartPosition,
		FigureColor::Black,
		std::make_shared<BishopBeatBehavior>(),
		std::make_shared<BishopMoveBehavior>()));

	result->push_back(Figure(NameOfFigures::Bishop,
		kBishopBlackRightStandartPosition,
		FigureColor::Black,
		std::make_shared<BishopBeatBehavior>(),
		std::make_shared<BishopMoveBehavior>()));

	return result;
}

std::string GameBoardConfiguration::getBoardPanel()
{
	return kBoardPanel;
}

std::string GameBoardConfiguration::getCellSeparator()
{
	return kCellSeparator;
}

std::string GameBoardConfiguration::getLineSeparator()
{
	return kLineSeparator;
}

std::string GameBoardConfiguration::getEmptyCell()
{
	return kEmptyCell;
}
