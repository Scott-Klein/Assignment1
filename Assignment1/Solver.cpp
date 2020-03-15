#include "Solver.h"
#include <iostream>

using namespace std;

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
	return this->found;
}

bool Solver::Search()
{
	int steps = this->maxSteps;
	while (steps-- > 0 && !this->goal.Accomplished(this->state))
	{
		this->legalActions = this->state.GetLegalActionPriorityQueue();


		this->state = State(&this->state, legalActions.top());
		this->state.Print();
	}
	if (this->goal.Accomplished(this->state))
	{
		cout << "Found the goal in " << (maxSteps - steps) << " steps " << endl;
		return true;
	}
	cout << "Found nothing after " << maxSteps << endl;
	return false;
}

