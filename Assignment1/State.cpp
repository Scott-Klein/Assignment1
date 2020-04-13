#pragma once
#include "State.h"
#include "Action.h"
#include <list>
#include <time.h>

using namespace std;

bool operator<(const State& lhs, const State& rhs)
{
	if (lhs.hash == rhs.hash)
	{
		return false;
	}
	return ((lhs.distance + lhs.heuristic) > (rhs.distance + rhs.heuristic));
}

State::State(int n, int k)
{
	if (n > 2)
	{
		size = n;
	}
	else
	{
		size = 3;
	}
	numbers = k;
	distance = 0;
	InitialiseInternalState();
	Print();
}

State::State()
{
	//defaults
	size = 3;
	numbers = 6;
	InitialiseInternalState();
}

State::State(State* parent, Action action)
{
	this->previous = parent;
	this->previousMove = action;
	this->internalState = parent->CopyInternalState();
	this->size = parent->BoardSize();
	this->Move(action.GetFrom(), action.GetTo());
	this->distance = parent->distance + 1;
	this->goal = parent->GetGoal();
}

int State::BoardSize()
{
	return this->size;
}

int* State::CopyInternalState()
{
	int* newState = new int[size * size];
	for (int i = 0; i < size * size; i++)
	{
		newState[i] = internalState[i];
	}

	return newState;
}

int State::BlockAt(int column, int row)
{
	return this->internalState[column * size + row];
}

void State::CalculateHeuristic()
{
	if (goal->GetType() == SOLVERTYPE_ATOMIC)
	{
		int atomicGoal = 0;
		heuristic = GoalDistance(atomicGoal);
	}
	else if (goal->GetType() == SOLVERTYPE_CONJUNCTIVE)
	{
		if (RowOfDeepestGoal() > 1)
		{
			heuristic = 10 * RowOfDeepestGoal();
		}
		heuristic += GoalDistance(deepestUnmetGoal());
	}
	else if (goal->GetType() == SOLVERTYPE_DISJUNCTIVE)
	{
		NearestGoalHeuristic();
	}
}

void State::Print()
{
	//0, 3, 6, 
	//1, 4, 7, 
	//2, 5, 8
	
	PrintFirstLine();

	PrintAllRows();

	PrintLastLine();
}

void State::OutputLegalActions()
{
	GeneratePossibleActions();
	PrintLegalActions();
}

void State::CombinedGoalHeuristic(int goalIndex)
{
	int total = 0;
	for (int i = 0; i < goal->Count(); i++)
	{
		total += GoalDistance(i);
	}
	heuristic = total;
}

void State::NearestGoalHeuristic()
{
	int min = 9999999999;
	for (int i = 0; i < goal->Count(); i++)
	{
		int current = GoalDistance(i);
		if (current < min)
		{
			min = current;
		}
	}
	heuristic = min;
}

bool State::Move(int from, int to)
{
	if (TopOfColumnClear(to))
	{
		DepositTop(to, RemoveTop(from));
		DropNumbers();
		HashCode();
		return true;
	}
	else
	{
		return false;
	}

}

bool State::Move(Action action)
{
	return Move(action.GetFrom(), action.GetTo());
}

bool State::GoalAccomplished()
{
	if (goal->GetType() == SOLVERTYPE_ATOMIC)
	{
		return CheckAtomicGoal();
	}
	else if (goal->GetType() == SOLVERTYPE_CONJUNCTIVE)
	{
		return CheckConjunctiveGoal();
	}
	else if (goal->GetType() == SOLVERTYPE_DISJUNCTIVE)
	{
		return CheckDisjunctiveGoal();
	}
}

bool State::CheckDisjunctiveGoal()
{
	for (int i = 0; i < goal->Count(); i++)
	{
		if (BlockAt(goal->Column(i), goal->Row(i)) == goal->Block(i))
		{
			goal->DisjunctiveSuccess(i);
			return true;
		}
	}
	return false; // All goals were missed.
}

bool State::CheckConjunctiveGoal()
{
	for (int i = 0; i < goal->Count(); i++)
	{
		if (BlockAt(goal->Column(i), goal->Row(i)) != goal->Block(i))
		{
			return false;
		}
	}
	return true; // can only hit here if all goals were met.
}

bool State::CheckAtomicGoal()
{
	int atomicGoal = 0;
	if (BlockAt(goal->Column(atomicGoal), goal->Row(atomicGoal)) == goal->Block(atomicGoal))
	{
		return true;
	}
	else
	{
		return false;
	}
}

vector<State*> State::GetNeighbours()
{
	vector<State*> result;
	GeneratePossibleActions();
	for (int i = 0; i < this->actions.size(); i++)
	{
		result.push_back(new State(this, actions[i]));
	}
	return result;
}

void State::PrintFirstLine()
{
	cout << endl << "\n    ";
	for (int i = 0; i < size; i++)
	{
		cout << "-" << i << "- ";
	}
	cout << endl;
	cout << "    ";
	for (int i = 0; i < size; i++)
	{
		cout << "--- ";
	}
	cout << endl;
}

void State::PrintAllRows()
{
	for (int i = 0; i < size; i++)
	{
		cout << i << "  ";
		for (int j = 0; j < (size * size); j += size)
		{
			if (internalState[i + j] != 0)
			{
				cout << "| " << internalState[i + j] << " ";
			}
			else
			{
				cout << "|   ";
			}
		}
		cout << "| " << endl;
	}
}

