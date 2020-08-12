// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 7 - Problem #1&2
#include <iostream>
using namespace std;


/*
Algorithm: 
Input parameters: 
Output (prints to screen): 
Returns: none
*/

class Planet
{
public: //public 
    
    Planet(); //default constructor
    Planet(string, double); //parameterized constructor
    void setName(string); //setter for name
    string getName(); //getter for name
    void setRadius(double); // setter for radius
    double getRadius(); // getter for radius
    double getVolume(); //getter for volume
    
    
private: 
    string planetName;
    double planetRadius;
};