#include "pch.h"
#include "Game.h"
#include "GameBoardConfiguration.h"

TEST(GameTestMove, IncorrectPlayer)
{
  Game game(Player("test", FigureColor::White), Player("test", FigureColor::Black));
  
  EXPECT_THROW(game.move({ 0, 6 }, { 0, 5 }), std::runtime_error);
}

TEST(GameTestMove, EmptyCell)
{
    Game game(Player("test", FigureColor::White), Player("test", FigureColor::Black));

    EXPECT_THROW(game.move({ 0, 5 }, { 0, 4 }), std::runtime_error);
}

TEST(GameTestMove, IncorrectStep)
{
    Game game(Player("test", FigureColor::White), Player("test", FigureColor::Black));

    EXPECT_THROW(game.move({ 1, 0 }, { 1, 1 }), std::runtime_error);
}

TEST(GameTestMove, CorrectStep)
{
    Game game(Player("test", FigureColor::White), Player("test", FigureColor::Black));

    EXPECT_NO_THROW(game.move({ 1, 1 }, { 1, 2 }));
    EXPECT_NO_THROW(game.move({ 6, 6 }, { 6, 4 }));
}

TEST(GameTestBeat, IncorrectStep)
{
    Game game(Player("test", FigureColor::White), Player("test", FigureColor::Black));

    EXPECT_THROW(game.beat({ 1, 1 }, { 1, 2 }), std::runtime_error);
}

TEST(GameTestBeat, WithoutEnemy)
{
    Game game(Player("test", FigureColor::White), Player("test", FigureColor::Black));

    EXPECT_THROW(game.beat({ 1, 1 }, { 2, 2 }), std::runtime_error);
}

TEST(GameTestBeat, IncorrectPlayer)
{
    Game game(Player("test", FigureColor::White), Player("test", FigureColor::Black));

    EXPECT_THROW(game.beat({ 1, 7 }, { 3, 6 }), std::runtime_error);
}

TEST(GameTestBeat, CorrectStep)
{
    Game game(Player("test", FigureColor::White), Player("test", FigureColor::Black));

    EXPECT_NO_THROW(game.move({ 3, 1 }, { 3, 3 }));
    EXPECT_NO_THROW(game.move({ 4, 6 }, { 4, 4 }));
    EXPECT_NO_THROW(game.beat({ 3, 3 }, { 4, 4 }));
}

TEST(GameTestCastle, CorrectStep)
{
    std::vector<Figure> figures;
    figures.push_back(Figure("K",
        {4,0},
        FigureColor::White,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    figures.push_back(Figure("K",
        { 4,7 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    figures.push_back(Figure("R",
        {7,0},
        FigureColor::White,
        GameBoardConfiguration::createBeatBehavior("R"),
        GameBoardConfiguration::createMoveBehavior("R")));
    
    Game game(Player("test", FigureColor::White), Player("test", FigureColor::Black), GameBoard(figures));

    EXPECT_NO_THROW(game.castle({ 4, 0 }, { 7, 0 }));
}

TEST(GameTestCastle, incorrectStepWithCheck)
{
    std::vector<Figure> figures;
    figures.push_back(Figure("K",
        { 4,0 },
        FigureColor::White,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    figures.push_back(Figure("R",
        { 7,0 },
        FigureColor::White,
        GameBoardConfiguration::createBeatBehavior("R"),
        GameBoardConfiguration::createMoveBehavior("R")));

    figures.push_back(Figure("K",
        { 4,7 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    figures.push_back(Figure("R",
        { 6,7 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("R"),
        GameBoardConfiguration::createMoveBehavior("R")));

    Game game(Player("test", FigureColor::White), Player("test", FigureColor::Black), GameBoard(figures));

    EXPECT_THROW(game.castle({ 4, 0 }, { 7, 0 }), std::runtime_error);
}

TEST(GameTestTurnPawn, correctStep)
{
    std::vector<Figure> figures;
    figures.push_back(Figure("K",
        { 4,0 },
        FigureColor::White,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    figures.push_back(Figure("P",
        { 7,6 },
        FigureColor::White,
        GameBoardConfiguration::createBeatBehavior("P"),
        GameBoardConfiguration::createMoveBehavior("P")));

    figures.push_back(Figure("K",
        { 4,2 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    Game game(Player("test", FigureColor::White), Player("test", FigureColor::Black), GameBoard(figures));

    EXPECT_NO_THROW(game.turnPawn({ 7, 6 }, { 7, 7 }, "Q"), std::runtime_error);
}

TEST(GameTestTurnPawn, incorrectStepWithCheck)
{
    std::vector<Figure> figures;
    figures.push_back(Figure("K",
        { 7,6 },
        FigureColor::White,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    figures.push_back(Figure("P",
        { 6,6 },
        FigureColor::White,
        GameBoardConfiguration::createBeatBehavior("P"),
        GameBoardConfiguration::createMoveBehavior("P")));

    figures.push_back(Figure("R",
        { 1,6 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("R"),
        GameBoardConfiguration::createMoveBehavior("R")));

    figures.push_back(Figure("K",
        { 4,2 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    Game game(Player("test", FigureColor::White), Player("test", FigureColor::Black), GameBoard(figures));

    EXPECT_THROW(game.turnPawn({ 6, 6 }, { 6, 7 }, "Q"), std::runtime_error);
}