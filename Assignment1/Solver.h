//Refactored once
#pragma once
#include <stack>
#include "Action.h"
#include "State.h"
#include "Options.h"

class Solver
{
public:
	Solver(Options options);

	stack<Action> GetWinningMoves()
	{
		return this->goalPath;
	}

	bool Success();

	void PrintWinningMoves();
private:
	bool Search();

	bool unWindMoves(State* endState);

	Goal* goal;
	State* state;
	stack<Action> goalPath;

	bool found;
};

