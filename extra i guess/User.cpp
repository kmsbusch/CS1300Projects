// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 7 - Problem #4
#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
using namespace std;

/*
Algorithm: 
1.
Input parameters: 
Output (prints to screen): 
Returns: none
*/

User::User()
{
    //cout << "default" << endl;
    username = "";
    numRatings = 0;
    size = 50;
    for (int i = 0; i < 50; i++)
    {
        ratings[i] = 0;
    }
}
User::User(string inputName, int userRatings[], int ratingsCount)
{
    //User();
    username = "";
    numRatings = 0;
    size = 50;
    username = inputName;
    for (int i = 0; i < 50; i++)
    {
        ratings[i] = userRatings[i];
    }
    numRatings = ratingsCount;
}
void User::setUsername(string inputName)
{
    username = inputName;
}
string User::getUsername()
{
    return username;
}
bool User::setRatingAt(int index, int value)
{
    
    if (index < 50 && value >= 0 && value <= 5) //error might show up here from syntax
    {
        ratings[index] = value;
        return true;
    }
    else 
    {
        return false;
    }
}
int User::getRatingAt(int index)
{
    if (index < 50)
    {
        return ratings[index];
    }
    else 
    {
        return -1;
    }
}
void User::setNumRatings(int ratingCount)
{
    numRatings = ratingCount;
}
int User::getNumRatings()
{
    return numRatings;
}
int User::getSize()
{
    return size;
}

