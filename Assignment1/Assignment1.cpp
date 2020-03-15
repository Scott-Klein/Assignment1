// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Action.h"
#include "State.h"
#include "Goal.h"
#include "Solver.h"
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    std::cout << "Assignment 1 --- Data Structures and Algorithms.\n";
    State test = State(3, 6);
    cout << "First board" << endl;
    test.Print();
    int target, column, row;

    cout << "Please choose a block to target" << endl;

    cin >> target;

    cout << "Please choose a column you want to deposit" << endl;

    cin >> column;

    cout << "Please choose the row you want the block to reach" << endl;

    cin >> row;

    Goal goal = Goal(target, column, row);
    Solver solver = Solver(goal, test, 4000);

}
