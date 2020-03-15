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
	State(State* parent, Action action);
	void Print();
	void OutputLegalActions();
	int BoardSize();
	int* CopyInternalState();
	bool MoveColumn(int from, int to);

	int BlockAt(int column, int row);
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

	bool CanDoAction(Action action);
	bool TopOfColumnClear(int column);
	bool ColumnEmpty(int column);
	int* GetColumn(int k);

	int GetNewRandom();
	int RemoveTop(int from);
protected:
};

