#pragma once
#include <vector>
#include <memory>

#include "IDrawn.h"
#include "Figure.h"
#include "FigureColor.h"

class GameBoard : public IDrawn
{
public:
	GameBoard();
	GameBoard(std::unique_ptr<std::vector<Figure>> figures);

	void addFigureOnBoard(Figure& figure);

	const std::vector<Figure>& getFigures() const;
	
	std::vector<Figure>::iterator findFigureByPosition(const FigurePosition& position);
	std::vector<Figure>::const_iterator findFigureByPosition(const FigurePosition& position) const;

	void moveFigure(const FigurePosition& whereIs, const FigurePosition& whereTo);
	void beatFigure(const FigurePosition& whereIs, const FigurePosition& whereTo);

	void draw() const override final;
	void reset();

	void removeFigure(std::vector<Figure>::iterator elementIter);

private:
	std::unique_ptr<std::vector<Figure>> m_figures;
};
