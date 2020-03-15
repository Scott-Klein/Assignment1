#pragma once
#include "Goal.h"
#include <stack>
#include <queue>
class Solver
{
public:
	Solver(Goal goal, State state, int Steps);
	Solver();
	bool Success();
private:
	priority_queue<Action> legalActions;
	Action lastAction;
	int maxSteps;
	Goal goal;
	State state;
	bool Search();
	bool found;
protected:
};

