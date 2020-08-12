// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 7 - Problem #3
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
#ifndef BOOK_H
#define BOOK_H


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

class Book
{
    
public:
    
    Book(); //default constructor
    Book(string, string); //parameterized constructor 
    void setTitle(string); //setter for title
    string getTitle(); //getter for title
    void setAuthor(string); //setter for author 
    string getAuthor(); //getter for author

private:
    string title;
    string author;
};
#endif