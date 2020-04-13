#pragma once
#include <iostream>
#include "Options.h"
#include "Solver.h"

using namespace std;

int main()
{
    cout << "Assignment 1 --- Data Structures and Algorithms.\n";

    Options options;
    Solver solver = Solver(options);

    if (solver.Success())
    {
        solver.PrintWinningMoves();
    }
    else
    {
        cout << "Could not find a solution" << endl;
    }
}

