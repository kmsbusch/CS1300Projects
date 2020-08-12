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


// class User
// {

// public:
//     User(); //default constructor
//     User(string, int[], int); //parameterized constructor
//     void setUsername(string); //setter for username string
//     string getUsername(); //getter for username
//     bool setRatingAt(int, int); //setter for rating at specified indices
//     int getRatingAt(int); //getter for rating at index
//     void setNumRatings(int); //setter for numratings
//     int getNumRatings(); //getter for numratings
//     int getSize();

// private:
//     string username;
//     int ratings[50];
//     int numRatings;
//     int size; //n2s does this need to be initializedabove ratings and then go into the brackets for ratings?
// };


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
    for (int i = ratingsCount; i < size; i++) //set the array after what has a value equal to zero. 
    {
        ratings[i] = 0;
    }
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