//Refactored once
#pragma once
#include <stack>
#include "Action.h"
#include "State.h"
#include "Options.h"
#include "node.h"
#include <queue>
#include <set>

class Solver
{
public:
	Solver(Options options);

	~Solver() {
		delete goal;
		delete state;
		while (!openSet.empty())
		{
			auto currentNode = openSet.top();
			openSet.pop();
			delete currentNode.GetData();
		}
		for (int i = 0; i < closedSet.size(); i++)
		{
			if (i > 0)
			{
				State* item = closedSet[i];
				delete item;
			}
		}
	}
	stack<Action> GetWinningMoves()
	{
		return this->goalPath;
	}

	bool Success();

	void PrintWinningMoves();
private:
	bool Search();

	bool unWindMoves(State* endState);

	priority_queue<Node> openSet;
	vector<State*> closedSet;
	vector<State*> neighbours;
	Goal* goal;
	State* state;
	stack<Action> goalPath;

	bool found;
};

