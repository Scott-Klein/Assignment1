#pragma once
#include "Goal.h"
class Solver
{
public:
	Solver(Goal goal, State state, int Steps);
	Solver();
	bool Success();
private:

	int maxSteps;
	Goal goal;
	State state;
	bool Search();
	bool found;
protected:
};

