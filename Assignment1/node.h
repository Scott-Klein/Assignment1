//Refactored once
#pragma once
#include "State.h"
#include "Action.h"

class Node
{
public:
	//Must be friend because of some reason.
	friend bool operator<(const Node& lhs, const Node& rhs);

	Node(State* d)
	{
		this->data = d;
	}
	Node(State* d, State* p) :Node(d)
	{
		this->parent = p;
		this->value = this->data->GetFinalvalue();
	}

	State* GetParent()
	{
		return parent;
	}
	State* GetData()
	{
		return data;
	}

	Action GetLastAction()
	{
		return lastAction;
	}
private:
	int value;
	State* parent;
	State* data;
	Action lastAction;
};

