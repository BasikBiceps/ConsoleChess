#include <iostream>

#include "GameBoardConfiguration.h"
#include "PawnBeatBehavior.h"
#include "PawnMoveBehavior.h"
#include "BishopBeatBehavior.h"
#include "BishopMoveBehavior.h"
#include "RookBeatBehavior.h"
#include "RookMoveBehavior.h"
#include "QueenBeatBehavior.h"
#include "QueenMoveBehavior.h"
#include "KingBeatBehavior.h"
#include "KingMoveBehavior.h"

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

constexpr FigurePosition kRookWhiteLeftStandartPosition = { 0, 0 };
constexpr FigurePosition kRookWhiteRightStandartPosition = { 7, 0 };

constexpr FigurePosition kRookBlackLeftStandartPosition = { 0, 7 };
constexpr FigurePosition kRookBlackRightStandartPosition = { 7, 7 };

constexpr FigurePosition kQueenWhiteStandartPosition = { 3, 0 };
constexpr FigurePosition kQueenBlackStandartPosition = { 3, 7 };

constexpr FigurePosition kKingWhiteStandartPosition = { 4, 0 };
constexpr FigurePosition kKingBlackStandartPosition = { 4, 7 };

std::unique_ptr<std::vector<Figure>> GameBoardConfiguration::getStartFigurePositions()
{
	auto result = std::make_unique<std::vector<Figure>>();

	createPawns(*result.get());
	createBishops(*result.get());
	createRooks(*result.get());
	createQueens(*result.get());
	createKings(*result.get());

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

void GameBoardConfiguration::createRooks(std::vector<Figure>& figures)
{
	figures.push_back(Figure(NameOfFigures::Rook,
		kRookWhiteLeftStandartPosition,
		FigureColor::White,
		std::make_shared<RookBeatBehavior>(),
		std::make_shared<RookMoveBehavior>()));

	figures.push_back(Figure(NameOfFigures::Rook,
		kRookWhiteRightStandartPosition,
		FigureColor::White,
		std::make_shared<RookBeatBehavior>(),
		std::make_shared<RookMoveBehavior>()));

	figures.push_back(Figure(NameOfFigures::Rook,
		kRookBlackLeftStandartPosition,
		FigureColor::Black,
		std::make_shared<RookBeatBehavior>(),
		std::make_shared<RookMoveBehavior>()));

	figures.push_back(Figure(NameOfFigures::Rook,
		kRookBlackRightStandartPosition,
		FigureColor::Black,
		std::make_shared<RookBeatBehavior>(),
		std::make_shared<RookMoveBehavior>()));
}

void GameBoardConfiguration::createBishops(std::vector<Figure>& figures)
{
	figures.push_back(Figure(NameOfFigures::Bishop,
		kBishopWhiteLeftStandartPosition,
		FigureColor::White,
		std::make_shared<BishopBeatBehavior>(),
		std::make_shared<BishopMoveBehavior>()));

	figures.push_back(Figure(NameOfFigures::Bishop,
		kBishopWhiteRightStandartPosition,
		FigureColor::White,
		std::make_shared<BishopBeatBehavior>(),
		std::make_shared<BishopMoveBehavior>()));

	figures.push_back(Figure(NameOfFigures::Bishop,
		kBishopBlackLeftStandartPosition,
		FigureColor::Black,
		std::make_shared<BishopBeatBehavior>(),
		std::make_shared<BishopMoveBehavior>()));

	figures.push_back(Figure(NameOfFigures::Bishop,
		kBishopBlackRightStandartPosition,
		FigureColor::Black,
		std::make_shared<BishopBeatBehavior>(),
		std::make_shared<BishopMoveBehavior>()));
}

void GameBoardConfiguration::createPawns(std::vector<Figure>& figures)
{
	for (std::size_t i = 0; i < kBoardWidth; ++i)
	{
		figures.push_back(Figure(NameOfFigures::Pawn,
			{ i,kWhitePawnYStartPosition },
			FigureColor::White,
			std::make_shared<PawnBeatBehavior>(),
			std::make_shared<PawnMoveBehavior>()));
	}

	for (std::size_t i = 0; i < kBoardWidth; ++i)
	{
		figures.push_back(Figure(NameOfFigures::Pawn,
			{ i,kBlackPawnYStartPosition },
			FigureColor::Black,
			std::make_shared<PawnBeatBehavior>(),
			std::make_shared<PawnMoveBehavior>()));
	}
}

void GameBoardConfiguration::createQueens(std::vector<Figure>& figures)
{
	figures.push_back(Figure(NameOfFigures::Queen,
		kQueenWhiteStandartPosition,
		FigureColor::White,
		std::make_shared<QueenBeatBehavior>(),
		std::make_shared<QueenMoveBehavior>()));

	figures.push_back(Figure(NameOfFigures::Queen,
		kQueenBlackStandartPosition,
		FigureColor::Black,
		std::make_shared<QueenBeatBehavior>(),
		std::make_shared<QueenMoveBehavior>()));
}

void GameBoardConfiguration::createKings(std::vector<Figure>& figures)
{
	figures.push_back(Figure(NameOfFigures::King,
		kKingWhiteStandartPosition,
		FigureColor::White,
		std::make_shared<KingBeatBehavior>(),
		std::make_shared<KingMoveBehavior>()));

	figures.push_back(Figure(NameOfFigures::King,
		kKingBlackStandartPosition,
		FigureColor::Black,
		std::make_shared<KingBeatBehavior>(),
		std::make_shared<KingMoveBehavior>()));
}
