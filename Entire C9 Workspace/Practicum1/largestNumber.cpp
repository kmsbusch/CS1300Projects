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

double largestNumber(double num1, double num2, double num3)
{
    if ((num1 > num2) && (num1 > num3))
    {
        return num1;
    }
    else if ((num2 >= num1) && (num2 >= num3))
    {
        return num2;
    }
    else if ((num3 > num1) && (num3 > num2))
    {
        return num3;
    }
}