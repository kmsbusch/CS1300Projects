// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 4 - Problem #6
#include <iostream>
using namespace std;

/*
Algorithm: Uses a switch statement to output hours per month, each month has a case with respective hours. 

Input parameters: integer parameter representing the month number.

Output (prints to screen): none

Returns: either 672, 744, or 720
*/

int countHours(int monthNum) // takes int input
{
    switch (monthNum) //switch statement calling int input
    {
        case 1: // if int input is 1
            return 744; // return 744
            break; 
        case 2: //if int is 2
            return 672; // return 672 
            break;
        case 3: // if int is 3
            return 744; // return 744
            break;
        case 4: // if int is 4
            return 720; // return 720
            break;
        case 5: // if int is 5
            return 744; // return 744
            break;
        case 6: // if int is 6
            return 720; // return 720
            break;
        case 7: // if int is 7
            return 744; // return 744
            break;
        case 8: // if int is 8
            return 744; // return 744
            break;
        case 9: // if int is 9
            return 720; // return 720
            break;
        case 10: // if int is 10
            return 744; // return 744
            break;
        case 11: // if int is 11
            return 720; // return 720
            break;
        case 12: // if int is 12
            return 744; // return 744
            break;
    }
}

int main()
{
    int month1 = countHours(9);
    int month2 = countHours(2);
    cout << "September has: " << month1 << " hours" << endl;
    cout << "February has: " << month2 << " hours" << endl;
}