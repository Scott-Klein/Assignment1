// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Action.h"
#include "State.h"
using namespace std;

int main()
{
    std::cout << "Assignment 1 --- Data Structures and Algorithms.\n";
    State test = State(3, 6);
    cout << "First board" << endl;
    test.Print();

    cout << "bottom first: " << endl;
    cout << test.BlockAt(0, 2) << endl;
    cout << "bottom second: " << endl;
    cout << test.BlockAt(1, 2) << endl;
    cout << "bottom last: " << endl;
    cout << test.BlockAt(2, 2) << endl;
}
