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

