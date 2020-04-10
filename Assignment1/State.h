#pragma once
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "Goal.h"
#include "Action.h"

using namespace std;

class State
{
public:

	friend bool operator<(const State& lhs, const State& rhs);

	bool operator==(const State& rhs) const { 
		return true;
	}

	State(int n, int k);
	State();
	State(State* parent, Action action);

	void Print();
	void OutputLegalActions();
	int BoardSize();
	int* CopyInternalState();
	int LegalNeighbourCount();
	bool Move(int from, int to);
	bool Move(Action action);
	void CalculateHeuristic(Goal goal);

	int BlockAt(int column, int row);

	bool GoalAccomplished(Goal goal);

	vector<State*> GetNeighbours();

	Action GetLastMove()
	{
		return previousMove;
	}

	int GetHeuristicValue()
	{
		return heuristic;
	}

	State* GetPreviousState()
	{
		return previous;
	}

	int GetFinalvalue()
	{
		return heuristic + distance;
	}

	int GetHash()
	{
		return hash;
	}
private:
	//vars
	int* internalState;
	int hash;
	int size;
	int numbers;
	int heuristic;
	int distance;
	Action previousMove;
	vector<int> candidatePositioins;
	vector<Action> actions;
	State* previous;
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
	void HashCode();

	bool CanDoAction(Action action);
	bool TopOfColumnClear(int column);
	bool ColumnEmpty(int column);
	int* GetColumn(int k);
	int CountBlocksAtAndAbove(int col, int row);
	int CountBlocksAtAndAboveSubject(int block);
	int GetNewRandom();
	int RemoveTop(int from);
protected:
};

