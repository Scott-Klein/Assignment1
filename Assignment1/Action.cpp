#include "Action.h"
#include <iostream>


using namespace std;

Action::Action( int from, int to)
{
	this->colFrom = from;
	this->colTo = to;
	RandomlyGenerateValue();
}

Action::Action()
{
	RandomlyGenerateValue();
}


bool Action::IsInverseAction(Action action)
{
	if (this->colFrom == action.GetTo() && this->colTo == action.GetFrom())
	{
		return true;
	}
	return false;
}

void Action::PrintMove()
{
	cout << "Move from " << colFrom << " to " << colTo << endl;
}

void Action::RandomlyGenerateValue()
{
	this->value = rand() % 100;
}

int Action::GetFrom()
{
	return this->colFrom;
}

int Action::GetTo()
{
	return this->colTo;
}

int Action::GetValue()
{
	return this->value;
}

void Action::SetValue(int value)
{
	this->value = value;
}

bool operator<(const Action& lhs, const Action& rhs)
{
	return lhs.value < rhs.value;
}

bool operator>(const Action& lhs, const Action& rhs)
{
	return lhs.value > rhs.value;
}
