#pragma once

#include "Solver.h"
#include <iostream>
#include <set>
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
	auto closedCmp = [](State* a, State* b) { return a->GetHash() > b->GetHash(); };
	auto openCmp = [](State* a, State* b) { return a->GetFinalvalue() > b->GetFinalvalue(); };

	priority_queue<State*> openSet;
	set<State*, decltype(closedCmp)> closedSet;
	openSet.push(state);

	while (!openSet.empty())
	{
		State* current = openSet.top();
		openSet.pop();
		closedSet.insert(current);// > IS happening here fuck!!! I NEED TO ROLL MY OWN CONTAINER
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
			openSet.push(neighbour);
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