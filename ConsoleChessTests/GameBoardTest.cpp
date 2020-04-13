#include "pch.h"
#include "GameBoard.h"
#include "GameBoardConfiguration.h"

TEST(GameBoardTest, addFigure)
{
	GameBoard gb;
	FigurePosition position = { 3,3 };

	EXPECT_EQ(gb.isFigureOnPosition(position), false);

	gb.addFigureOnBoard(Figure("P", position,
		FigureColor::White,
		GameBoardConfiguration::createBeatBehavior("P"),
		GameBoardConfiguration::createMoveBehavior("P")));

	EXPECT_NE(gb.isFigureOnPosition(position), false);
}

TEST(GameBoardTest, removeFigure)
{
	GameBoard gb;
	FigurePosition position = { 3,3 };

	EXPECT_EQ(gb.isFigureOnPosition(position), false);

	gb.addFigureOnBoard(Figure("P", position,
		FigureColor::White,
		GameBoardConfiguration::createBeatBehavior("P"),
		GameBoardConfiguration::createMoveBehavior("P")));

	EXPECT_NE(gb.isFigureOnPosition(position), false);

	gb.removeFigure(gb.findFigureByPosition(position));

	EXPECT_EQ(gb.isFigureOnPosition(position), false);
}

TEST(GameBoardTest, getDependentOnOtherFiguresKnightMoveTrace)
{
	GameBoard gb;
	FigurePosition position = { 1,0 };

	auto trace = gb.getDependentOnOtherFiguresFigureMoveTrace(*(gb.findFigureByPosition(position)));

	EXPECT_EQ(trace->size(), 2);
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 2, 2 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 0, 2 })), trace->end());
}

TEST(GameBoardTest, getDependentOnOtherFiguresQueenMoveTrace)
{
	GameBoard gb;
	FigurePosition position = { 3,0 };

	auto trace = gb.getDependentOnOtherFiguresFigureMoveTrace(*(gb.findFigureByPosition(position)));

	EXPECT_EQ(trace->size(), 0);
}

TEST(GameBoardTest, getDependentOnOtherFiguresKnightBeatTrace)
{
	GameBoard gb;
	FigurePosition position = { 1,0 };

	auto trace = gb.getDependentOnOtherFiguresFigureBeatTrace(*(gb.findFigureByPosition(position)));

	EXPECT_EQ(trace->size(), 0);
}

TEST(GameBoardTest, getDependentOnOtherFiguresQueenBeatTrace)
{
	GameBoard gb;
	FigurePosition position = { 3,0 };

	auto trace = gb.getDependentOnOtherFiguresFigureBeatTrace(*(gb.findFigureByPosition(position)));

	EXPECT_EQ(trace->size(), 0);
}

TEST(GameBoardTest, allPossibleMoveTraces)
{
	GameBoard gb;

	auto whiteTraces = gb.getWhiteFigureMoveTraces();
	auto blackTraces = gb.getBlackFigureMoveTraces();

	EXPECT_EQ(whiteTraces.size(), 20);
	EXPECT_EQ(blackTraces.size(), 20);
}

TEST(GameBoardTest, allPossibleBeatTraces)
{
	GameBoard gb;

	auto whiteTraces = gb.getWhiteFigureBeatTraces();
	auto blackTraces = gb.getBlackFigureBeatTraces();

	EXPECT_EQ(whiteTraces.size(), 0);
	EXPECT_EQ(blackTraces.size(), 0);
}

TEST(GameBoardTest, getKingPosition)
{
	GameBoard gb;

	auto position = gb.getKingPosition(FigureColor::White);

	EXPECT_EQ(position, FigurePosition({4, 0}));
}

TEST(GameBoardTest, moveFigure)
{
	GameBoard gb;
	FigurePosition whereIs = { 1,0 };
	FigurePosition whereTo = { 2,2 };

	EXPECT_EQ(gb.isFigureOnPosition(whereTo), false);

	gb.moveFigure(whereIs, whereTo);

	EXPECT_EQ(gb.isFigureOnPosition(whereIs), false);
	EXPECT_NE(gb.isFigureOnPosition(whereTo), false);
}

TEST(GameBoardTest, beatFigure)
{
	GameBoard gb;
	FigurePosition whereIs = { 1,0 };
	FigurePosition whereTo = { 2,2 };

	gb.addFigureOnBoard(Figure("P", whereTo,
		FigureColor::Black,
		GameBoardConfiguration::createBeatBehavior("P"),
		GameBoardConfiguration::createMoveBehavior("P")));

	EXPECT_NE(gb.isFigureOnPosition(whereTo), false);

	gb.beatFigure(whereIs, whereTo);

	EXPECT_EQ(gb.isFigureOnPosition(whereIs), false);
	EXPECT_NE(gb.isFigureOnPosition(whereTo), false);
	EXPECT_EQ(gb.findFigureByPosition(whereTo)->getColor(), FigureColor::White);
}