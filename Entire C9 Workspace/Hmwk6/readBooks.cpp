// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 6 - Problem #5
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Algorithm: split
Input parameters: 
Output (prints to screen): 
Returns: none
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



/*
Algorithm: readBooks
Input parameters: 
Output (prints to screen): 
Returns: none
*/

int readBooks(string fileName, string titles[], string authors[], int numBookStored, int size) //numBookstored = # of books currently in arrays. size = capacity of the arrays
{
    ifstream myfile;
    myfile.open(fileName);
    int k = 0;
    int countingVariable = 0;
    if (numBookStored != 0)
    {
        countingVariable += numBookStored;
    }
    string line = "";
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            
            if (line.length() != 0)
            {
                string str[line.length()];
                
                if (numBookStored == size)
                {
                    return -2;
                }
                if (numBookStored < size)
                {
                    split(line, ',', str, size);
                    authors[countingVariable] = str[k];
                    titles[countingVariable] = str[k + 1];
                    countingVariable++;
                    numBookStored++;
                }
                if (numBookStored >= size)
                {
                    return numBookStored;
                    break;
                }
            }
        }
        return numBookStored;
    }
    if (!myfile.is_open())
    {
        return -1;
    }
}

int main()
{
    string titles[15];
    string authors[15];
    cout << readBooks("books1.txt", titles, authors, 0, 15) << endl;
    for (int m = 0; m < 50; m++)
    {
        cout << "authors: " << authors[m] << " title: " << titles[m] << endl;
    }
}