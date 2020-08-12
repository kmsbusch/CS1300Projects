// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinbusch/csci1300
// Homework 3 - Problem #6
#include <iostream>
#include <math.h>
using namespace std;
/*
Algorithm: calculate surface area of a sphere based on radius using 
1. surface area equation = 4 * pi * radius^2
Input:radius (double)
Output (prints to screen): surface area
Returns: none
*/
void sphereSurfaceArea(double radius)
{
    cout << "surface area: " << (4.0) * M_PI * pow(radius, 2) << endl; 
    
}
int main()
{
    sphereSurfaceArea(12.00);
    sphereSurfaceArea(15.00);
}



