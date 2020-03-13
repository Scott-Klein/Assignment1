#include "Action.h"
#include <iostream>

using namespace std;

Action::Action( int from, int to)
{
	this->colFrom = from;
	this->colTo = to;
}

void Action::PrintMove()
{
	cout << "Move from " << colFrom << " to " << colTo << endl;
}


