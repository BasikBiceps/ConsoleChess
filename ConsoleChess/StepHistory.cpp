#include "StepHistory.h"

std::stack<Step>& StepHistory::getSteps()
{
	return m_steps;
}

void StepHistory::addStep(Step& step)
{
	m_steps.push(step);
}

void StepHistory::undoLastStep(GameBoard& gameBoard)
{
	m_steps.top().undo(gameBoard);
	m_steps.pop();
}
