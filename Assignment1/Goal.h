#pragma once
//#include "State.h"

class Goal
{
public:
	Goal();
	Goal(int k, int n)
	{
		while (block < 1 || block > k )
		{
			cout << "Please choose a block to target" << endl;
			cin >> block;
		}
		while (column > n-1 || column < 0)
		{
			cout << "Please choose a column you want to deposit" << endl;
			cin >> column;
		}
		while (row > n-1 || row < 0)
		{
			cout << "Please choose the row you want the block to reach" << endl;
			cin >> row;
		}
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





