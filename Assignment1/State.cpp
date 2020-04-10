#pragma once

#include "State.h"
#include <iostream>
#include <stack>
#include <time.h>
#include <vector>
#include <list>


using namespace std;



State::State(int n, int k)
{
	if (n > 2)
	{
		size = n;
	}
	else
	{
		size = 3;
	}
	numbers = k;
	distance = 0;
	InitialiseInternalState();
}

State::State()
{
	//defaults
	size = 3;
	numbers = 6;
	InitialiseInternalState();
}

State::State(State* parent, Action action)
{
	this->previous = parent;
	this->previousMove = action;
	this->internalState = parent->CopyInternalState();
	this->size = parent->BoardSize();
	this->Move(action.GetFrom(), action.GetTo());
	this->distance = parent->distance + 1;
}


#pragma region PublicFunctions

void State::Print()
{
	//0, 3, 6, 
	//1, 4, 7, 
	//2, 5, 8
	PrintFirstLine();

	PrintAllRows();

	PrintLastLine();
}

void State::OutputLegalActions()
{
	GeneratePossibleActions();
	PrintLegalActions();
}



int State::BoardSize()
{
	return this->size;
}

int* State::CopyInternalState()
{
	int* newState = new int[size * size];
	for (int i = 0; i < size * size; i++)
	{
		newState[i] = internalState[i];
	}

	return newState;
}

int State::LegalNeighbourCount()
{
	return 4;
}

bool State::GoalAccomplished(Goal goal)
{
	if (BlockAt(goal.Column(), goal.Row()) == goal.Block())
	{
		return true;
	}
	else
	{
		return false;
	}
}

vector<State*> State::GetNeighbours()
{
	vector<State*> result;
	GeneratePossibleActions();
	for (int i = 0; i < this->actions.size(); i++)
	{
		result.push_back(new State(this, actions[i]));
	}
	return result;
}

#pragma endregion

#pragma region PrivateFunctions

void State::RandomiseNewState()
{
	for (int i = 0; i < numbers; i++)
	{
		internalState[GetNewRandom()] = i + 1;
	}
}

void State::DropNumbers()
{
	for (int i = 0; i < size; i++)
	{
		DropColumn(GetColumn(i));
	}
}

void State::DropColumn(int* column)
{
	list<int> temp;
	for (int i = 0; i < size; i++)
	{
		temp.push_back(column[i]);
		column[i] = 0;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		while (!temp.empty() && temp.back() == 0)
		{
			temp.pop_back();
		}
		if (!temp.empty())
		{
			column[i] = temp.back();
			temp.pop_back();
		}
	}
}

bool State::Move(int from, int to)
{
	if (TopOfColumnClear(to))
	{
		DepositTop(to, RemoveTop(from));
		DropNumbers();
		HashCode();
		return true;
	}
	else
	{
		return false;
	}

}

bool State::Move(Action action)
{
	return Move(action.GetFrom(), action.GetTo());
}

int State::BlockAt(int column, int row)
{
	return this->internalState[column * size + row];
}



int State::RemoveTop(int from)
{
	int* column = GetColumn(from);
	for (int i = 0; i < size; i++)
	{
		if (column[i] > 0)
		{
			int result = column[i];
			column[i] = 0;
			return result;
		}
	}
	return 0;
}

void State::DepositTop(int column, int value)
{
	GetColumn(column)[0] = value;
}


bool State::CanDoAction(Action action)
{
	if (action.GetFrom() == action.GetTo())
	{
		return false;
	}

	return (TopOfColumnClear(action.GetTo()) && !ColumnEmpty(action.GetFrom()));
}

bool State::TopOfColumnClear(int column)
{
	return GetColumn(column)[0] == 0;
}

bool State::ColumnEmpty(int column)
{
	int* arr = GetColumn(column);
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0)
		{
			return false;
		}
	}
	return true;
}

int* State::GetColumn(int k)
{
	return &internalState[k * size];
}

int State::CountBlocksAtAndAbove(int col, int row)
{
	int* column = GetColumn(col);
	int count = 0;
	for (int i = 0; i < row+1; i++)
	{
		if (column[i] > 0)
		{
			count++;
		}
	}
	return count;
}

void State::GeneratePossibleActions()
{
	for (int fromColumn = 0; fromColumn < size; fromColumn++)
	{
		for (int toColumn = 0; toColumn < size; toColumn++)
		{
			Action candidate = Action(fromColumn, toColumn);
			if (CanDoAction(candidate))
			{
				this->actions.push_back(candidate);
			}
		}
	}
}


void State::PrintLegalActions()
{
	while (!actions.empty())
	{
		//auto action = actions.top();
		//action.PrintMove();
		//actions.pop();
	}
}

int State::GetNewRandom()
{
	int randomNum = rand() % candidatePositioins.size();
	int result = candidatePositioins[randomNum];
	candidatePositioins.erase(candidatePositioins.begin() + randomNum);
	return result;
}

void State::PrintFirstLine()
{
	cout << " ";
	for (int i = 0; i < size; i++)
	{
		cout << "--- ";
	}
	cout << endl;
}

void State::PrintAllRows()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < (size * size); j += size)
		{
			cout << "| " << internalState[i + j] << " ";
		}
		cout << "| " << endl;
	}
}

void State::PrintLastLine()
{
	cout << " ";
	for (int i = 0; i < size; i++)
	{
		cout << "--- ";
	}
	cout << endl;
}

void State::InitialiseInternalState()
{
	InitialiseRandomisation();
	ZeroInternalState();
	RandomiseNewState();
	DropNumbers();
	HashCode();
}

void State::ZeroInternalState()
{
	internalState = new int[size * size];
	for (int i = 0; i < size * size; i++)
	{
		internalState[i] = 0;
	}
}

void State::InitialiseRandomisation()
{
	srand(time(NULL));
	candidatePositioins = vector<int>();
	for (int i = 0; i < size * size; i++)
	{
		candidatePositioins.push_back(i);
	}
}

void State::HashCode()
{
	int code = 0;
	for (int i = 0; i < size * size; i++)
	{
		code = code << 3;
		code = code | internalState[i];
	}
	hash = code;
}


bool operator<(const State& lhs, const State& rhs)
{
	if (lhs.hash == rhs.hash)
	{
		bool isAlright = true;
		for (int i = 0; i < lhs.size * lhs.size; i++)
		{
			if (lhs.internalState[i] != rhs.internalState[i])
			{
				isAlright = false;
				
			}
		}
		return false;
	}
	return ((lhs.distance + lhs.heuristic) > (rhs.distance + rhs.heuristic));
}

void State::CalculateHeuristic(Goal goal)
{
	int blocksInDestinationColumn = 0;

	blocksInDestinationColumn = CountBlocksAtAndAbove(goal.Column(), goal.Row());
	heuristic = (blocksInDestinationColumn + CountBlocksAtAndAboveSubject(goal.Block()));
}

int State::CountBlocksAtAndAboveSubject(int block)
{
	for (int i = 0; i < size * size; i++)
	{
		if (internalState[i] == block)
		{
			int col = i / size;
			return CountBlocksAtAndAbove(col, (i % size));
		}
	}
}



#pragma endregion




