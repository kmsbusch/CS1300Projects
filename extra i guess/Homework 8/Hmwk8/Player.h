// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Hmwk8
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*
Algorithm: 
1.
Input parameters: 
Output (prints to screen): 
Returns: none
*/
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    
public:
    Player(); //default constructor
    Player(string, double); //parameterized constructor
    string getName(); //getter for names
    double getPoints();// point getter
    void setName(string);//setter for names
    void setPoints(double);//point setter

private:
    string name; //name
    double points; //points
    
};
#endif
