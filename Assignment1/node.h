#pragma once
#include "state.h"
#include "Action.h"
class Node
{
public:
	Node(State* d)
	{
		this->data = d;
	}
	Node(State* d, State* p)
	{
		this->parent = p;
		this->data = d;
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

	friend bool operator<(const Node& lhs, const Node& rhs);
private:
	int value;
	State* parent;
	State* data;
	Action lastAction;

};

