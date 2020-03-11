#pragma once
class State
{
public:
	State();
	void Print();
private:
	//vars
	int internalState[9];
	//funcs
	void PrintFirstLine();
	void PrintAllRows();
	void PrintLastLine();
	void InitialiseInternalState();
protected:
};

