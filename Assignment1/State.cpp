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

int State::BoardSize()
{
	return this->size;
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
	if (GetColumn(to)[0] == 0)
	{
		DepositTop(to, RemoveTop(from));
		return true;
	}
	else
	{
		return false;
	}

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

int* State::GetColumn(int k)
{
	return &internalState[k * size];
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
		for (int j = 0; j < (size*size); j += size)
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




