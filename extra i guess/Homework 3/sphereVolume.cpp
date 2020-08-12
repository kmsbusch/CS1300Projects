// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinbusch/csci1300
// Homework 3 - Problem #5
#include <iostream>
#include <math.h>
using namespace std;
/*
Algorithm: Calculate and output volume of a sphere based on radius using
1. volume equation = 4/3 * pi * radius^3
Input: radius
Output (prints to screen): volume
Returns: none
*/
void sphereVolume(double radius)
{
    cout << "volume: " << (4.0/3.0) * M_PI * pow(radius, 3) << endl; 
}

int main()
{
    sphereVolume(10.00);
    sphereVolume(19.00);
}