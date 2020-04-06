#pragma once
//#include "State.h"

class Goal
{
public:
	Goal(int block, int column, int row)
	{
		this->block = block;
		this->column = column;
		this->row = row;
	}

	Goal()
	{
	}

	int Block()
	{
		return this->block;
	}

	int Column()
	{
		return this->column;
	}

	int Row()
	{
		return this->row;
	}

private:
	int block, column, row;
protected:
};





