// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 7 - Problem #1
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

int main()
{
    // checking setter for name
    Planet p2 = Planet();
    string name = "On A Cob Planet";
    p2.setName(name);
    cout << "Planet Name: " << p2.getName() << endl;
}