// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 4 - Problem #5 
#include <iostream>
using namespace std;

/*
Algorithm: algorithm first checks if the number is less than zero, and multiplies it by -1 to make it a positive number.
Then it checks if number is greater than 99, if so, return 3. If greater than 9, return 2. If greater/equal to 0, return 1.
Input parameters: integer parameter.

Output (prints to screen): none

Returns: 3 or 2 or 1
*/

int countDigits(int myNum) //takes integer input
{
    if (myNum < 0) // checks if number is less than zero
    {
        myNum = myNum * -1; // multiplies number by -1 if negative in order to get positive value
    }
    if (myNum > 99)// check if larger than 99
    {
        return 3; // return 3 if above is true
    }
    else if (myNum > 9) // check if number is larger than 9
    {
        return 2; // return 2 if true
    }
    else if (myNum >= 0) // check if number is greater than or equal to 0
    {
        return 1; // return 1 if true
    }
}

int main()
{
    int digit1 = countDigits(976);
    int digit2 = countDigits(42);
    cout << digit1 << endl;
    cout << digit2 << endl;
}