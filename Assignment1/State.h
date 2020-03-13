#pragma once
#include <vector>
#include <list>
#include "Action.h"

using namespace std;

class State
{
public:
	State(int n, int k);
	State();
	State(State* parent, int from, int to);
	void Print();
	void OutputLegalActions();
	int BoardSize();
	int* CopyInternalState();
	bool MoveColumn(int from, int to);
private:
	//vars
	int* internalState;
	int size;
	int numbers;
	vector<int> candidatePositioins;
	list<Action> actions;

	//funcs
	void PrintFirstLine();
	void PrintAllRows();
	void PrintLastLine();
	void InitialiseInternalState();
	void ZeroInternalState();
	void InitialiseRandomisation();
	void RandomiseNewState();
	void DropNumbers();
	void GeneratePossibleActions();
	void PrintLegalActions();
	void DropColumn(int* column);
	void DepositTop(int column, int value);



	int* GetColumn(int k);

	int GetNewRandom();
	int RemoveTop(int from);
protected:
};

