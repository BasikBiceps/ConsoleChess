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
	GameBoard(const std::vector<Figure>& figures);

	void addFigureOnBoard(Figure& figure);

	const std::vector<Figure>& getFigures() const;
	std::shared_ptr<std::vector<FigurePosition>> getDependentOnOtherFiguresFigureMoveTrace(const Figure& figure) const;
	std::shared_ptr<std::vector<FigurePosition>> getDependentOnOtherFiguresFigureBeatTrace(const Figure& figure) const;
	const std::vector<FigurePosition>& getWhiteFigureMoveTraces() const;
	const std::vector<FigurePosition>& getBlackFigureMoveTraces() const;
	const std::vector<FigurePosition>& getWhiteFigureBeatTraces() const;
	const std::vector<FigurePosition>& getBlackFigureBeatTraces() const;
	const FigurePosition& getKingPosition(const FigureColor& color) const;
	
	std::vector<Figure>::iterator findFigureByPosition(const FigurePosition& position);
	std::vector<Figure>::const_iterator findFigureByPosition(const FigurePosition& position) const;

	void moveFigure(const FigurePosition& whereIs, const FigurePosition& whereTo);
	void beatFigure(const FigurePosition& whereIs, const FigurePosition& whereTo);

	void draw() const override final;
	void reset();
	void updateFigureTraces();

	bool isValidPosition(const FigurePosition& position) const;
	bool isFigureOnPosition(const FigurePosition& position) const;
	bool isFigureOnTrace(const FigurePosition& whereIs, const FigurePosition& whereTo) const;

	void removeFigure(std::vector<Figure>::iterator elementIter);

private:
	bool isFigureOnVertical(const FigurePosition& whereIs, const FigurePosition& whereTo) const;
	bool isFigureOnHorizontal(const FigurePosition& whereIs, const FigurePosition& whereTo) const;
	bool isFigureOnDiagonal(const FigurePosition& whereIs, const FigurePosition& whereTo) const;

	void updateMoveFigureTraces();
	void updateBeatFigureTraces();

private:
	std::unique_ptr<std::vector<Figure>> m_figures;
	std::vector<FigurePosition> m_whiteFigureMoveTraces;
	std::vector<FigurePosition> m_blackFigureMoveTraces;
	std::vector<FigurePosition> m_whiteFigureBeatTraces;
	std::vector<FigurePosition> m_blackFigureBeatTraces;
};
