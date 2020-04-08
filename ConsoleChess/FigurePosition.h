#pragma once
#include <cstddef>

struct FigurePosition
{
	std::size_t x;
	std::size_t y;

	bool operator == (const FigurePosition& right)
	{
		return x == right.x && y == right.y;
	}
};
