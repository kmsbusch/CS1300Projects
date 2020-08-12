// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinbusch/csci1300
// Homework 3 - Problem #4
#include <iostream>
#include <math.h>
using namespace std;


/*
Algorithm: Calculate volume and surface area of a sphere using:
1. volume equation = 4/3 * pi * radius^3
2. surface area equation = 4 * pi * radius^2
Input: radius (double)
Output (prints to screen): volume and surface area
Returns: none
*/
int main()
{
    cout << "Enter a radius: " << endl;
    double radius;
    cin >> radius;
    double volume;
    volume = (4.0/3.0) * M_PI * pow(radius, 3);
    cout << "volume: " << volume << endl;
    
    double surfaceArea;
    surfaceArea = (4.0) * M_PI * pow(radius, 2);
    cout <<"surface area: " << surfaceArea << endl;
}