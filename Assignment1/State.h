#pragma once
#include <vector>

using namespace std;

class State
{
public:
	State(int n, int k);
	State();
	void Print();
	int BoardSize();
private:
	//vars
	int* internalState;
	int size;
	int numbers;
	vector<int> candidatePositioins;
	//funcs
	void PrintFirstLine();
	void PrintAllRows();
	void PrintLastLine();
	void InitialiseInternalState();
	void ZeroInternalState();
	void InitialiseRandomisation();
	void RandomiseNewState();
	void DropNumbers();
	void DropColumn(int* column);
	bool MoveColumn(int from, int to);
	int RemoveTop(int from);
	void DepositTop(int column, int value);
	int* GetColumn(int k);
	
	int GetNewRandom();
protected:
};

