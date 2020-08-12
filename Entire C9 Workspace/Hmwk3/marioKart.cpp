// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinbusch/csci1300
// Homework 3 - Problem #10
#include <iostream>
#include <math.h>
using namespace std;
/*
Algorithm: calculate deceleration of cart using formula:
1. deceleration = initial speed^2 / (2 * distance)
Input: initialSpeed (double), distance (double)
Output (prints to screen): none
Returns: deceleration (double)
*/
double marioKart(double initialSpeed, double distance)
{
    double deceleration = pow(initialSpeed, 2.0) / (2.0 * distance);
    return deceleration;
}

int main()
{
    double decel1 = marioKart(20.00, 12.00);
    cout << "decel1 = " << decel1 << endl;
    double decel2 = marioKart(91.00, 14.00);
    cout << "decel2 = " << decel2 << endl;
}
