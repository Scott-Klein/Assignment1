#include "Solver.h"
#include <iostream>

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

	vector<State> closeSet;

	state.CalculateHeuristic();

	while (!openSet.empty())
	{
		State current = openSet.top();
		openSet.pop();
		closeSet.push_back(current);
		vector<State> neighbours = current.GetNeighbours();
		for (int i = 0; i < neighbours.size(); i++)
		{
			State neighbour = neighbours[i];

			neighbour.CalculateHeuristic(goal);

			openSet.push(neighbour);
		}
	}

	return false;
}

