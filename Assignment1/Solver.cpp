#include "Solver.h"

Solver::Solver(Goal goal, State state, int Steps)
{
	this->maxSteps = Steps;
	this->goal = goal;

	this->found = Search();
}

Solver::Solver()
{
	//TODO: Implement input gathering
}

bool Solver::Success()
{
	int steps = this->maxSteps;
	while (steps > 0 && !this->goal.Accomplished(this->state))
	{

	}
	return this->found;
}

bool Solver::Search()
{

	return false;
}

