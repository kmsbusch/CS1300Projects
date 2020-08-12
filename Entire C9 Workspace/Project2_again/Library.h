// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project 2 - Problem #
#ifndef LIBRARY_H
#define LIBRARY_H


#include <iostream>
#include <fstream>
#include <string>




#include "Book.h"
#include "User.h"

using namespace std;

/*
Algorithm: 
1.
Input parameters: 
Output (prints to screen): 
Returns: none
*/

class Library
{
    
    public:
        Library(); //Sets both numBooks and numUsers to value 0.
        int getSizeBook(); //Returns sizeBook as an integer
        int getSizeUser(); //Returns sizeUser as an integer
        int getNumBooks(); //Returns numBooks as an integer
        int getNumUsers(); //Returns numUsers as an integer
        int readBooks(string); //Takes string (filename) & populates books array. Returns total # of books in books array as int
        int readRatings(string); //Takes string (filename) & populates users array. Returns total number users in users array as int.
        void printAllBooks(); //Prints all books stored in books array.
        int getCountReadBooks(string); //Takes string (username) & returns # books read by that user as an int.
        double calcAvgRating(string); //Takes string (title of book) & returns theavg rating of specified book as double
        int addUser(string); //Takes string (username) returns integer 1 if user successfully added, 0 if username already exists in users array -2 if users array already full.
        int checkOutBook(string, string, int); //Takes username, title of book, & new rating, respectively (in this order). Returns int 1 if rating successfully updated, -4 if rating value not valid & -3 if rating value is valid, but user or title doesnt exist in database.
        void viewRatings(string); //Takes string (username) & prints all books a user has provided ratings for.
        int getRating(string, string); //Takes 2 strings (username & book title) returns that user’s rating for the specified book.
        string getRecommendations(string); //Takes a string username and prints the first 5 book recommendations from the most similar (other) user.

    private:
        const static int sizeBook = 50; //The capacity of books array (50). Constant. Should this be static too, like the ones in hw7.cpp last week?
        const static int sizeUser = 100; //The capacity of users array (100). Constant. same question as above
        Book books[sizeBook]; //An array of Book objects. Is it best to put the number in here bc I know the size already?
        User users[sizeUser]; //An array of User objects. same question as above
        int numBooks; //number of books in the database (library).
        int numUsers; //number of users in the database (library).
};
#endif