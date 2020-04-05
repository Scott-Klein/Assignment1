#pragma once
#include <vector>
#include <list>
#include "Action.h"
#include <stack>
#include <queue>
#include "Goal.h"

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
	int LegalNeighbourCount();
	bool MoveColumn(int from, int to);
	void CalculateHeuristic(Goal goal);
	int GetFinalvalue()
	{
		return heuristic + Distance;
	}
	int BlockAt(int column, int row);
	vector<State> GetNeighbours();
	int Distance;

	int GetHeuristicValue()
	{
		return heuristic;
	}
private:
	//vars
	int* internalState;
	int size;
	int numbers;
	int heuristic;
	vector<int> candidatePositioins;
	vector<Action> actions;

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
	void GenerateHeuristic(Action* const action);


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

void State::CalculateHeuristic(Goal goal)
{
	int blocksInDestinationColumn = 0;

	blocksInDestinationColumn = CountBlocksAtAndAbove(goal.Column, goal.Row);
	heuristic = (blocksInDestinationColumn + CountBlocksAtAndAboveSubject(goal.Block));
}

int State::CountBlocksAtAndAboveSubject(int block)
{
	for (int i = 0; i < size*size; i++)
	{
		if (internalState[i] == block)
		{
			int col = i / size;
			return CountBlocksAtAndAbove(col, (i % size));
		}
	}
}
