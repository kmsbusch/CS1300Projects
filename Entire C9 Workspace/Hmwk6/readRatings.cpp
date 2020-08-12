// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 6 - Problem #7
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Algorithm: 
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

/*
Algorithm: 
Input parameters: 
Output (prints to screen): 
Returns: none
*/
int readRatings (string fileName, string users[], int ratings[][50], int numUsers, int maxRows, int maxColumns)
{
    ifstream myfile;
    myfile.open(fileName);
    string str[100]; //string that split takes, 51 bc ratings + name = 51
    
    int ratingCount = 0;
    
    string userRatings[maxColumns];
    
    int rowShift = numUsers - 1;
    //int userShift = maxRows - 1;
    if (numUsers == maxRows)
    {
        return -2;
    }
    
    if (myfile.is_open())
    {
        string line = ""; //empty string to contain the extracted line in the file 
    
        while (getline(myfile, line))//line for each line in the file
        {
            if (numUsers == (maxRows - 1))      //////////////////////////////////////////////////
            {
                return numUsers;
            }
    
            if(line != "")
                {
                    split(line, ',', str, maxRows);
                    rowShift++;
                    if (rowShift >= maxRows)
                    {
                        return rowShift;
                    }
                    users[rowShift] = str[0];
                    if (numUsers < maxRows)
                    {
                        for (int j = 1; j < maxColumns + 1; j++)
                        {
                            if (str[j] != "")
                            {
                                ratings[rowShift][j-1] = stoi(str[j]);
                            }
                        }
                    }    
                }    
        }
        return rowShift + 1;
    }else
    {
        return -1;
    }
}

int main()
{
    // check return value after reading the file
    string users[10] = {};
    int ratings[10][50] = {{0}};
    int numUsers = 0;
    int maxRows = 10;
    int maxColumns = 50;
    cout << readRatings("ratings.txt", users, ratings, numUsers, maxRows, maxColumns) << endl;
}

