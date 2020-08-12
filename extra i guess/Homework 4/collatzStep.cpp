// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 4 - Problem #2
#include <iostream>
using namespace std;

/*
Algorithm: check if integer is less than zero, if so, return 0. If not, check if divisible by 2 with no remainder. 
If so, / by 2 and return. If not, multiply integer by 3 and add 1, then return. 

Input parameters: integer value

Output (prints to screen): none

Returns: integer value
*/

int collatzStep(int numIn) // takes in integer 
{
    if (numIn < 0) // check if number is less than zero
    {
        return 0; // return zero if above is true
    }
    else if (numIn % 2 == 0) // check if the number divides by 2 evenly (checks if it is an even number)
    {
        numIn = numIn / 2; // divide by 2 because number is even
        return numIn; // return new value of number
    }
    else if (numIn % 2 != 0) // check if number is odd
    {
        numIn = (3 * numIn) + 1; // multiply number by 3 and add one because number is odd
        return numIn; // return new value of number
    }
}

int main()
{
    int step1 = collatzStep(123);
    int step2 = collatzStep(6);
    cout << step1 << endl;
    cout << step2 << endl;
}