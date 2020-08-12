// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 7 - Problem #5
#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
using namespace std;

/*
Algorithm: 
1.
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

int readBooks(string fileName, Book books[], int numBookStored, int booksArrSize) //numBookstored = # of books currently in arrays. size = capacity of the arrays
{
    ifstream myfile;
    myfile.open(fileName);
    int k = 0;
    int countingVariable = 0;
    Book book;
    if (numBookStored != 0)
    {
        countingVariable += numBookStored;
    }
    string line = "";
    
    if (numBookStored >= booksArrSize) //moved out to put higher priority than -1
    {
        return -2;
    }
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            
            if (line.length() != 0)
            {
                string str[line.length()];
                
                if (numBookStored < booksArrSize)
                {
                    split(line, ',', str, booksArrSize);
                    
                    book = Book();
                    
                    // authors[countingVariable] = str[k];
                    // titles[countingVariable] = str[k + 1];
                    book.setAuthor(str[k]);
                    book.setTitle(str[k + 1]);
                    
                    books[countingVariable] = book;
                    
                    countingVariable++;
                    numBookStored++;
                }
                if (numBookStored >= booksArrSize)
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
    Book books[50];
    // no books stored with numBooks 0
    readBooks("fileName.txt", books, 0, 50);
    cout << "checking if we can call the function" << endl;
    // Test non-exist file
    cout << readBooks("whatbook.txt", books, 0, 50) << endl;

}