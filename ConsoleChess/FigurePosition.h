#pragma once
#include <cstddef>

struct FigurePosition
{
	std::size_t x;
	std::size_t y;

	bool operator == (const FigurePosition& other) const
	{
		return x == other.x && y == other.y;
	}

	bool operator != (const FigurePosition& other) const
	{
		return !(*this == other);
	}
};
