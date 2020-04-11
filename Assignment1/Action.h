#pragma once
#include <iostream>

using namespace std;

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

	bool operator==(const Action& rhs)
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

	bool operator!=(const Action& rhs)
	{
		return !(*this == rhs);
	}

	bool IsInverseAction(Action action)
	{
		if (this->colFrom == action.GetTo() && this->colTo == action.GetFrom())
		{
			return true;
		}
		return false;
	}

	int GetFrom()
	{
		return this->colFrom;
	}

	int GetTo()
	{
		return this->colTo;
	}

	void PrintMove()
	{
		cout << "    Move from " << colFrom << " to " << colTo << endl;
	}

	bool Empty()
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
};

