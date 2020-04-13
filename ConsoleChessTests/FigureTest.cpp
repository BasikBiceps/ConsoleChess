#include "pch.h"
#include "Figure.h"
#include "GameBoardConfiguration.h"

TEST(FigureTestPawn, pawnMoveBehavior)
{
	std::string name = "P";
	Figure figure(name, {1,1}, 
		FigureColor::White, 
		GameBoardConfiguration::createBeatBehavior(name), 
		GameBoardConfiguration::createMoveBehavior(name));

	auto trace = figure.getMoveTrace();

	EXPECT_EQ(trace->size(), 2);
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 1, 2 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 1, 3 })), trace->end());
}

TEST(FigureTestPawn, pawnBeatBehavior)
{
	std::string name = "P";
	Figure figure(name, { 1,1 },
		FigureColor::White,
		GameBoardConfiguration::createBeatBehavior(name),
		GameBoardConfiguration::createMoveBehavior(name));

	auto trace = figure.getBeatTrace();

	EXPECT_EQ(trace->size(), 2);
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 2, 2 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 0, 2 })), trace->end());
}

TEST(FigureTestRook, rookMoveBehavior)
{
	std::string name = "R";
	Figure figure(name, { 0,0 },
		FigureColor::White,
		GameBoardConfiguration::createBeatBehavior(name),
		GameBoardConfiguration::createMoveBehavior(name));

	auto trace = figure.getMoveTrace();

	EXPECT_EQ(trace->size(), 14);
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 0, 7 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 7, 0 })), trace->end());
}

TEST(FigureTestRook, rookBeatBehavior)
{
	std::string name = "R";
	Figure figure(name, { 3, 3},
		FigureColor::White,
		GameBoardConfiguration::createBeatBehavior(name),
		GameBoardConfiguration::createMoveBehavior(name));

	auto trace = figure.getBeatTrace();

	EXPECT_EQ(trace->size(), 14);
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 7, 3 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 3, 0 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 0, 3 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 3, 7 })), trace->end());
}

TEST(FigureTestBishop, bishopMoveBehavior)
{
	std::string name = "B";
	Figure figure(name, { 3,3 },
		FigureColor::White,
		GameBoardConfiguration::createBeatBehavior(name),
		GameBoardConfiguration::createMoveBehavior(name));

	auto trace = figure.getMoveTrace();

	EXPECT_EQ(trace->size(), 13);
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 0, 0 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 7, 7 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 6, 0 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 0, 6 })), trace->end());
}

TEST(FigureTestBishop, bishopBeatBehavior)
{
	std::string name = "B";
	Figure figure(name, { 7, 0 },
		FigureColor::White,
		GameBoardConfiguration::createBeatBehavior(name),
		GameBoardConfiguration::createMoveBehavior(name));

	auto trace = figure.getBeatTrace();

	EXPECT_EQ(trace->size(), 7);
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 0, 7 })), trace->end());
}

TEST(FigureTestKnight, knightMoveBehavior)
{
	std::string name = "N";
	Figure figure(name, { 3,3 },
		FigureColor::White,
		GameBoardConfiguration::createBeatBehavior(name),
		GameBoardConfiguration::createMoveBehavior(name));

	auto trace = figure.getMoveTrace();

	EXPECT_EQ(trace->size(), 8);
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 4, 1 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 2, 1 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 1, 2 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 5, 2 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 1, 4 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 2, 5 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 4, 5 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 5, 4 })), trace->end());
}

TEST(FigureTestKnight, knightBeatBehavior)
{
	std::string name = "N";
	Figure figure(name, { 0, 0 },
		FigureColor::White,
		GameBoardConfiguration::createBeatBehavior(name),
		GameBoardConfiguration::createMoveBehavior(name));

	auto trace = figure.getBeatTrace();

	EXPECT_EQ(trace->size(), 2);
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 2, 1 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 1, 2 })), trace->end());
}

TEST(FigureTestKing, kingMoveBehavior)
{
	std::string name = "K";
	Figure figure(name, { 3,3 },
		FigureColor::White,
		GameBoardConfiguration::createBeatBehavior(name),
		GameBoardConfiguration::createMoveBehavior(name));

	auto trace = figure.getMoveTrace();

	EXPECT_EQ(trace->size(), 8);
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 3, 4 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 4, 3 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 4, 4 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 2, 2 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 2, 4 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 4, 2 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 3, 2 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 2, 3 })), trace->end());
}

TEST(FigureTestKing, kingBeatBehavior)
{
	std::string name = "K";
	Figure figure(name, { 0, 0 },
		FigureColor::White,
		GameBoardConfiguration::createBeatBehavior(name),
		GameBoardConfiguration::createMoveBehavior(name));

	auto trace = figure.getBeatTrace();

	EXPECT_EQ(trace->size(), 3);
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 1, 0 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 1, 1 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 0, 1 })), trace->end());
}

TEST(FigureTestQueen, queenMoveBehavior)
{
	std::string name = "Q";
	Figure figure(name, { 3,3 },
		FigureColor::White,
		GameBoardConfiguration::createBeatBehavior(name),
		GameBoardConfiguration::createMoveBehavior(name));

	auto trace = figure.getMoveTrace();

	EXPECT_EQ(trace->size(), 27);
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 7, 3 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 0, 3 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 3, 0 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 3, 7 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 6, 0 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 0, 6 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 0, 0 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 7, 7 })), trace->end());
}

TEST(FigureTestQueen, QueenBeatBehavior)
{
	std::string name = "Q";
	Figure figure(name, { 0, 0 },
		FigureColor::White,
		GameBoardConfiguration::createBeatBehavior(name),
		GameBoardConfiguration::createMoveBehavior(name));

	auto trace = figure.getBeatTrace();

	EXPECT_EQ(trace->size(), 21);
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 7, 7 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 7, 0 })), trace->end());
	EXPECT_NE(std::find(trace->begin(), trace->end(), FigurePosition({ 0, 7 })), trace->end());
}