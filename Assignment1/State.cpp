#include "State.h"
#include <iostream>
using namespace std;

State::State(int n)
{
	if (n > 2)
	{
		size = n;
	}
	else
	{
		size = 3;
	}
	InitialiseInternalState();
}

State::State()
{
	size = 3;
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

}


void State::PrintFirstLine()
{
	cout << " ";
	for (int i = 0; i < 3; i++)
	{
		cout << "--- ";
	}
	cout << endl;
}

void State::PrintAllRows()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 9; j += 3)
		{
			cout << "| " << internalState[i + j] << " ";
		}
		cout << "| " << endl;
	}
}

void State::PrintLastLine()
{
	cout << " ";
	for (int i = 0; i < 3; i++)
	{
		cout << "--- ";
	}
}

void State::InitialiseInternalState()
{
	internalState = new int[size * size];
	for (int i = 0; i < size*size; i++)
	{
		internalState[i] = i;
	}
}

#pragma endregion




