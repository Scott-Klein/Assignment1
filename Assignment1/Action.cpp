#include "Action.h"
#include <iostream>


using namespace std;

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

int Action::GetFrom()
{
	return this->colFrom;
}

int Action::GetTo()
{
	return this->colTo;
}


