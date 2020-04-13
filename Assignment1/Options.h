//Refactored once
#pragma once
#include "State.h"
#include "Goal.h"
#include "SolverType.h"

class Options
{
public:
	Options()
	{
		while (!ValidateOptions())
		{
			QueryType();
			QueryNumbers();
			QuerySize();
		}
		initialState = new State(Size, Numbers);
		goal = new Goal(Numbers, Size, Type);
	}
	State* GetState()
	{
		return initialState;
	}

	Goal* GetGoal()
	{
		return goal;
	}
private:
	void QueryType();
	void QueryNumbers();
	void QuerySize();

	void PrintOptions();

	bool ValidateOptions();

	int Size;
	int Numbers;
	SolverType Type;
	State* initialState;
	Goal* goal;
};

