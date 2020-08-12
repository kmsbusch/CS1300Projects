// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 7 - Problem #7
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
int split(string str, char c, string words[], int arrayLength)
{
    if (str.length() == 0) {
        return 0;
    }
    string word = "";
    int j = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c) 
        {
        	if (word.length() == 0) continue;
            words[j] = word;
            j++;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return j;
}

int readRatings (string fileName, User users[], int numUserStored, int userArrSize, int maxColumns)
{
    ifstream myfile;
    myfile.open(fileName);
    string str[51]; //string that split takes, 51 bc ratings + name = 51
    User user;
    int countingVariable = 0;
    if (numUsersStored != 0)
    {
        countingVariable += numUsersStored;
    }
    //string userRatings[maxColumns];
    
    int numUsersAdjusted = numUsersStored - 1;
    if (numUsersStored == usersArrSize)
    {
        return -2;
    }
    
    if (myfile.is_open())
    {
        int j = 0;
        string line = ""; //empty string to contain the extracted line in the file 
    
        while (getline(myfile, line))//line for each line in the file
        {
            user = User(); //declaration of instance of user object made for each line.
             if ((numUsersStored == 99) || (numUsersAdjusted >= usersArrSize))
            {
                return numUsersStored;
            }
    
            if(line != "")
                {
                    split(line, ',', str, usersArrSize);
                    numUsersAdjusted++;
                    if (numUsersAdjusted >= usersArrSize)
                    {
                        return numUsersAdjusted;
                    }
                    user.setUsername(str[0]);
                    users[numUsersAdjusted] = user;
                    if (numUsersStored < usersArrSize)
                    {
                        for (int j = 1; j < maxColumns + 1; j++)
                        {
                            if (str[j] != "")
                            {
                                //user.setNumRatings(stoi(str[j]));
                                
                                //cout << user.getNumRatings() << endl;
                                user.setRatingAt(j - 1, stoi(str[j]));
                                //ratings[j] = user.setRatingAt(j, stoi(str[j]));
                                //cout << " PART 2 STR{J]: " << str[j] << endl;
                            }
                        }
                        users[numUsersAdjusted] = user;
                        
                    }    
                }    
        }
        return numUsersAdjusted + 1;
        
    }
    else
    {
        return - 1;
    }
}