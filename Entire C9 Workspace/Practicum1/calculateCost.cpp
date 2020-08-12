// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project 1 - Problem # 
#include <iostream>
using namespace std;

/*
Algorithm: 
Input parameters: 
Output (prints to screen): 
Returns: none
*/

double calculateCost(double distance, double avgSpeed, double gasPrice)
{
    if (avgSpeed > 62)
    {
        double tripCost = (distance / 26) * gasPrice;
        return tripCost;
    }
    else if (avgSpeed <= 62)
    {
        double tripCost = (distance / 30) * gasPrice;
        return tripCost;
    }
}