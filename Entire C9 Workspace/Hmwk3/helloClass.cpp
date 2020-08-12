// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinbusch/csci1300
// Homework 3 - Problem #2
#include <iostream>
using namespace std;
/*
Algorithm: Output specific text to screen with a changing element in the text. 
Input parameters: Class number (integer)
Output (prints to screen): "Hello, CS (class number here) World!"
Returns: none
*/
int main()
{
    cout <<"Enter a CS course number: " <<endl;
    int class_number;
    cin >> class_number;
    cout <<"Hello, CS " << class_number <<" World!" << endl;    
}