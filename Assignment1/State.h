#pragma once
#include <vector>
#include "Goal.h"
#include "Action.h"
using namespace std;

class State
{
public:
	friend bool operator<(const State& lhs, const State& rhs);

	State(int n, int k);

	State();

	State(State* parent, Action action);

	int BoardSize();

	int* CopyInternalState();

	int BlockAt(int column, int row);

	void CalculateHeuristic();

	void Print();

	void OutputLegalActions();

	void CombinedGoalHeuristic(int goalIndex);

	void NearestGoalHeuristic();

	bool Move(int from, int to);

	bool Move(Action action);

	bool GoalAccomplished();

	bool CheckDisjunctiveGoal();

	bool CheckConjunctiveGoal();

	bool CheckAtomicGoal();

	vector<State*> GetNeighbours();

	int GetHeuristicValue()
	{
		return heuristic;
	}

	int GetFinalvalue()
	{
		return heuristic + distance;
	}

	int GetHash()
	{
		return hash;
	}

	Action GetLastMove()
	{
		return previousMove;
	}

	State* GetPreviousState()
	{
		return previous;
	}

	Goal* GetGoal()
	{
		return goal;
	}

	void SetGoal(Goal* goal)
	{
		this->goal = goal;
	}
private:
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

	int GoalDistance(int i);

	int UnmetGoals();

	int deepestUnmetGoal();

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

	Goal* goal;
};

