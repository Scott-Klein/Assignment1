#pragma once
#include <stack>
#include "Action.h"
#include "State.h"
#include "Options.h"

class Solver
{
public:
	Solver(Options options);

	bool Success();

	stack<Action> GetWinningMoves()
	{
		return this->goalPath;
	}
	void PrintWinningMoves();
private:
	Goal goal;
	State* state;
	stack<Action> goalPath;
	bool Search();
	bool found;
	bool unWindMoves(State* endState);
	
protected:
};

