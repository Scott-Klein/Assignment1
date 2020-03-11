#include "State.h"
#include <iostream>
using namespace std;

State::State()
{
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

#pragma endregion

#pragma region PrivateFunctions

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
	for (int i = 0; i < 9; i++)
	{
		internalState[i] = 0;
	}
}

#pragma endregion




