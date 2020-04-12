#include <iostream>

#include "CommandHandler.h"
#include "Game.h"
#include "GameRules.h"
#include "MoveStep.h"
#include "BeatStep.h"
#include "PawnMoveBehavior.h"
#include "CastlingStep.h"
#include "GameBoardConfiguration.h"

const std::string kGameResetMessage = "The game was reset.";
const std::string kGameOverMessage = "The game was over.";
const std::string kEnterCommandMessage = "Enter command: ";
const std::string kHelpMessage = "If you need help /help";
const std::string kWhiteSideMessage = "           White          ";
const std::string kBlackSideMessage = "           Black          ";

const std::string kPositionIsOccupiedMessage = "The position is occupied for move by another figure!";
const std::string kBeatEmptyPositionMessage = "The cell is empty! You should beat something.";
const std::string kWrongPlayerMoveMessage = "Wrong player move!";
const std::string kWrongStepMessage = "Incorrect step!";
const std::string kWrongStepWithCheckMessage = "Incorrect step with check!";
const std::string kMoveEmptyCell = "An attempt to resemble an empty!";

const std::string kIncorrectCastling = "Incorrect castling!";
const std::string kIncorrectFigureForCastling = "Incorrect figure for castling!";
const std::string kFiguresHaveAlreadyChangedPosition = "Figures have already changed position!";

const std::string kIncorrectFigureForTurn = "Incorrect figure for turn!";
const std::string kIncorrectStepForTurn = "Incorrect step for turn!";

const std::string kWhiteWinMessage = "Checkmate! White won!";
const std::string kBlackWinMessage = "Checkmate! Black won!";
const std::string kCongratulations = "Congratulations";

const std::string kStalemateMessage = "Stalemate!";
const std::string kCheckMessage = "Check!";

