// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 7 - Problem #3
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

int main()
{
    // checking setter for author
    Book b3 = Book();
    string a = "is this author?";
    b3.setAuthor(a);
    cout << b3.getAuthor() << endl;
    
    string title = "Check parameterized constructor title";
    string author = "Check parameterized constructor author";
    Book b4 = Book(title, author);
    cout << b4.getTitle() << endl;
    cout << b4.getAuthor() << endl;
}