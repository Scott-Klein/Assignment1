#pragma once
#include "State.h"

class Action
{
private:
	int colFrom;
	int colTo;
	State* parent;
	State* child;
public:
	Action(State* parent, int from, int to);
	State* GetChild();
	State* GetParent();
protected:
};

