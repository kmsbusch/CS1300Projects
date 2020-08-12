// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 7 - Problem #6
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Algorithm: 
1.
Input parameters: 
Output (prints to screen): 
Returns: none
*/

void printAllBooks(Book books[], int bookNum)
{
    
    if (bookNum <= 0){
       cout << "No books are stored" << endl;
    }
    else{
        cout << "Here is a list of books" << endl;
        for (int i = 0; i < bookNum; i++){
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
        }
    }
}










