#pragma once

#include "GameBoard.h"
#include "StepHistory.h"
#include "Player.h"

class Game
{
public:
	Game(const Player& firstPlayer, const Player& secondPlayer);

	void start();
	void finish();

private:
	GameBoard m_gameBoard;
	StepHistory m_stepHistory;
	Player m_firstPlayer;
	Player m_secondPlayer;
};

