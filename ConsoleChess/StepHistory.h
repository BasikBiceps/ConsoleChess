#pragma once
#include <vector>

#include "Step.h"
#include "GameBoard.h"

class StepHistory
{
public:
	std::vector<std::shared_ptr<Step>>& getSteps();

	bool isStep(const FigurePosition& startPosition);
	std::shared_ptr<Step> getLast();

	void addStep(std::shared_ptr<Step> step);
	void reset();
	void undoLastStep(GameBoard& gameBoard);

private:
	std::vector<std::shared_ptr<Step>> m_steps;
};

