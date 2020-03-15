#include "Solver.h"
#include <iostream>

using namespace std;

Solver::Solver(Goal goal, State state, int Steps)
{
	this->state = state;
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
	int steps = 0;
	cout << "Starting search" << endl;
	while (steps++ < this->maxSteps && !this->goal.Accomplished(this->state))
	{
		this->legalActions = this->state.GetLegalActionPriorityQueue();
		Action top = this->legalActions.top();
		cout << "Step: " << steps << ", ";
		top.PrintMove();
		this->state = State(&this->state, this->legalActions.top());
		this->state.Print();
	}
	if (this->goal.Accomplished(this->state))
	{
		cout << "Found the goal in " << steps << " steps " << endl;
		return true;
	}
	cout << "Found nothing after " << maxSteps << endl;
	return false;
}

