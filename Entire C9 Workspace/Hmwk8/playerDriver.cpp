// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Hmwk8
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Player.h"
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
    // checking default constructor
Player stella;
cout << stella.getName() << endl;
cout << stella.getPoints() << endl;

// checking name setters and getters
Player stella2;
stella2.setName("Stella2");
cout << stella2.getName() << endl;

// checking points setters and getters
stella.setPoints(13.1);
cout << stella.getPoints() << endl;

// checking parameterized constructor
Player hector("Hector", 6.2);
cout << hector.getName() << endl;
cout << hector.getPoints() << endl;

}