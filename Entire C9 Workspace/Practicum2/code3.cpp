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

string removeDigits(string digitString)
{
    int length = digitString.length();
    
    string newString = "";
    for (int i = 0; i < length; i++)
    {
        int letterAscii = int(digitString[i]);
        if ((letterAscii >= 65) && (letterAscii <= 90))
        {
            newString = newString + char(letterAscii);
        }
        else if ((letterAscii >= 97) && (letterAscii <= 122))
        {
            newString = newString + char(letterAscii);
        }
        else if (letterAscii == 32)
        {
            newString = newString + char(letterAscii);
        }
    }
    return newString;
}

int main()
{
    cout << removeDigits("Hello World") << endl;
    cout << removeDigits("123") << endl;
}