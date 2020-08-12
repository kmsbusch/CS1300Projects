// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project 1 - Problem #1 
#include <iostream>
using namespace std;

/*
Algorithm: takes in n integer, assigns variable numReturn's value to 1. then sets loop where as long as numReturn is less than n, print the value and then add 2 to it, until it is equal to n. 
Input parameters: 
Output (prints to screen): 
Returns: none
*/


void printOddNums(int n) // function that takes in n
{
    int numReturn = 1; // variable numReturn has value 1
    while (numReturn <= n) // while numReturn is less than n
    {
       cout << numReturn << endl; // print value of numReturn 
       numReturn += 2; // add 2 to it.
       
    }
}

int main()
{
    printOddNums(11);
    cout << "" << endl;
    printOddNums(44);
}