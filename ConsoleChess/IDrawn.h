#pragma once
#include <cstddef>

class IDrawn
{
public:
	virtual void draw() const = 0;
	virtual std::size_t getPixelWidth() const = 0;
	virtual std::size_t getPixelHeight() const = 0;
};