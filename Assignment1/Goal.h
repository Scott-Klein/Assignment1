#pragma once
//#include "State.h"

class Goal
{
public:
	Goal(int block, int column, int row);
	Goal();
	int Block();
	int Column();
	int Row();
	bool Accomplished(State state);
private:
	int block, column, row;
protected:
};


bool Goal::Accomplished(State state)
{
	if (state.BlockAt(this->column, this->row) == this->block)
	{
		return true;
	}
	else
	{
		return false;
	}
}
