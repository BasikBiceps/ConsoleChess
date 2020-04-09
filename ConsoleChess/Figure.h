#pragma once
#include <string>
#include <memory>

#include "FigurePosition.h"
#include "IDrawn.h"
#include "IFigureMoveBehavior.h"
#include "FigureColor.h"
#include "IFigureBeatBehavior.h"

namespace NameOfFigures
{
	const std::string Pawn = "P";
	const std::string King = "K";
	const std::string Queen = "Q";
	const std::string Rook = "R";
	const std::string Knight = "N";
	const std::string Bishop = "B";
}

class Figure : public IDrawn
{
public:
	Figure(const std::string& name, 
		   const FigurePosition& position, 
		   const FigureColor& color, 
		   std::shared_ptr<IFigureBeatBehavior> beatBehavior,
		   std::shared_ptr<IFigureMoveBehavior> moveBehavior);
	
	void setPosition(const FigurePosition& position);

	std::shared_ptr<std::vector<FigurePosition>> getMoveTrace() const;
	std::shared_ptr<std::vector<FigurePosition>> getBeatTrace() const;
	const FigurePosition& getPosition() const;

	void draw() const override final;

private:
	std::string m_name;
	FigurePosition m_position;
	FigureColor m_color;
	std::shared_ptr<IFigureMoveBehavior> m_moveBehavior;
	std::shared_ptr<IFigureBeatBehavior> m_beatBehavior;
};
