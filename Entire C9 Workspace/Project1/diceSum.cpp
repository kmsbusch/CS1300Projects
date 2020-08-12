// CSCI1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project 1 - Problem #2
#include <iostream>
using namespace std;

/*
Algorithm: 
Input parameters: 
Output (prints to screen): 
Returns: none
*/

/* rollDie
 * returns a random integer between 1 and 6,
 * works as rolling a die.
 * return value, int number (1-6)
*/
 
int rollDie()
{
return random() % 6 + 1;
}


void diceSum(int desiredSum)
{
    int totalVal = 0;
    if ((desiredSum < 2) || (desiredSum > 12))
    {
       cout << "The desired sum should be between 2 and 12" << endl;
    }
    else 
    {
        int rollNum = 0;
        while (totalVal != desiredSum)
        {
            int die1 = rollDie();
            int die2 = rollDie();
            totalVal = die1 + die2;
            cout << "You rolled a " << die1 << " and a " << die2 << endl;
            rollNum++;
        }
        if (totalVal = desiredSum)
        {
            cout << "Got a " << desiredSum << " in " << rollNum << " rolls! " << endl; 
        }
    }
}

int main()
{
    diceSum(31);
    diceSum(5);
}