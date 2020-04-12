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

constexpr FigurePosition kBishopWhiteLeftStandardPosition = { 2, 0 };
constexpr FigurePosition kBishopWhiteRightStandardPosition = { 5, 0 };

constexpr FigurePosition kBishopBlackLeftStandardPosition = { 2, 7 };
constexpr FigurePosition kBishopBlackRightStandardPosition = { 5, 7 };

constexpr FigurePosition kRookWhiteLeftStandardPosition = { 0, 0 };
constexpr FigurePosition kRookWhiteRightStandardPosition = { 7, 0 };

constexpr FigurePosition kRookBlackLeftStandardPosition = { 0, 7 };
constexpr FigurePosition kRookBlackRightStandardPosition = { 7, 7 };

constexpr FigurePosition kQueenWhiteStandardPosition = { 3, 0 };
constexpr FigurePosition kQueenBlackStandardPosition = { 3, 7 };

constexpr FigurePosition kKingWhiteStandardPosition = { 4, 0 };
constexpr FigurePosition kKingBlackStandardPosition = { 4, 7 };

constexpr FigurePosition kKnightWhiteLeftStandardPosition = { 1, 0 };
constexpr FigurePosition kKnightWhiteRightStandardPosition = { 6, 0 };

constexpr FigurePosition kKnightBlackLeftStandardPosition = { 1, 7 };
constexpr FigurePosition kKnightBlackRightStandardPosition = { 6, 7 };

std::unique_ptr<std::vector<Figure>> GameBoardConfiguration::getStartFigurePositions()
{
	auto result = std::make_unique<std::vector<Figure>>();

	createPawns(*result);
	createBishops(*result);
	createRooks(*result);
	createQueens(*result);
	createKings(*result);
	createKnights(*result);

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
	figures.emplace_back(NameOfFigures::Rook,
        kRookWhiteLeftStandardPosition,
        FigureColor::White,
        std::make_shared<RookBeatBehavior>(),
        std::make_shared<RookMoveBehavior>());

	figures.emplace_back(NameOfFigures::Rook,
        kRookWhiteRightStandardPosition,
        FigureColor::White,
        std::make_shared<RookBeatBehavior>(),
        std::make_shared<RookMoveBehavior>());

	figures.emplace_back(NameOfFigures::Rook,
        kRookBlackLeftStandardPosition,
        FigureColor::Black,
        std::make_shared<RookBeatBehavior>(),
        std::make_shared<RookMoveBehavior>());

	figures.emplace_back(NameOfFigures::Rook,
        kRookBlackRightStandardPosition,
        FigureColor::Black,
        std::make_shared<RookBeatBehavior>(),
        std::make_shared<RookMoveBehavior>());
}

void GameBoardConfiguration::createBishops(std::vector<Figure>& figures)
{
	figures.emplace_back(NameOfFigures::Bishop,
        kBishopWhiteLeftStandardPosition,
        FigureColor::White,
        std::make_shared<BishopBeatBehavior>(),
        std::make_shared<BishopMoveBehavior>());

	figures.emplace_back(NameOfFigures::Bishop,
        kBishopWhiteRightStandardPosition,
        FigureColor::White,
        std::make_shared<BishopBeatBehavior>(),
        std::make_shared<BishopMoveBehavior>());

	figures.emplace_back(NameOfFigures::Bishop,
        kBishopBlackLeftStandardPosition,
        FigureColor::Black,
        std::make_shared<BishopBeatBehavior>(),
        std::make_shared<BishopMoveBehavior>());

	figures.emplace_back(NameOfFigures::Bishop,
        kBishopBlackRightStandardPosition,
        FigureColor::Black,
        std::make_shared<BishopBeatBehavior>(),
        std::make_shared<BishopMoveBehavior>());
}

void GameBoardConfiguration::createPawns(std::vector<Figure>& figures)
{
	for (std::size_t i = 0; i < kBoardWidth; ++i)
	{
		figures.emplace_back(Figure(NameOfFigures::Pawn,
			{ i,kWhitePawnYStartPosition },
			FigureColor::White,
			std::make_shared<PawnBeatBehavior>(),
			std::make_shared<PawnMoveBehavior>()));
	}

	for (std::size_t i = 0; i < kBoardWidth; ++i)
	{
		figures.emplace_back(Figure(NameOfFigures::Pawn,
			{ i,kBlackPawnYStartPosition },
			FigureColor::Black,
			std::make_shared<PawnBeatBehavior>(),
			std::make_shared<PawnMoveBehavior>()));
	}
}

void GameBoardConfiguration::createQueens(std::vector<Figure>& figures)
{
	figures.emplace_back(Figure(NameOfFigures::Queen,
		kQueenWhiteStandardPosition,
		FigureColor::White,
		std::make_shared<QueenBeatBehavior>(),
		std::make_shared<QueenMoveBehavior>()));

	figures.emplace_back(Figure(NameOfFigures::Queen,
		kQueenBlackStandardPosition,
		FigureColor::Black,
		std::make_shared<QueenBeatBehavior>(),
		std::make_shared<QueenMoveBehavior>()));
}

void GameBoardConfiguration::createKings(std::vector<Figure>& figures)
{
	figures.emplace_back(Figure(NameOfFigures::King,
		kKingWhiteStandardPosition,
		FigureColor::White,
		std::make_shared<KingBeatBehavior>(),
		std::make_shared<KingMoveBehavior>()));

	figures.emplace_back(Figure(NameOfFigures::King,
		kKingBlackStandardPosition,
		FigureColor::Black,
		std::make_shared<KingBeatBehavior>(),
		std::make_shared<KingMoveBehavior>()));
}

void GameBoardConfiguration::createKnights(std::vector<Figure>& figures)
{
	figures.emplace_back(Figure(NameOfFigures::Knight,
		kKnightWhiteLeftStandardPosition,
		FigureColor::White,
		std::make_shared<KnightBeatBehavior>(),
		std::make_shared<KnightMoveBehavior>()));

	figures.emplace_back(Figure(NameOfFigures::Knight,
		kKnightWhiteRightStandardPosition,
		FigureColor::White,
		std::make_shared<KnightBeatBehavior>(),
		std::make_shared<KnightMoveBehavior>()));

	figures.emplace_back(Figure(NameOfFigures::Knight,
		kKnightBlackLeftStandardPosition,
		FigureColor::Black,
		std::make_shared<KnightBeatBehavior>(),
		std::make_shared<KnightMoveBehavior>()));

	figures.emplace_back(Figure(NameOfFigures::Knight,
		kKnightBlackRightStandardPosition,
		FigureColor::Black,
		std::make_shared<KnightBeatBehavior>(),
		std::make_shared<KnightMoveBehavior>()));
}
