#include "pch.h"
#include "GameBoard.h"
#include "GameBoardConfiguration.h"
#include "GameRules.h"

TEST(GameRulesTestCheck, isCheckTrue)
{
    std::vector<Figure> figures;
    figures.push_back(Figure("K",
        { 4,0 },
        FigureColor::White,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    figures.push_back(Figure("R",
        { 7,0 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("R"),
        GameBoardConfiguration::createMoveBehavior("R")));

    figures.push_back(Figure("K",
        { 4,7 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    GameBoard gameBoard(figures);

    EXPECT_EQ(GameRules::isCheck(gameBoard, FigureColor::White), true);
}

TEST(GameRulesTestCheck, isCheckFalse)
{
    std::vector<Figure> figures;
    figures.push_back(Figure("K",
        { 4,0 },
        FigureColor::White,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    figures.push_back(Figure("R",
        { 5,0 },
        FigureColor::White,
        GameBoardConfiguration::createBeatBehavior("R"),
        GameBoardConfiguration::createMoveBehavior("R")));

    figures.push_back(Figure("R",
        { 7,0 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("R"),
        GameBoardConfiguration::createMoveBehavior("R")));

    figures.push_back(Figure("K",
        { 4,7 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    GameBoard gameBoard(figures);

    EXPECT_EQ(GameRules::isCheck(gameBoard, FigureColor::White), false);
}

TEST(GameRulesTestCheckmate, isCheckmateTrue)
{
    std::vector<Figure> figures;
    figures.push_back(Figure("K",
        { 4,0 },
        FigureColor::White,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    figures.push_back(Figure("R",
        { 6,0 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("R"),
        GameBoardConfiguration::createMoveBehavior("R")));

    figures.push_back(Figure("R",
        { 7,1 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("R"),
        GameBoardConfiguration::createMoveBehavior("R")));

    figures.push_back(Figure("K",
        { 4,7 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    GameBoard gameBoard(figures);

    EXPECT_EQ(GameRules::isCheckmate(gameBoard, FigureColor::White), true);
}

TEST(GameRulesTestCheckmate, isCheckmateFalse)
{
    std::vector<Figure> figures;
    figures.push_back(Figure("K",
        { 4,0 },
        FigureColor::White,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    figures.push_back(Figure("R",
        { 5,0 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("R"),
        GameBoardConfiguration::createMoveBehavior("R")));

    figures.push_back(Figure("R",
        { 7,1 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("R"),
        GameBoardConfiguration::createMoveBehavior("R")));

    figures.push_back(Figure("K",
        { 4,7 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    GameBoard gameBoard(figures);

    EXPECT_EQ(GameRules::isCheckmate(gameBoard, FigureColor::White), false);
}

TEST(GameRulesTestStalemate, isStalemateTrue)
{
    std::vector<Figure> figures;
    figures.push_back(Figure("K",
        { 4,0 },
        FigureColor::White,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    figures.push_back(Figure("R",
        { 5,3 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("R"),
        GameBoardConfiguration::createMoveBehavior("R")));

    figures.push_back(Figure("R",
        { 3,3 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("R"),
        GameBoardConfiguration::createMoveBehavior("R")));

    figures.push_back(Figure("R",
        { 7,1 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("R"),
        GameBoardConfiguration::createMoveBehavior("R")));

    figures.push_back(Figure("K",
        { 4,7 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    GameBoard gameBoard(figures);

    EXPECT_EQ(GameRules::isStalemate(gameBoard, FigureColor::White), true);
}

TEST(GameRulesTestStalemate, isStalemateFalse)
{
    std::vector<Figure> figures;
    figures.push_back(Figure("K",
        { 4,0 },
        FigureColor::White,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    figures.push_back(Figure("R",
        { 5,3 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("R"),
        GameBoardConfiguration::createMoveBehavior("R")));

    figures.push_back(Figure("R",
        { 3,0 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("R"),
        GameBoardConfiguration::createMoveBehavior("R")));

    figures.push_back(Figure("R",
        { 7,1 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("R"),
        GameBoardConfiguration::createMoveBehavior("R")));

    figures.push_back(Figure("K",
        { 4,7 },
        FigureColor::Black,
        GameBoardConfiguration::createBeatBehavior("K"),
        GameBoardConfiguration::createMoveBehavior("K")));

    GameBoard gameBoard(figures);

    EXPECT_EQ(GameRules::isStalemate(gameBoard, FigureColor::White), false);
}