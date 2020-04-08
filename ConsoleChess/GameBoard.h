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

	const std::vector<Figure>& getFigures() const;
	
	bool isFigureOnBoard(const FigurePosition& position, const std::string& figureName, FigureColor figurecolor);
	std::shared_ptr<Figure> findFigureByPosition(const FigurePosition& position) const;

	void moveFigure(const FigurePosition& whereIs, const FigurePosition& whereTo);
	void beatFigure(const FigurePosition& whereIs, const FigurePosition& whereTo);

	void draw() const override final;

private:
	std::unique_ptr<std::vector<Figure>> m_figures;
};

