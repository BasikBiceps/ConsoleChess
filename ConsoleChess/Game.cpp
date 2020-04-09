#include <iostream>

#include "CommandHandler.h"
#include "Game.h"

const std::string kGameResetMessage = "The game was reset.";
const std::string kGameOverMessage = "The game was over.";
const std::string kEnterCommandMessage = "Enter command: ";
const std::string kHelpMessage = "If you need help /help";
const std::string kWhiteSideMessage = "           White          ";
const std::string kBlackSideMessage = "           Black          ";

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
		std::cin.clear();
		std::string command = "/help";

		std::cout << kWhiteSideMessage << std::endl;
		m_gameBoard.draw();
 		std::cout << kBlackSideMessage << std::endl;

		std::cout << kHelpMessage << std::endl;
		std::cout << kEnterCommandMessage;
		std::cin.ignore();
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
	std::cout << kGameResetMessage << std::endl;
}

void Game::finish()
{
	m_isPlay = false;
	std::cout << kGameOverMessage << std::endl;
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
