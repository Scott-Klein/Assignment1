#pragma once
//#include "State.h"

class Action
{
private:
	int colFrom;
	int colTo;

public:
	Action(int from, int to);
	int GetFrom();
	int GetTo();
	void PrintMove();
protected:
};

