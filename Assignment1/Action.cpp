#include "Action.h"


Action::Action(State* parent, int from, int to)
{
	this->parent = parent;
	this->colFrom = from;
	this->colTo = to;
}

State* Action::GetChild()
{
	if (this->child == nullptr)
	{
		this->child = new State(this->parent, this->colFrom, this->colTo);
	}
	return this->child;
}

State* Action::GetParent()
{
	return this->parent;
}
