// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 4 - Problem #4
#include <iostream>
using namespace std;

/*
Algorithm: output whether a square on a chess board is white or black. Does this by:
1. First checking whether the inputs are within the bounds of a-h and 1-8.
2. Convert the letter of the column into it's ascii value.
3. Use modulus functions on the Column letter values, and the row numbers to determine whether color is black or white. 

Input parameters: one letter input, one number input

Output (prints to screen): black, white, or not in the bounds.

Returns: none
*/

void chessBoard(char columnLetter, int rowNumber) // takes one character input and one int
{
    if (!(((int)columnLetter > 96) && ((int)columnLetter < 105)) || !((rowNumber > 0) && (rowNumber < 9))) // check if the char's ascii value is within a-h and if the int number is within 1-8.
    {
        cout << "Chessboard squares can only have letters between a-h and numbers between 1-8" << endl; // outputs if values aren't within a-h or 1-8
    }
        else if ((((int)columnLetter % 2 != 0) && (rowNumber % 2 != 0)) || ((int)(columnLetter % 2 == 0) && (rowNumber % 2 == 0))) // check if letter ascii value and number is odd, or if letter and number is even
        {
            cout << "black" << endl; // if true, output black
        }
            else if ((((int)columnLetter % 2 != 0) && (rowNumber % 2 == 0)) || ((int)(columnLetter % 2 == 0) && (rowNumber % 2 != 0))) // check if letter is odd and number is even or if letter is even and number is odd.
            {
                cout << "white" << endl; // output white if above is true
            }
}

int main()
{
    chessBoard('a', 23);
    chessBoard('e', 7);
}