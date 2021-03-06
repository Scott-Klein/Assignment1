#pragma once
#include <iostream>
#include "Options.h"
#include "Solver.h"

using namespace std;

bool runAgain();

int main()
{
    //_crtBreakAlloc = 6926;
    do
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
    } while (runAgain());
}

bool runAgain()
{
    char result;
    cout << endl << "Would you like to run the program again? (y / n) :";
    cin >> result;
    if (result == 'y' || result == 'Y')
    {
        return true;
    }
    cout << "Goodbye";
    return false;
}