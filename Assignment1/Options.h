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
		goal = Goal(Numbers, Size, Type);
	}

	State* GetState()
	{
		return initialState;
	}
	Goal GetGoal()
	{
		return goal;
	}

private:
	Goal goal;
	int Size;
	int Numbers;
	SolverType Type;
	State* initialState;
	void QueryType();
	void QueryNumbers();
	void QuerySize();
	bool ValidateOptions();
	void PrintOptions();
};

