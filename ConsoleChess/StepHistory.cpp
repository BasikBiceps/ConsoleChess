#include "StepHistory.h"

std::stack<Step>& StepHistory::getSteps()
{
	return m_steps;
}

void StepHistory::addStep(Step& step)
{
	m_steps.push(step);
}

void StepHistory::reset()
{
	while (m_steps.size() != 0)
	{
		m_steps.pop();
	}
}

void StepHistory::undoLastStep(GameBoard& gameBoard)
{
	m_steps.top().undo(gameBoard);
	m_steps.pop();
}
