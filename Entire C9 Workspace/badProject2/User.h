// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 7 - Problem #4
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#ifndef USER_H
#define USER_H
/*
Algorithm: 
1.
Input parameters: 
Output (prints to screen): 
Returns: none
*/

class User
{

public:
    User(); //default constructor
    User(string, int[], int); //parameterized constructor
    void setUsername(string); //setter for username string
    string getUsername(); //getter for username
    bool setRatingAt(int, int); //setter for rating at specified indices
    int getRatingAt(int); //getter for rating at index
    void setNumRatings(int); //setter for numratings
    int getNumRatings(); //getter for numratings
    int getSize();

private:
    string username;
    int ratings[50];
    int numRatings;
    int size; //n2s does this need to be initializedabove ratings and then go into the brackets for ratings?
};
#endif