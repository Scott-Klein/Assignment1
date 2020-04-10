#pragma once
#include "Goal.h"
#include <stack>
#include <queue>
#include <vector>
#include "State.h"
#include "Action.h"
#include "Node.h"

class Solver
{
public:
	Solver(Goal goal, State* state);
	Solver();
	bool Success();
	stack<Action> GetWinningMoves()
	{
		return this->goalPath;
	}
private:
	Goal goal;
	State* state;
	stack<Action> goalPath;
	bool Search();
	bool found;
	bool unWindMoves(State* endState);
protected:
};

