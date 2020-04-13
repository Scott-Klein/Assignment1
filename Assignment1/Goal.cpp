//Refactored once
#include "Goal.h"

void Goal::DisjunctiveSuccess(int i)
{
	disjunctiveSuccessIndex = i;
}

void Goal::Print()
{
	if (goalType == SOLVERTYPE_ATOMIC || goalType == SOLVERTYPE_CONJUNCTIVE)
	{
		for (int i = 0; i < Count(); i++)
		{
			goalLineDisplay(columns[i], rows[i], blocks[i]);
		}
	}
	else
	{
		goalLineDisplay(columns[disjunctiveSuccessIndex], rows[disjunctiveSuccessIndex], blocks[disjunctiveSuccessIndex]);
	}
}

bool Goal::GoalConflicts(int column, int row, int block)
{
	for (int i = 0; i < Count(); i++)
	{
		if (Column(i) == column && Row(i) == row)
		{
			cout << "Sorry, a goal already places a token at that position." << endl;
			return true;
		}
		else if (Block(i) == block)
		{
			cout << "Sorry, that block already has a goal, please choose a different block to target" << endl;
			return true;
		}
	}
	return false;
}

void Goal::CollectNewGoal(int k, int n)
{
	int block, column, row;
	do
	{
		block = -1, column = -1, row = -1;
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
	} while (GoalConflicts(column, row, block));

	blocks.push_back(block);
	rows.push_back(row);
	columns.push_back(column);
}

void Goal::goalLineDisplay(int column, int row, int block)
{
	cout << "Goal to move " << block << " to column " << column << ", row " << row << " fullfilled" << endl;
}
