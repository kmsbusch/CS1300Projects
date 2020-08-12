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

double CoffeeCost(int cupNum, double costCup)
{
    double costTotal;
    costTotal = cupNum * costCup;
    if (cupNum > 12 && cupNum < 24)
    {
        costTotal = (cupNum - 1) * costCup;
    }
    else if (cupNum > 24 && cupNum < 36)
    {
        costTotal = (cupNum - 2) * costCup;
    }
    return costTotal;
}