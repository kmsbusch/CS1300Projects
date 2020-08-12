// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Algorithm: 
1.
Input parameters: 
Output (prints to screen): 
Returns: none
*/

int CountMtoZ (string letterCount)
{
    int length = letterCount.length();
    
    if (letterCount.length() == 0)
    {
        return -1;
    }
    int tallyNum = 0;
    for (int i = 0; i < length; i++)
    {
        int letterAscii = (int)letterCount[i];
        if ((letterAscii >= 77) && (letterAscii <= 90))
        {
            tallyNum++;
        }
    }
    if (tallyNum == 0)
    {
        tallyNum = -2;
    }
    return tallyNum;
}

int main()
{
    cout << CountMtoZ("MUENZINGER") << endl;
    
}