#pragma once
#include "FigurePosition.h"
#include "IDrawn.h"
#include "IFigureMoveBehavior.h"
#include "FigureColor.h"
#include "IFigureBeatBehavior.h"

#include <string>
#include <memory>

class Figure : public IDrawn
{
public:
	Figure(const std::string& name, 
		   const FigurePosition& position, 
		   const FigureColor& color, 
		   std::shared_ptr<IFigureBeatBehavior> beatBehavior,
		   std::shared_ptr<IFigureMoveBehavior> moveBehavior);

	bool move(const FigurePosition& whereTo) const;
	bool beat(const FigurePosition& whereTo) const;

	void draw() const override final;
	std::size_t getPixelWidth() const override final;
	std::size_t getPixelHeight() const override final;

private:
	std::string m_name;
	FigurePosition m_position;
	FigureColor m_color;
	std::shared_ptr<IFigureMoveBehavior> m_moveBehavior;
	std::shared_ptr<IFigureBeatBehavior> m_beatBehavior;
};
