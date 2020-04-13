//Refactored once
#pragma once
#include "Solver.h"
#include "State.h"
#include "Options.h"
#include "Goal.h"
#include "node.h"
#include <queue>
#include <set>

using namespace std;

Solver::Solver(Options options)
{
	state = options.GetState();
	goal = options.GetGoal();
	state->SetGoal(goal);
	this->found = Search();
}

bool Solver::Success()
{
	return this->found;
}

void Solver::PrintWinningMoves()
{
	while (!goalPath.empty())
	{
		state->Move(goalPath.top());
		goalPath.top().PrintMove();
		goalPath.pop();
		state->Print();
	}
	goal->Print();
}

bool Solver::Search()
{
	auto cmp = [](State* a, State* b) { return a->GetHash() > b->GetHash(); };
	priority_queue<Node> openSet;
	set<State*, decltype(cmp)> closedSet;
	openSet.push(Node(state));

	while (!openSet.empty())
	{
		Node currentNode = openSet.top();
		State* current = currentNode.GetData();
		openSet.pop();
		closedSet.insert(current);
		vector<State*> neighbours = current->GetNeighbours();
		for (int i = 0; i < neighbours.size(); i++)
		{
			State* neighbour = neighbours[i];
			if (closedSet.find(neighbour) != closedSet.end()) //if neighbour is in closeSet, then skip this run
			{
				continue;
			}
			if (neighbour->GoalAccomplished())
			{
				return unWindMoves(neighbour);
			}
			neighbour->CalculateHeuristic();
			openSet.push(Node(neighbour, current));
		}
	}
	return false;
}

bool Solver::unWindMoves(State* endState)
{
	State* current = endState;
	while (!current->GetLastMove().Empty())
	{
		goalPath.push(current->GetLastMove());
		current = current->GetPreviousState();
	}
	return true;
}