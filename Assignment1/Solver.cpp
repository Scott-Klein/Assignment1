#pragma once

#include "Solver.h"
#include <iostream>
#include <set>
#include "Node.h"

using namespace std;

Solver::Solver(Goal goal, State* state)
{
	this->state = state;
	this->goal = goal;

	this->found = Search();
}

Solver::Solver()
{
	//TODO: Implement input gathering
}

bool Solver::Success()
{
	return this->found;
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
			if (neighbour->GoalAccomplished(goal))
			{
				return unWindMoves(neighbour);
			}
			neighbour->CalculateHeuristic(goal);
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