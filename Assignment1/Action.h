#pragma once
//#include "State.h"

class Action
{
private:
	int colFrom;
	int colTo;
public:
	Action(int from = -1, int to = -1)
	{
		this->colFrom = from;
		this->colTo = to;

	}

	bool operator== (const Action &rhs);
	bool operator!= (const Action &rhs);
	bool IsInverseAction(Action action);
	int GetFrom();
	int GetTo();
	void PrintMove();
	bool Empty();
protected:
};

bool Action::Empty()
{
	if (colFrom < 0 || colTo < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Action::operator==(const Action& rhs)
{
	if (colFrom == rhs.colFrom && colTo == rhs.colTo)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline bool Action::operator!=(const Action& rhs)
{
	return !(*this == rhs);
}