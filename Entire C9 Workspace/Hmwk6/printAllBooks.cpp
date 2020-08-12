// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 6 - Problem #6
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Algorithm: check if booknum equals zero, if so, cout no book statement
2. otherwise cout books exist statement, and then cout list from array with for loop
Input parameters: string of book titles, string of authors, and int of bookNum
Output (prints to screen): cout books exist or not statement
Returns: none
*/

void printAllBooks(string titles[], string authors[], int bookNum)
{
    if (bookNum <= 0){
       cout << "No books are stored" << endl;
    }
    else{
        cout << "Here is a list of books" << endl;
        for (int i = 0; i < bookNum; i++){
            cout << titles[i] << " by " << authors[i] << endl;
        }
    }
}

int main()
{
    // no books stored with negative numBooks
    string book_titles[] = {};
    string book_authors[] = {};
    printAllBooks(book_titles, book_authors, -1);
}