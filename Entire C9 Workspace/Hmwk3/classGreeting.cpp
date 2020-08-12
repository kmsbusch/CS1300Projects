// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinbusch/csci1300
// Homework 3 - Problem #3
#include <iostream>
using namespace std;
/*
Algorithm: output specific text to screen with included value
Input: Course number (int)
Output (prints to screen): "Hello, CS (course number) World!"
Returns: none
*/
void classGreeting(int course_number)
{
    cout << "Hello, CS " << course_number << " World!" << endl; 
}

int main()
{
    classGreeting(13);
    classGreeting(192);
}