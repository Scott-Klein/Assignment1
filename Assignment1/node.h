#pragma once
#include "state.h"
#include "Action.h"
class node
{
private:

	State* parent;
	State* data;
	Action lastAction;

};

