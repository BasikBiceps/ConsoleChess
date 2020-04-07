#pragma once

class IDrawn
{
public:
	virtual void draw() = 0;
	virtual void getPixelWidth() = 0;
	virtual void getPixelHeight() = 0;
};