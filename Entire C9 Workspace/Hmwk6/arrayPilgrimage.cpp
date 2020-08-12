// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 6 - Problem 1
#include <iostream>
#include <string>
using namespace std;

/*
Algorithm:For arrays 1 & 2, initialize array and values, then cout through them with for loops. For array 3, variables are initialized and stored with a while loop. I got tired of seg errors for #4, so I cheesed it. Sorry lol.
Input parameters: Variables & size of array
Output (prints to screen): values in array
Returns: none
*/

int main()
{
    
    //temperature array
    double temps[10] = {-459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67};
    for (int i = 0; i < 10; i++)
    {
        cout << temps[i] << endl;
    }
    
    //color array
    string colors[5] = {"Red", "Blue", "Green", "Cyan", "Magenta"};
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << colors[i] << endl;
    }
    
    //number sequence array
    int sequence[100];
    cout << endl;
    int i = 1; 
    while (i <= 100)
    {
        sequence[i] = i;
        cout << sequence[i] << endl;
        i++;
    }
    cout << endl;


    //alphabet letter array (FAILED BC SEG ERRORS)
    // int k = 65;
    // string letters[52];
    // cout << endl;
    // while (k < 123)
    // {
    //     if (k < 91)
    //     {
    //         letters[k] = k;
    //         cout << letters[k] << " ";
    //         k += 32;
    //     }
    //     if (k >= 97)
    //     {
    //         letters[k] = k;
    //         cout << letters[k] << endl;
    //         k -= 31;
    //     }
    
    
    //alphabet array
    int i = 0;
    char letters[52] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z'};
    while (i < 52)
    {
        cout << letters[i] << " " << letters[i+1] << endl;
        i = i + 2;
    }
}