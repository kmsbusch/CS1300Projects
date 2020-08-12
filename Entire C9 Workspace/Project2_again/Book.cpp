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

Book::Book()
{
    title = "";
    author = "";
}
Book::Book(string bookTitle, string bookAuthor)
{
    title = bookTitle;
    author = bookAuthor;
}
void Book::setTitle(string bookTitle)
{
    title = bookTitle;
}
string Book::getTitle()
{
    return title;
}
void Book::setAuthor(string bookAuthor)
{
    author = bookAuthor;
}
string Book::getAuthor()
{
    return author;
}


