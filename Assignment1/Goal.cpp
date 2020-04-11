#include "Goal.h"

void Goal::DisjunctiveSuccess(int i)
{
	disjunctiveSuccess = i;
}

void Goal::Print()
{
	for (int i = 0; i < Count(); i++)
	{
		cout << "Goal to move " << blocks[i] << " to column " << columns[i] << ", row " << rows[i] << " fullfilled" << endl;
	}
}

void Goal::CollectNewGoal(int k, int n)
{
	int block = -1, column = -1, row = -1;
	while (block < 1 || block > k)
	{
		cout << "Please choose a block to target" << endl;
		cin >> block;
	}
	while (column > n - 1 || column < 0)
	{
		cout << "Please choose a column you want to deposit" << endl;
		cin >> column;
	}
	while (row > n - 1 || row < 0)
	{
		cout << "Please choose the row you want the block to reach" << endl;
		cin >> row;
	}
	blocks.push_back(block);
	rows.push_back(row);
	columns.push_back(column);
}
