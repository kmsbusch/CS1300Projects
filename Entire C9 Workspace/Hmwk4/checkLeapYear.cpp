// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 4 - Problem #7
#include <iostream>
using namespace std;

/*
Algorithm: 1. check if year is divisible by 4 first, if not, return false. 
2. if year is divisible by 4, check if less than 1582, if so, return true. 
3. if greater than 1582 check if divisible by both 100 and 400. if so, return true. 
4. if greater than 1582 and divisible by 100 but not 400, return false. 
Input parameters: integer representing year number.

Output (prints to screen): none

Returns: boolean value true or false.
*/

int checkLeapYear(int yearNum) //takes int input
{
    if (yearNum % 4 != 0) // checks if number isn't divisible by 4
    {
        return false; // if true, return bool false
    }
    if (yearNum % 4 == 0) // checks if number is divisible by 4
    {
        if (yearNum < 1582) //checks if number is less than 1582
        {
            return true; // if true, return bool true
        }
        if (yearNum > 1582) // check if number is greater than 1582
        {
            if ((yearNum % 400 == 0) && (yearNum % 100 == 0)) // check if number is divisible by both 400 and 100
            {
                return true; // if true, return bool true
            }
            if ((yearNum % 100 == 0) && (yearNum % 400 != 0)) // check if number is divisible by 100 but not 400
            {
                return false; // if true, return bool false
            }
            
        }
    }
}
       
int main()
{
    int year1 = checkLeapYear(1337);
    int year2 = checkLeapYear(2000);
    cout << year1 << endl;
    cout << year2 << endl;
}
        


