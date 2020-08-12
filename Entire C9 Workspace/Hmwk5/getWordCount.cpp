// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 5 - Problem #2
#include <iostream>
#include <string>
using namespace std;

/*
Algorithm: Look for spaces in the string and increment the variable everytime one is encountered.
Input parameters: Sentence string 
Output (prints to screen): None
Returns: Number of words stored in variable.
*/

int getWordCount(string sentence) //Returns int of how many words in the string. Takes in string to count.
{
    int wordNum = 1; //variable that stores word count
    if (sentence.length() == 0) // if statement for if the string doesn't have any words in it.
        {
            wordNum -= 1; //subtracts one from the wordNum variable to put it at zero, because there aren't any words in the string
        }
    for (int i = 0; i < sentence.length(); i++) // loop beginnng
    {
        
        if ((int)sentence[i] == 32) //if statement for if a space is ran into in the string, it increments the word count
        {
           wordNum += 1; //actual increment
        }
    }
    return wordNum; //return number of words found in the string.
}

int main()
{
    cout << getWordCount("When this doesn't work it hurts my head") << endl;
    cout << getWordCount("Please just work ffs") << endl;
}
