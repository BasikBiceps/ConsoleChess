#pragma once
#include <stack>

#include "Step.h"
#include "GameBoard.h"

class StepHistory
{
public:
	std::stack<Step>& getSteps();

	void addStep(Step& step);
	void undoLastStep(GameBoard& gameBoard);

private:
	std::stack<Step> m_steps;
};

