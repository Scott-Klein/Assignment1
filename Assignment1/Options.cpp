#include "Options.h"
#include <iostream>

using namespace std;

void Options::QueryType()
{
	PrintOptions();
	int input = 0;
	while (input != 1 && input != 2 && input != 3)
	{
		cout << "Mode (1 - 3):";
		cin >> input;
	}
	switch (input)
	{
	case 1:
		Type = Single;
		break;
	case 2:
		Type = Multiple_Disjunctive;
		break;
	case 3:
		Type = Multiple_Conjunctive;
		break;
	default:
		cout << "FATAL ERROR CANNOT RECOVER" << endl;
		exit(-1);
		break;
	}
}

void Options::QueryNumbers()
{
	cout << "Please enter the number of tokens for your board" << endl;
	int k = 2;
	while (k < 3)
	{
		cout << "Tokens (3+):";
		cin >> k;
	}
	Numbers = k;

	
}

void Options::QuerySize()
{
	cout << "Please enter the height/width(size) of the board" << endl;
	int n = 2;
	while (n < 3)
	{
		cout << "Size (3+):";
		cin >> n;
	}
	Size = n;
}

bool Options::ValidateOptions()
{
	if (Size > 2 && Size <= Numbers && Numbers <= Size*Size - Size)
	{
		return true;
	}
	else
	{
		cout << "Invalid options: Rules are that n>2 and n≤k≤n2–n." << endl;
		cout << "n = size" << endl << "k = numbers";
		return false;
	}
}

void Options::PrintOptions()
{
	cout << "Please choose one of the following options:" << endl;
	cout << "1 - Atomic Goal" << endl;
	cout << "2 - Disjunctive Goals" << endl;
	cout << "3 - Conjunctive Goals" << endl;
}
