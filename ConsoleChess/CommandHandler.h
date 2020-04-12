#pragma once
#include <memory>
#include <string>

#include "Game.h"
#include "ICommandHandler.h"

namespace Commands
{
	const std::string help = "/help";
	const std::string move = "/move";
	const std::string beat = "/beat";
	const std::string restart = "/restart";
	const std::string finish = "/finish";
	const std::string castle = "/castle";
	const std::string turn = "/turn";

	constexpr std::size_t kMoveParams = 2;
	constexpr std::size_t kBeatParams = 2;
	constexpr std::size_t kCastleParams = 2;
	constexpr std::size_t kTurnParams = 3;

	const std::string error = "Incorrect command!";
	const std::string errorInParams = "Incorrect command params!";
}

class CommandHandler : public ICommandHandler
{
public:
	CommandHandler(Game& game);

	void handle(const std::string& command) override;
	void printCommands() const;

private:
	FigurePosition convertToFigurePosition(std::string& str);
	bool isNormalNameOfFigure(std::string& name);

private:
	Game& m_game;
};
