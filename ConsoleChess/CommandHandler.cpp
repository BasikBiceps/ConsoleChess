#include <iostream>
#include <sstream>
#include <vector>

#include "CommandHandler.h"

const std::string kIncorrectPositionFormatMessage = "Incorrect position format.";
const std::string kIncorrectStringLengthMessage = "Incorrect string length.";
const std::string kIncorrectNameOfFigureMessage = "Incorrect name of figure!";
const std::string kHelpCommandMessage = " - to show all commands with description;";
const std::string kFinishCommandMessage = " - to finish game and exit;";
const std::string kMoveCommandMessage = " - to move figure (example: " + Commands::move + " b2 b4);";
const std::string kBeatCommandMessage = " - to beat enemy figure (example: " + Commands::beat + " b2 b4);";
const std::string kRestartCommandMessage = " - to restart game;";
const std::string kCastleCommandMessage = " - to castle king (example: " + Commands::castle + " e1 h1);";
const std::string kTurnCommandMessage = " - to turn figure (example: " + Commands::turn + " e7 h8 Q);";

CommandHandler::CommandHandler(Game& game) : m_game(game)
{
}

void CommandHandler::handle(const std::string& command)
{
	std::stringstream sstream(command);
	std::vector<std::string> params;
	std::string param;

	while (sstream >> param)
	{
		params.push_back(param);
	}

	if (params.empty())
	{
		std::cout << Commands::error << std::endl;
		return;
	}

	if (params[0] == Commands::help)
	{
		printCommands();
		return;
	}

	if (params[0] == Commands::finish)
	{
		m_game.finish();
		return;
	}

	if (params[0] == Commands::restart)
	{
		m_game.restart();
		return;
	}

	if (params[0] == Commands::move)
	{
		if (params.size() != (Commands::kMoveParams + 1))
		{
			std::cout << Commands::errorInParams << std::endl;
			return;
		}

		try 
		{
			auto whereIs = convertToFigurePosition(params[1]);
			auto whereTo = convertToFigurePosition(params[2]);

			m_game.move(whereIs, whereTo);
		}
		catch (const std::exception & ex)
		{
			std::cout << ex.what() << std::endl;
		}

		return;
	}

	if (params[0] == Commands::turn)
	{
		if (params.size() != (Commands::kTurnParams + 1))
		{
			std::cout << Commands::errorInParams << std::endl;
			return;
		}

		try
		{
			auto whereIs = convertToFigurePosition(params[1]);
			auto whereTo = convertToFigurePosition(params[2]);

			if (!isNormalNameOfFigure(params[3]))
			{
				std::cout << kIncorrectNameOfFigureMessage << std::endl;
			}
			else
			{
				m_game.turnPawn(whereIs, whereTo, params[3]);
			}
		}
		catch (const std::exception & ex)
		{
			std::cout << ex.what() << std::endl;
		}

		return;
	}

	if (params[0] == Commands::castle)
	{
		if (params.size() != (Commands::kCastleParams + 1))
		{
			std::cout << Commands::errorInParams << std::endl;
			return;
		}

		try
		{
			auto whereIs = convertToFigurePosition(params[1]);
			auto whereTo = convertToFigurePosition(params[2]);

			m_game.castle(whereIs, whereTo);
		}
		catch (const std::exception & ex)
		{
			std::cout << ex.what() << std::endl;
		}

		return;
	}

	if (params[0] == Commands::beat)
	{
		if (params.size() != (Commands::kBeatParams + 1))
		{
			std::cout << Commands::errorInParams << std::endl;
			return;
		}

		try
		{
			auto whereIs = convertToFigurePosition(params[1]);
			auto whereTo = convertToFigurePosition(params[2]);

			m_game.beat(whereIs, whereTo);
		}
		catch (const std::exception & ex)
		{
			std::cout << ex.what() << std::endl;
		}

		return;
	}

	std::cout << Commands::error << std::endl;
	return;
}

void CommandHandler::printCommands() const
{
	std::cout << Commands::help << kHelpCommandMessage << std::endl;
	std::cout << Commands::move << kMoveCommandMessage << std::endl;
	std::cout << Commands::beat << kBeatCommandMessage << std::endl;
	std::cout << Commands::finish << kFinishCommandMessage << std::endl;
	std::cout << Commands::restart << kRestartCommandMessage << std::endl;
	std::cout << Commands::castle << kCastleCommandMessage << std::endl;
	std::cout << Commands::turn << kTurnCommandMessage << std::endl;
}

FigurePosition CommandHandler::convertToFigurePosition(std::string& str)
{
	if (str.length() != 2)
	{
		throw std::runtime_error(kIncorrectStringLengthMessage);
	}

	if (!std::isalpha(str[0]) || !std::isdigit(str[1]))
	{
		throw std::runtime_error(kIncorrectPositionFormatMessage);
	}

	str[0] = std::tolower(str[0]);

	FigurePosition result;
	result.x = str[0] - 'a';
	result.y = str[1] - '0' - 1;

	return result;
}

bool CommandHandler::isNormalNameOfFigure(std::string& name)
{
	if (name.length() != 1)
	{
		throw std::runtime_error(kIncorrectStringLengthMessage);
	}

	if (!std::isalpha(name[0]))
	{
		throw std::runtime_error(kIncorrectPositionFormatMessage);
	}

	name[0] = std::toupper(name[0]);

	return name == NameOfFigures::King ||
		name == NameOfFigures::Bishop ||
		name == NameOfFigures::Knight ||
		name == NameOfFigures::Pawn ||
		name == NameOfFigures::Rook ||
		name == NameOfFigures::Queen;
}
