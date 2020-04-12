#pragma once
#include <memory>

#include "ICommandHandler.h"
#include "GameBoard.h"
#include "StepHistory.h"
#include "Player.h"

class Game
{
public:
	Game(const Player& firstPlayer, const Player& secondPlayer);

	GameBoard& getGameBoard();
	StepHistory& getStepHistory();
	FigureColor& getFigureColor();

	void start();
	void restart();
	void finish();
	void setPriorityOfMove();

	void move(const FigurePosition& whereIs, const FigurePosition& whereTo);
	void beat(const FigurePosition& whereIs, const FigurePosition& whereTo);
	void castle(const FigurePosition& whereIs, const FigurePosition& whereTo);

private:
	void printGame() const;
	bool isBeatenField(const Figure& figure);
	FigurePosition getBeatenField(const FigurePosition& startPosition, const FigurePosition& endPosition);
	void checkGameRules();

private:
	std::unique_ptr<ICommandHandler> m_commandHandler;
	GameBoard m_gameBoard;
	StepHistory m_stepHistory;
	Player m_firstPlayer;
	Player m_secondPlayer;
	FigureColor m_priorityOfMove;
	bool m_isPlay;
};

