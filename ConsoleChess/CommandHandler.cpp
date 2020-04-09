#include <iostream>
#include <sstream>
#include <vector>

#include "CommandHandler.h"

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
	std::cout << Commands::help << " - to show all commands with description;" << std::endl;
	std::cout << Commands::move << " - to move figure (example: " << Commands::move << " b2 b4);" << std::endl;
	std::cout << Commands::beat << " - to beat enemy figure (example: " << Commands::beat << " b2 b4);" << std::endl;
	std::cout << Commands::finish << " - to finish game and exit;" << std::endl;
	std::cout << Commands::restart << " - to restart game;" << std::endl;
}

FigurePosition CommandHandler::convertToFigurePosition(std::string& str)
{
	if (str.length() != 2)
	{
		throw std::runtime_error("Incorrect position string length.");
	}

	if (!std::isalpha(str[0]) || !std::isdigit(str[1]))
	{
		throw std::runtime_error("Incorrect position format.");
	}

	str[0] = std::tolower(str[0]);

	FigurePosition result;
	result.x = str[0] - 'a';
	result.y = str[1] - '0' - 1;

	return result;
}
