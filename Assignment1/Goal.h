#pragma once
#include <iostream>
#include "SolverType.h"
#include <vector>
using namespace std;

class Goal
{
public:
	Goal()
	{
	}

	Goal(int k, int n, SolverType type)
	{
		this->goalType = type;
		if (type != SOLVERTYPE_ATOMIC)
		{
			int input = 1;
			while (input > 0)
			{
				CollectNewGoal(k,n);
				cout << "Input a positive number if you'd like to enter another goal:" << endl;
				cin >> input;
			}
		}
	}
	int Block(int i)
	{
		return blocks[i];
	}

	int Column(int i)
	{
		return columns[i];
	}

	int Row(int i)
	{
		return rows[i];
	}

	SolverType GetType()
	{
		return goalType;
	}

	int Count()
	{
		return blocks.size();
	}
	void DisjunctiveSuccess(int i);
	void Print();
private:
	SolverType goalType;
	void CollectNewGoal(int k, int n);
	vector<int> blocks, rows, columns;
	int disjunctiveSuccessIndex;
	void goalLineDisplay(int column, int row, int block);
protected:
};





