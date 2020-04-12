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

	void Print();
	void OutputLegalActions();
	int BoardSize();
	int* CopyInternalState();
	bool Move(int from, int to);
	bool Move(Action action);
	void CalculateHeuristic();

	void CombinedGoalHeuristic(int goalIndex);

	void NearestGoalHeuristic();

	int BlockAt(int column, int row);

	bool GoalAccomplished();

	bool CheckDisjunctiveGoal();

	bool CheckConjunctiveGoal();

	bool CheckAtomicGoal();

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
	Goal* GetGoal()
	{
		return goal;
	}
	void SetGoal(Goal* goal)
	{
		this->goal = goal;
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
	Goal* goal;
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
protected:
};

