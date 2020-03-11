#pragma once

using namespace std;

class State
{
public:
	State(int n);
	State();
	void Print();
	int BoardSize();
private:
	//vars
	int* internalState;
	int size;
	//funcs
	void PrintFirstLine();
	void PrintAllRows();
	void PrintLastLine();
	void InitialiseInternalState();
	void RandomiseNewState();
protected:
};

