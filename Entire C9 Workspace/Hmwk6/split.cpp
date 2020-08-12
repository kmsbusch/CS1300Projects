// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 6 - Problem #3
#include <iostream>
#include <string>
using namespace std;

/*
Algorithm: 
First, if empty, return 0.
1. make empty string to store each split.
2. int j to store number of splits
3. add delimiter to string so it won't overflow.
4. within the for loop, if the character of string = delimiter, reset word.length to 0, and assign what was in word to the array index of j. then increment j so it counts a word.
5. if character isn't the delimiter, it adds the character to the string and moves on. 
Input parameters: string str, char c used as delimiter, string array to keep each of the splits, int that defines arrayLength
Output (prints to screen): none
Returns: return number of splits
*/

int split(string str, char c, string words[], int arrayLength)
{
    if (str.length() == 0) {
        return 0;
    }
    string word = "";
    int j = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c) 
        {
        	if (word.length() == 0) continue;
            words[j] = word;
            j++;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return j;
}

int main()
{
    string words[4];
    cout << split("hi how are you", ' ', words, 4) << endl;
    for (int m = 0; m < 4; m++)
    {
        cout << words[m] << endl;
    }
}