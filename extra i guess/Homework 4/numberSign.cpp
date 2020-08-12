// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 4 - Problem #1
#include <iostream>
using namespace std;

/*
Algorithm: evaluate integer and output whether it is positive, negative, or zero

Input parameters: Integer value

Output (prints to screen): outputs whether value is positive, negative, or zero

Returns: none
*/

void numberSign(int numberinput) // void function takes number input
{
    if (numberinput > 0) // check if number inputted is greater than zero
    {
        cout << "positive" << endl; // output positive if above case is true
    }
    else if (numberinput == 0) //check if equal to zero
    {
        cout << "zero" << endl; //output zero if above is true
    }
    else if (numberinput < 0) // check if number is less than zero
    {
        cout << "negative" << endl; // output negative if above is true
    }
}

int main()
{
    numberSign(30);
    numberSign(-225);
}