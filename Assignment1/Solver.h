#pragma once
#include "Goal.h"
#include <stack>
#include <queue>
#include <vector>
class Solver
{
public:
	Solver(Goal goal, State state);
	Solver();
	bool Success();
private:
	Goal goal;
	State state;
	bool Search();
	bool found;
protected:
};

