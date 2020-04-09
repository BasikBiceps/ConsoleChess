#include <iostream>

#include "CommandHandler.h"
#include "Game.h"

Game::Game(const Player& firstPlayer, const Player& secondPlayer) :
	m_firstPlayer(firstPlayer),
	m_secondPlayer(secondPlayer),
	m_isPlay(true),
	m_priorityOfMove(FigureColor::White),
	m_commandHandler(std::make_unique<CommandHandler>(*this))
{
}

GameBoard& Game::getGameBoard()
{
	return m_gameBoard;
}

StepHistory& Game::getStepHistory()
{
	return m_stepHistory;
}

FigureColor& Game::getFigureColor()
{
	return m_priorityOfMove;
}

void Game::start()
{
	while (m_isPlay)
	{
		std::string command;

		std::cout << "           White          " << std::endl;
		m_gameBoard.draw();
		std::cout << "           Black          " << std::endl;

		std::cout << "If you need help /help" << std::endl;
		std::cout << "Enter command: ";
		std::getline(std::cin, command);

		m_commandHandler->handle(command);

		system("pause");
		system("cls");
	}
}

void Game::restart()
{
	m_gameBoard.reset();
	m_stepHistory.reset();
	m_priorityOfMove = FigureColor::White;
	std::cout << "The game was reset." << std::endl;
}

void Game::finish()
{
	m_isPlay = false;
	std::cout << "The game was over." << std::endl;
}

void Game::move(FigurePosition& whereIs, FigurePosition& whereTo)
{
	std::cout << whereIs.x << " " << whereIs.y << std::endl;
	std::cout << whereTo.x << " " << whereTo.y << std::endl;
}

void Game::beat(FigurePosition& whereIs, FigurePosition& whereTo)
{
	std::cout << whereIs.x << " " << whereIs.y << std::endl;
	std::cout << whereTo.x << " " << whereTo.y << std::endl;
}
