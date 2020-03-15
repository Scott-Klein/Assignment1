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
	this->internalState = parent->CopyInternalState();
	this->size = parent->BoardSize();
	this->MoveColumn(action.GetFrom(), action.GetTo());
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

bool State::MoveColumn(int from, int to)
{
	if (TopOfColumnClear(to))
	{
		DepositTop(to, RemoveTop(from));
		DropNumbers();
		return true;
	}
	else
	{
		return false;
	}

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
	auto it = actions.begin();
	for (; it != actions.end(); it++)
	{
		(*it).PrintMove();
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

#pragma endregion