const std::string kWhiteMoveMessage = "White's move";
const std::string kBlackMoveMessage = "Black's move";

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
	std::cin.ignore();
	while (m_isPlay)
	{
		std::cin.clear();
		std::string command = "/help";

		printGame();

		std::cout << kEnterCommandMessage;
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

void Game::setPriorityOfMove()
{
	if (m_priorityOfMove == FigureColor::White)
	{
		m_priorityOfMove = FigureColor::Black;
	}
	else
	{
		m_priorityOfMove = FigureColor::White;
	}
}

void Game::move(const FigurePosition& whereIs, const FigurePosition& whereTo)
{
	auto whereIsFigure = m_gameBoard.findFigureByPosition(whereIs);
	auto whereToFigure = m_gameBoard.findFigureByPosition(whereTo);

	if (whereIsFigure == m_gameBoard.getFigures().end())
	{
		throw std::runtime_error(kMoveEmptyCell);
	}

	if ((*whereIsFigure).getColor() != m_priorityOfMove)
	{
		throw std::runtime_error(kWrongPlayerMoveMessage);
	}

	if (whereToFigure != m_gameBoard.getFigures().end())
	{
		throw std::runtime_error(kPositionIsOccupiedMessage);
	}

	auto possibleTrace = m_gameBoard.getDependentOnOtherFiguresFigureMoveTrace(*whereIsFigure);

	if (std::find(possibleTrace->begin(), possibleTrace->end(), whereTo) == possibleTrace->end())
	{
		throw std::runtime_error(kWrongStepMessage);
	}

	GameBoard sandBox(m_gameBoard.getFigures());

	sandBox.moveFigure(whereIs, whereTo);

	if (GameRules::isCheck(sandBox, m_priorityOfMove))
	{
		throw std::runtime_error(kWrongStepWithCheckMessage);
	}

	m_gameBoard.moveFigure(whereIs, whereTo);
	m_stepHistory.addStep(std::make_shared<MoveStep>(std::make_shared<Figure>(*whereIsFigure), whereIs, whereTo));

	setPriorityOfMove();

	checkGameRules();
}

bool Game::isBeatenField(const Figure& figure)
{
	if (figure.getName() == NameOfFigures::Pawn && m_stepHistory.getLast()->getMoveFigure()->getName() == NameOfFigures::Pawn)
	{
		auto pawn = m_stepHistory.getLast()->getMoveFigure();
		auto startPosition = m_stepHistory.getLast()->getStartPosition();
		auto endPosition = m_stepHistory.getLast()->getEndPosition();

		if (startPosition.x == endPosition.x && std::abs(static_cast<int>(startPosition.y) - static_cast<int>(endPosition.y)) == PawnSteps::kLong)
		{
			if (endPosition.y == figure.getPosition().y && std::abs(static_cast<int>(endPosition.x) - static_cast<int>(figure.getPosition().x)) == 1)
			{
				return true;
			}
		}
	}

	return false;
}

FigurePosition Game::getBeatenField(const FigurePosition& startPosition, const FigurePosition& endPosition)
{
	auto potentialAttackingCell = endPosition.y > startPosition.y ?
		FigurePosition({ endPosition.x, startPosition.y + 1 }) :
		FigurePosition({ endPosition.x, startPosition.y - 1 });;

	return potentialAttackingCell;
}

void Game::checkGameRules()
{
	if (GameRules::isCheckmate(m_gameBoard, m_priorityOfMove))
	{
		if (m_priorityOfMove != FigureColor::White)
		{
			std::cout << kWhiteWinMessage << std::endl;
			std::cout << kCongratulations << " " << m_firstPlayer.getName() << std::endl;
		}
		else
		{
			std::cout << kBlackWinMessage << std::endl;
			std::cout << kCongratulations << " " << m_firstPlayer.getName() << std::endl;
		}
		finish();

		return;
	}

	if (GameRules::isStalemate(m_gameBoard, m_priorityOfMove))
	{
		std::cout << kStalemateMessage << std::endl;

		finish();

		return;
	}

	if (GameRules::isCheck(m_gameBoard, m_priorityOfMove))
	{
		std::cout << kCheckMessage << std::endl;
	}
}

void Game::beat(const FigurePosition& whereIs, const FigurePosition& whereTo)
{
	auto whereIsFigure = m_gameBoard.findFigureByPosition(whereIs);
	auto whereToFigure = m_gameBoard.findFigureByPosition(whereTo);
	auto isBF = isBeatenField(*whereIsFigure);

	if ((*whereIsFigure).getColor() != m_priorityOfMove)
	{
		throw std::runtime_error(kWrongPlayerMoveMessage);
	}

	if (whereToFigure == m_gameBoard.getFigures().end() && !isBF)
	{
		throw std::runtime_error(kBeatEmptyPositionMessage);
	}

	auto possibleTrace = m_gameBoard.getDependentOnOtherFiguresFigureBeatTrace(*whereIsFigure);

	if (std::find(possibleTrace->begin(), possibleTrace->end(), whereTo) == possibleTrace->end())
	{
		if (!isBF || whereTo != getBeatenField(m_stepHistory.getLast()->getStartPosition(), m_stepHistory.getLast()->getEndPosition()))
		{
			throw std::runtime_error(kWrongStepMessage);
		}
	}

	GameBoard sandBox(m_gameBoard.getFigures());

	if (!isBF)
	{
		sandBox.beatFigure(whereIs, whereTo);

		if (GameRules::isCheck(sandBox, m_priorityOfMove))
		{
			throw std::runtime_error(kWrongStepWithCheckMessage);
		}

		m_stepHistory.addStep(std::make_shared<BeatStep>(std::make_shared<Figure>(*whereIsFigure), 
			std::make_shared<Figure>(*whereToFigure), whereIs, whereTo));

		m_gameBoard.beatFigure(whereIs, whereTo);
	}
	else
	{
		sandBox.moveFigure(whereIs, whereTo);
		auto sandBoxBeatFigure = sandBox.findFigureByPosition({ whereTo.x, whereIs.y });
		sandBox.removeFigure(sandBoxBeatFigure);

		if (GameRules::isCheck(sandBox, m_priorityOfMove))
		{
			throw std::runtime_error(kWrongStepWithCheckMessage);
		}

		auto beatFigure = m_gameBoard.findFigureByPosition({ whereTo.x, whereIs.y });

		m_stepHistory.addStep(std::make_shared<BeatStep>(std::make_shared<Figure>(*whereIsFigure),
			std::make_shared<Figure>(*beatFigure), whereIs, whereTo));

		m_gameBoard.moveFigure(whereIs, whereTo);
		m_gameBoard.removeFigure(beatFigure);
	}

	setPriorityOfMove();

	checkGameRules();
}

void Game::castle(const FigurePosition& whereIs, const FigurePosition& whereTo)
{
	auto whereIsFigure = m_gameBoard.findFigureByPosition(whereIs);
	auto whereToFigure = m_gameBoard.findFigureByPosition(whereTo);

	if (whereIsFigure == m_gameBoard.getFigures().end() || whereToFigure == m_gameBoard.getFigures().end())
	{
		throw std::runtime_error(kIncorrectCastling);
	}

	if ((*whereIsFigure).getColor() != m_priorityOfMove || (*whereToFigure).getColor() != m_priorityOfMove)
	{
		throw std::runtime_error(kIncorrectCastling);
	}

	if ((*whereIsFigure).getName() != NameOfFigures::King || (*whereToFigure).getName() != NameOfFigures::Rook)
	{
		throw std::runtime_error(kIncorrectFigureForCastling);
	}

	if (m_stepHistory.isStep(whereIs) || m_stepHistory.isStep(whereTo))
	{
		throw std::runtime_error(kFiguresHaveAlreadyChangedPosition);
	}

	if (whereIs.x < whereTo.x)
	{
		for (auto x = whereIs.x + 1; x < whereTo.x; ++x)
		{
			if (m_gameBoard.findFigureByPosition({ x, whereIs.y }) != m_gameBoard.getFigures().end())
			{
				throw std::runtime_error(kIncorrectCastling);
			}
		}

		for (auto x = whereIs.x + 1; x < whereTo.x; ++x)
		{
			GameBoard sandbox(m_gameBoard.getFigures());
			sandbox.moveFigure(whereIs, { x, whereIs.y });

			if (GameRules::isCheck(sandbox, whereIsFigure->getColor()))
			{
				throw std::runtime_error(kIncorrectCastling);
			}
		}

		FigurePosition kingNewPosition = { whereIs.x + 2, whereIs.y };
		FigurePosition rookNewPosition = { whereIs.x + 1, whereIs.y };

		m_stepHistory.addStep(std::make_shared<CastlingStep>(
			std::make_shared<Figure>(*whereIsFigure),
			std::make_shared<Figure>(*whereToFigure),
			whereIs,
			kingNewPosition,
			whereTo,
			rookNewPosition));

		m_gameBoard.moveFigure(whereIs, kingNewPosition);
		m_gameBoard.moveFigure(whereTo, rookNewPosition);
	}
	else
	{
		for (auto x = whereIs.x - 1; x > whereTo.x; --x)
		{
			if (m_gameBoard.findFigureByPosition({ x, whereIs.y }) != m_gameBoard.getFigures().end())
			{
				throw std::runtime_error(kIncorrectCastling);
			}
		}

		for (auto x = whereIs.x - 1; x > whereTo.x; --x)
		{
			GameBoard sandbox(m_gameBoard.getFigures());
			sandbox.moveFigure(whereIs, { x, whereIs.y });

			if (GameRules::isCheck(sandbox, whereIsFigure->getColor()))
			{
				throw std::runtime_error(kIncorrectCastling);
			}
		}

		FigurePosition kingNewPosition = { whereIs.x - 2, whereIs.y };
		FigurePosition rookNewPosition = { whereIs.x - 1, whereIs.y };

		m_stepHistory.addStep(std::make_shared<CastlingStep>(
			std::make_shared<Figure>(*whereIsFigure),
			std::make_shared<Figure>(*whereToFigure),
			whereIs,
			kingNewPosition,
			whereTo,
			rookNewPosition));

		m_gameBoard.moveFigure(whereIs, kingNewPosition);
		m_gameBoard.moveFigure(whereTo, rookNewPosition);
	}

	setPriorityOfMove();

	checkGameRules();
}

void Game::turnPawn(const FigurePosition& whereIs, const FigurePosition& whereTo, const std::string& name)
{
	auto whereIsFigure = m_gameBoard.findFigureByPosition(whereIs);
	auto whereToFigure = m_gameBoard.findFigureByPosition(whereTo);

	if (whereIsFigure == m_gameBoard.getFigures().end())
	{
		throw std::runtime_error(kMoveEmptyCell);
	}

	if ((*whereIsFigure).getColor() != m_priorityOfMove)
	{
		throw std::runtime_error(kWrongPlayerMoveMessage);
	}

	if (name == NameOfFigures::King)
	{
		throw std::runtime_error(kIncorrectFigureForTurn);
	}

	if (whereTo.y != (GameBoardConfiguration::kBoardHeight - 1) && whereTo.y != 0)
	{
		throw std::runtime_error(kIncorrectStepForTurn);
	}

	if (whereIsFigure->getName() != NameOfFigures::Pawn)
	{
		throw std::runtime_error(kIncorrectFigureForTurn);
	}

	if (whereToFigure != m_gameBoard.getFigures().end())
	{
		throw std::runtime_error(kPositionIsOccupiedMessage);
	}

	auto possibleTrace = m_gameBoard.getDependentOnOtherFiguresFigureMoveTrace(*whereIsFigure);

	if (std::find(possibleTrace->begin(), possibleTrace->end(), whereTo) == possibleTrace->end())
	{
		throw std::runtime_error(kWrongStepMessage);
	}

	GameBoard sandBox(m_gameBoard.getFigures());

	sandBox.moveFigure(whereIs, whereTo);

	if (GameRules::isCheck(sandBox, m_priorityOfMove))
	{
		throw std::runtime_error(kWrongStepWithCheckMessage);
	}

    auto newBeatBehavior = GameBoardConfiguration::createBeatBehavior(name);
    auto newMoveBehavior = GameBoardConfiguration::createMoveBehavior(name);

	m_gameBoard.moveFigure(whereIs, whereTo);
	m_stepHistory.addStep(std::make_shared<MoveStep>(std::make_shared<Figure>(*whereIsFigure), whereIs, whereTo));

	whereIsFigure->setName(name);
	whereIsFigure->setBeatBehavior(newBeatBehavior);
	whereIsFigure->setMoveBehavior(newMoveBehavior);

	setPriorityOfMove();

	checkGameRules();
}

void Game::printGame() const
{
	std::cout << kWhiteSideMessage << std::endl;
	m_gameBoard.draw();
	std::cout << kBlackSideMessage << std::endl;
	std::cout << kHelpMessage << std::endl;

	if (m_priorityOfMove == FigureColor::White)
	{
		std::cout << kWhiteMoveMessage << std::endl;
	}
	else
	{
		std::cout << kBlackMoveMessage << std::endl;
	}
}
