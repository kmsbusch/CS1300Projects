// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project 1 - Problem # 
#include <iostream>
using namespace std;

/*
Algorithm: 
Input parameters: 
Output (prints to screen): 
Returns: none
*/

void cardSuit(int cardIn)
{
    switch (cardIn)
    {
        case 0:
        cout << "Suit " << cardIn << ": Clubs" << endl;
        break;
        case 1:
        cout << "Suit " << cardIn << ": Diamonds" << endl;
        break;
        case 2:
        cout << "Suit " << cardIn << ": Spades" << endl;
        break;
        case 3:
        cout << "Suit " << cardIn << ": Hearts" << endl;
        break;
        default:
        cout << "Suit " << cardIn << ": Invalid" << endl;
        break;
    }
}