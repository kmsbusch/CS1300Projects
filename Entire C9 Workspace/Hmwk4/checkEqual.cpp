// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 4 - Problem # 
#include <iostream>
using namespace std;

/*
Algorithm: check if num1 is equal to num2, and if num2 equals num3, if so then num1 must equal num3. Print all same. 
Then check if all of them aren't equal and if so, output all different. If not, output neither.

Input parameters: 3 integer values

Output (prints to screen): output whether the numbers are same different or neither

Returns: none
*/

void checkEqual(int num1, int num2, int num3) // takes in 3 numbers to compare
{
    if (num1 == num2 && num2 == num3) // checks if num1 is equal to num2 and if num2 is equal to num3
    {
        cout << "All same" << endl; // outputs all same if above is true
    }
    else if  ((num1 != num2) && (num2 != num3) && (num3 != num1)) // checks if the numbers are all not equal to each other
    {
        cout << "All different" << endl; // outputs all different if above is true
    }
    else 
    {
        cout << "Neither" << endl; // if neither above statements is true, output neither. 
    }
}

int main()
{
    checkEqual(14, 14, 14);
    checkEqual(12, 14, 167);
}