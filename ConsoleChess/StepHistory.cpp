#include "StepHistory.h"

std::vector<std::shared_ptr<Step>>& StepHistory::getSteps()
{
	return m_steps;
}

bool StepHistory::isStep(const FigurePosition& startPosition)
{
	for (auto step : m_steps)
	{
		if (step->getStartPosition() == startPosition)
		{
			return true;
		}
	}

	return false;
}

std::shared_ptr<Step> StepHistory::getLast()
{
	if (m_steps.size() > 0)
	{
		return m_steps[m_steps.size() - 1];
	}

	return nullptr;
}

void StepHistory::addStep(std::shared_ptr<Step> step)
{
	m_steps.push_back(step);
}

void StepHistory::reset()
{
	m_steps.clear();
}

void StepHistory::undoLastStep(GameBoard& gameBoard)
{
	if (m_steps.size() > 0)
	{
		m_steps[m_steps.size() - 1]->undo(gameBoard);
		m_steps.emplace_back();
	}
}
