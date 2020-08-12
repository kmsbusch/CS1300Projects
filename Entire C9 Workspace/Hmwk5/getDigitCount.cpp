// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 5 - Problem #1
#include <iostream>
#include <string>
using namespace std;

/*
Algorithm: For each value in the string, check if it's ascii value is between 48 and 57. If it is, increment the variable and loop.
Input parameters: Number String
Output (prints to screen): None
Returns: integer value for the number of digits in the string
*/

int getDigitCount(string inputString) // function returns a int value, takes in a string
{
    int digitNum = 0; // variable that stores number of digits
    for (int i = 0; i < inputString.length(); i++) // loop beginning
    {
        if (((int)inputString[i] >= 48) && ((int)inputString[i] <= 57)) // check if ascii value in string is between 48 and 57 
        {
           digitNum += 1; // increment digitNum value
        }
    
    }
    return digitNum; // after loop finishes return int value.
}

int main()
{
    int digit1 = getDigitCount("12345");
    int digit2 = getDigitCount("465");
    cout << "digit1 = " << digit1 << endl;
    cout << "digit2 = " << digit2 << endl;
}