void State::PrintLastLine()
{
	cout << "    ";
	for (int i = 0; i < size; i++)
	{
		cout << "--- ";
	}
	cout << endl << endl;
}

void State::InitialiseInternalState()
{
	InitialiseRandomisation();
	ZeroInternalState();
	RandomiseNewState();
	DropNumbers();
	HashCode();
}

void State::ZeroInternalState()
{
	internalState = new int[size * size];
	for (int i = 0; i < size * size; i++)
	{
		internalState[i] = 0;
	}
}

void State::InitialiseRandomisation()
{
	srand(time(NULL));
	candidatePositioins = vector<int>();
	for (int i = 0; i < size * size; i++)
	{
		candidatePositioins.push_back(i);
	}
}

void State::RandomiseNewState()
{
	for (int i = 0; i < numbers; i++)
	{
		internalState[GetNewRandom()] = i + 1;
	}
}

void State::DropNumbers()
{
	for (int i = 0; i < size; i++)
	{
		DropColumn(GetColumn(i));
	}
}

void State::GeneratePossibleActions()
{
	for (int fromColumn = 0; fromColumn < size; fromColumn++)
	{
		for (int toColumn = 0; toColumn < size; toColumn++)
		{
			Action candidate = Action(fromColumn, toColumn);
			if (CanDoAction(candidate))
			{
				this->actions.push_back(candidate);
			}
		}
	}
}

void State::PrintLegalActions()
{
	while (!actions.empty())
	{
		//auto action = actions.top();
		//action.PrintMove();
		//actions.pop();
	}
}

void State::DropColumn(int* column)
{
	list<int> temp;
	for (int i = 0; i < size; i++)
	{
		temp.push_back(column[i]);
		column[i] = 0;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		while (!temp.empty() && temp.back() == 0)
		{
			temp.pop_back();
		}
		if (!temp.empty())
		{
			column[i] = temp.back();
			temp.pop_back();
		}
	}
}

void State::DepositTop(int column, int value)
{
	GetColumn(column)[0] = value;
}

void State::HashCode()
{
	int code = 0;
	for (int i = 0; i < size * size; i++)
	{
		code = code << 3;
		code = code | internalState[i];
	}
	hash = code;
}

bool State::CanDoAction(Action action)
{
	if (action.GetFrom() == action.GetTo())
	{
		return false;
	}
	return (TopOfColumnClear(action.GetTo()) && !ColumnEmpty(action.GetFrom()));
}

bool State::TopOfColumnClear(int column)
{
	return GetColumn(column)[0] == 0;
}

bool State::ColumnEmpty(int column)
{
	int* arr = GetColumn(column);
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0)
		{
			return false;
		}
	}
	return true;
}

bool State::CompletedGoalAbove(int i)
{
	int column = goal->Column(i), row = goal->Row(i), block = goal->Block(i);
	int* col = GetColumn(column);
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < goal->Count(); k++)
		{

		}
	}
	return false;
}

int* State::GetColumn(int k)
{
	return &internalState[k * size];
}

int State::CountBlocksAtAndAbove(int col, int row)
{
	int* column = GetColumn(col);
	int count = 0;
	for (int i = 0; i < row+1; i++)
	{
		if (column[i] > 0)
		{
			count++;
		}
	}
	return count;
}

int State::CountBlocksAtAndAboveSubject(int block)
{
	for (int i = 0; i < size * size; i++)
	{
		if (internalState[i] == block)
		{
			int col = i / size;
			return CountBlocksAtAndAbove(col, (i % size));
		}
	}
}

int State::RowOfBlock(int block)
{
	for (int i = 0; i < size * size; i++)
	{
		if (internalState[i] == block)
		{
			int col = i / size;
			return (i % size);
		}
	}
}

int State::GetNewRandom()
{
	int randomNum = rand() % candidatePositioins.size();
	int result = candidatePositioins[randomNum];
	candidatePositioins.erase(candidatePositioins.begin() + randomNum);
	return result;
}

int State::RemoveTop(int from)
{
	int* column = GetColumn(from);
	for (int i = 0; i < size; i++)
	{
		if (column[i] > 0)
		{
			int result = column[i];
			column[i] = 0;
			return result;
		}
	}
	return 0;
}

int State::GoalDistance(int i)
{
	//if (true)// If there is an unmet goal below goal i, then return a monstrously large value.
	//{
	//	return 999999999;
	//}
	int blocksInDestinationColumn = CountBlocksAtAndAbove(goal->Column(i), goal->Row(i));
	return (blocksInDestinationColumn + CountBlocksAtAndAboveSubject(goal->Block(i)));
}

int State::RowOfDeepestGoal()
{
	int max = 0;
	for (int i = 0; i < goal->Count(); i++)
	{
		if (BlockAt(goal->Column(i), goal->Row(i)) != goal->Block(i))
		{
			if (goal->Row(i) > max)
			{
				max = goal->Row(i);
			}
		}
	}
	return max;
}

int State::deepestUnmetGoal()
{
	int index = 0;
	for (int i = 0; i < goal->Count(); i++)
	{
		if (goal->Row(i) > index && BlockAt(goal->Column(i), goal->Row(i)) != goal->Block(i)) // if 
		{
			index = i;
		}
	}
	return index;
}