#include "Goal.h"

Goal::Goal(int block, int column, int row)
{
	this->block = block;
	this->column = column;
	this->row = row;
}

Goal::Goal()
{
}

int Goal::Block()
{
	return this->block;
}

int Goal::Column()
{
	return this->column;
}

int Goal::Row()
{
	return this->row;
}

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


