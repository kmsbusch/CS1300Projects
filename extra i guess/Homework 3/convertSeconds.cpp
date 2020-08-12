// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinbusch/csci1300
// Homework 3 - Problem #7
#include <iostream>
#include <math.h>
using namespace std;
/*
Algorithm: convert seconds to count of hours, minutes, and seconds. Done by dividing from initial second count and then subtracting.
Input: seconds (integer)
Output (prints to screen): hours, minutes, and seconds
Returns: none
*/
void convertSeconds(int secondsin)
{
    int mincount;
    int hrcount;
    
    hrcount = secondsin / 3600;
    secondsin -= hrcount * 3600;
    mincount = secondsin / 60;
    secondsin -= mincount * 60;
    
    cout << hrcount << " hour(s) " << mincount << " minute(s) " << secondsin << " second(s)" << endl;
}

int main()
{
    convertSeconds(21023);
    convertSeconds(3192);
}