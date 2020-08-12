// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 5 - Problem #3
#include <iostream>
#include <string>
using namespace std;

/*
Algorithm: 
Input parameters: 
Output (prints to screen): 
Returns: none
*/

int split(string splitString, char delimiter)
{
    int splitNum = 0;
    
    if (splitString == "")
    {
        splitNum = 0;
        return splitNum;
    }
    int letterCount = 0, sub = 0;  
    for (int i = 0; i < splitString.length(); i++)
    {
        if (splitString[i] != delimiter)
        {
            if(splitNum == 0){
                splitNum = 1;
            }
            letterCount++;
        }
        else 
        {
            
            string sub1 = splitString.substr((i - letterCount), i - sub);
            if(sub1.length() != 0){
              cout << sub1 << endl; 
                splitNum++;
            }
            sub = letterCount + sub + 1;
            letterCount = 0;

        }
        
    }
    
    string sub1 = splitString.substr((splitString.length() - letterCount),  splitString.length());
    cout << sub1 << endl;
    return (splitNum);
}

int main()
{
    int string1 = split("hi how are you doing", ' ');
    cout << string1 << endl;
    cout << split("I/don't/like/this", '/') << endl;
}