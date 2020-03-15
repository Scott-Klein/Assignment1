#pragma once
//#include "State.h"

class Action
{
private:
	int colFrom;
	int colTo;
	int value;
public:
	Action(int from, int to);
	Action();
	friend bool operator< (const Action &lhs, const Action &rhs);
	friend bool operator> (const Action &lhs, const Action &rhs);
	bool IsInverseAction(Action action);
	int GetFrom();
	int GetTo();
	int GetValue();
	void PrintMove();
	void RandomlyGenerateValue();
protected:
};

