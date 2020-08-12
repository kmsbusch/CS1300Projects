// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 7 - Problem #2
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "Planet.h"
using namespace std;

/*
Algorithm: 
1.
Input parameters: 
Output (prints to screen): 
Returns: none
*/


int maxRadius(Planet planets[], int numPlanets)
{
    if (numPlanets == 0) //error return for empty array 
    {
        return -1;
    }
    int biggestRadius = 0; //storage variable for index of planet with biggest radius
    for (int i = 0; i < numPlanets; i++)
    {
        if (i == 0)
        {
            biggestRadius = i;
        }
        else if (i >= 1)
        {
            if (planets[biggestRadius].getRadius() == planets[i].getRadius())
            {
                biggestRadius = biggestRadius;
            }
            else if (planets[i].getRadius() > planets[i - 1].getRadius())
            {
                biggestRadius = i;
            }
            
            
        }
    }
    return biggestRadius;
}

int main()
{
    Planet planets[3];
    planets[0] = Planet("Nebraska",20);
    planets[1] = Planet("Delphi 6",10);
    planets[2] = Planet("p3",20);
    int idx = maxRadius(planets, 3);
    cout << planets[idx].getName() << endl;
    cout << planets[idx].getRadius() << endl;
    cout << planets[idx].getVolume() << endl;
    
    planets[0] = Planet("Planet Squanch",6.8);
    planets[1] = Planet("Delphi 6",8.6);
    planets[2] = Planet("Cronenberg World",8.6);
    idx = maxRadius(planets, 3);
    cout << planets[idx].getName() << endl;
    cout << planets[idx].getRadius() << endl;
    cout << planets[idx].getVolume() << endl;
}