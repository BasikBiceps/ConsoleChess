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
#include "KnightBeatBehavior.h"
#include "KnightMoveBehavior.h"

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

constexpr FigurePosition kKnightWhiteLeftStandartPosition = { 1, 0 };
constexpr FigurePosition kKnightWhiteRightStandartPosition = { 6, 0 };

constexpr FigurePosition kKnightBlackLeftStandartPosition = { 1, 7 };
constexpr FigurePosition kKnightBlackRightStandartPosition = { 6, 7 };

std::unique_ptr<std::vector<Figure>> GameBoardConfiguration::getStartFigurePositions()
{
	auto result = std::make_unique<std::vector<Figure>>();

	createPawns(*result.get());
	createBishops(*result.get());
	createRooks(*result.get());
	createQueens(*result.get());
	createKings(*result.get());
	createKnights(*result.get());

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

std::shared_ptr<IFigureBeatBehavior> GameBoardConfiguration::createBeatBehavior(const std::string& name)
{
	if (name == NameOfFigures::Bishop)
	{
		return std::make_shared<BishopBeatBehavior>();
	}
	if (name == NameOfFigures::Knight)
	{
		return std::make_shared<KnightBeatBehavior>();
	}
	if (name == NameOfFigures::Rook)
	{
		return std::make_shared<RookBeatBehavior>();
	}
	if (name == NameOfFigures::Queen)
	{
		return std::make_shared<QueenBeatBehavior>();
	}
	if (name == NameOfFigures::Pawn)
	{
		return std::make_shared<PawnBeatBehavior>();
	}
	if (name == NameOfFigures::King)
	{
		return std::make_shared<KingBeatBehavior>();
	}

	return nullptr;
}

std::shared_ptr<IFigureMoveBehavior> GameBoardConfiguration::createMoveBehavior(const std::string& name)
{
	if (name == NameOfFigures::Bishop)
	{
		return std::make_shared<BishopMoveBehavior>();
	}
	if (name == NameOfFigures::Knight)
	{
		return std::make_shared<KnightMoveBehavior>();
	}
	if (name == NameOfFigures::Rook)
	{
		return std::make_shared<RookMoveBehavior>();
	}
	if (name == NameOfFigures::Queen)
	{
		return std::make_shared<QueenMoveBehavior>();
	}
	if (name == NameOfFigures::Pawn)
	{
		return std::make_shared<PawnMoveBehavior>();
	}
	if (name == NameOfFigures::King)
	{
		return std::make_shared<KingMoveBehavior>();
	}

	return nullptr;
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

void GameBoardConfiguration::createKnights(std::vector<Figure>& figures)
{
	figures.push_back(Figure(NameOfFigures::Knight,
		kKnightWhiteLeftStandartPosition,
		FigureColor::White,
		std::make_shared<KnightBeatBehavior>(),
		std::make_shared<KnightMoveBehavior>()));

	figures.push_back(Figure(NameOfFigures::Knight,
		kKnightWhiteRightStandartPosition,
		FigureColor::White,
		std::make_shared<KnightBeatBehavior>(),
		std::make_shared<KnightMoveBehavior>()));

	figures.push_back(Figure(NameOfFigures::Knight,
		kKnightBlackLeftStandartPosition,
		FigureColor::Black,
		std::make_shared<KnightBeatBehavior>(),
		std::make_shared<KnightMoveBehavior>()));

	figures.push_back(Figure(NameOfFigures::Knight,
		kKnightBlackRightStandartPosition,
		FigureColor::Black,
		std::make_shared<KnightBeatBehavior>(),
		std::make_shared<KnightMoveBehavior>()));
}
