// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 7 - Problem #1&2
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "Planet.h"
using namespace std;

/*
Algorithm: 
Input parameters: 
Output (prints to screen): 
Returns: none
*/

Planet::Planet()
{
    planetName = "";
    planetRadius = 0.0;
}

Planet::Planet(string name, double radius)
{
    planetName = name;
    planetRadius = radius;
}
void Planet::setName(string name)
{
    planetName = name;
}
string Planet::getName()
{
    return planetName;
}
void Planet::setRadius(double radius)
{
    planetRadius = radius;
}
double Planet::getRadius()
{
    return planetRadius;
}
double Planet::getVolume()
{
    return (4.0/3.0) * pow(planetRadius, 3) * M_PI;
}