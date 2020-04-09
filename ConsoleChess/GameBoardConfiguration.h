#pragma once
#include <memory>
#include <vector>
#include <string>

#include "Figure.h"

class GameBoardConfiguration
{
public:
	static std::unique_ptr<std::vector<Figure>> getStartFigurePositions();
	static std::string getBoardPanel();
	static std::string getCellSeparator();
	static std::string getLineSeparator();
	static std::string getEmptyCell();

	static const std::size_t kBoardWidth = 8;
	static const std::size_t kBoardHeight = 8;
};

namespace BoardBorders {
	constexpr std::size_t kXLeftEndPosition = 0;
	constexpr std::size_t kXRightEndPosition = GameBoardConfiguration::kBoardWidth - 1;
	constexpr std::size_t kWhiteYEndPosition = GameBoardConfiguration::kBoardHeight - 1;
	constexpr std::size_t kBlackYEndPosition = 0;
};