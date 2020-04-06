#pragma once

#include "Solver.h"
#include <iostream>
#include <set>
using namespace std;

Solver::Solver(Goal goal, State state)
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
	priority_queue<State> openSet;
	openSet.push(state);
	set<State> closedSet;
	while (!openSet.empty())
	{
		State current = openSet.top();
		openSet.pop();
		auto result = closedSet.insert(current);// > IS happening here fuck!!! I NEED TO ROLL MY OWN CONTAINER
		if (!result.second)
		{
			cout << "Some shits fucked" << endl;
		}
		vector<State> neighbours = current.GetNeighbours();
		for (int i = 0; i < neighbours.size(); i++)
		{
			State neighbour = neighbours[i];
			if (closedSet.find(neighbour) != closedSet.end()) //if neighbour is in closeSet, then continue.
			{
				continue;
			}

			if (neighbour.GoalAccomplished(goal))
			{
				return unWindMoves(neighbour);
			}

			neighbour.CalculateHeuristic(goal);

			openSet.push(neighbour);
		}
	}

	return false;
}

bool Solver::unWindMoves(State endState)
{
	State current = endState;
	while (!current.GetLastMove().Empty())
	{
		goalPath.push(current.GetLastMove());
		current = *(current.GetPreviousState());
	}
	return true;
}