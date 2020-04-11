#pragma once
#include "SolverType.h"
#include "Goal.h"
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
		goal = Goal(Numbers, Size);
	}
	void QueryType();
	void QueryNumbers();
	void QuerySize();
	bool ValidateOptions();
private:
	Goal goal;
	int Size;
	int Numbers;
	SolverType Type;

	void PrintOptions();
};

