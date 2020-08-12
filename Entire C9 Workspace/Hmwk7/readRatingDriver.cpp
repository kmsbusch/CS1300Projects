// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 7 - Problem #8
#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
#include "Book.h"
using namespace std;



/*
Algorithm: 
1.
Input parameters: 
Output (prints to screen): 
Returns: none
*/

string makeLower(string nameIn) //was string originally but changed to void bc it isn't returning nameIn string anymore but storing it instead
{
    // User user;
    // user = User();
    int length = nameIn.length(); //stores length of input string so it can limit for loop
    for (int i = 0; i < length; i++) //loop through string
    {
        int m = nameIn[i]; //assign character of string to variable (ascii value of letter)
        nameIn[i] = tolower(m); // tolower func makes m lowercase and then character of nameIn string is assigned to that value
    }
    return nameIn; // return the new lowercase string
    // user.setUsername(nameIn); //new lowercase username is stored in user object
}


//func searches array to see if 
int searchUserFunc(User users[], int storageMax, string target) //string arr[] is array to be searched, storageMax is arr size, string target is the string to be found
{
    string temp = makeLower(users[0].getUsername()); //assigns first indexed string in arr[] variable string temp (after using makeLower func on it)
    string test = makeLower(target); //assigns lowercase target string to variable string test
    int h = 0; //h keeps count of times through loop
    while(temp != test && h < storageMax) // while the strings don't match (meaning target hasn't been found), and still within arr bounds
    {   
        h++; //increment here because before this, arr index was set to zero so that while case would run, and it would default to look for first term
        if(h<storageMax) // if still in array bounds
            temp = makeLower(users[h].getUsername()); //checks rest of array by reassigning temps value, and then it'll be checked by while statement
    }
    if (h == storageMax) //if at end of array and target not found, return -3
    {
        return -3;
    }
    return h; //otherwise, return index where target was found
}

int searchBookFunc(Book books[], int storageMax, string target) //string arr[] is array to be searched, storageMax is arr size, string target is the string to be found
{
    string temp = makeLower(books[0].getTitle()); //assigns first indexed string in arr[] variable string temp (after using makeLower func on it)
    string test = makeLower(target); //assigns lowercase target string to variable string test
    int h = 0; //h keeps count of times through loop
    while(temp != test && h < storageMax) // while the strings don't match (meaning target hasn't been found), and still within arr bounds
    {   
        h++; ////increment here because before this, arr index was set to zero so that while case would run, and it would default to look for first term
        if(h<storageMax) // if still in array bounds
            temp = makeLower(books[h].getTitle()); //checks rest of array by reassigning temps value, and then it'll be checked by while statement
    }
    if (h == storageMax) //if at end of array and target not found, return -3
    {
        return -3;
    }
    return h; //otherwise, return index where target was found
}





//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

int getRating(string username, string titleOfBook, User users[], Book books[], int userCount, int bookCount)
{
    User user;
    Book book;
    
    int i = searchUserFunc(users, userCount, username);
    int j = searchBookFunc(books, bookCount, titleOfBook);
    if ((i == -3) || (j == -3))
    {
        return -3;
    }
    else
    {
        //return rating[i][j];
        return users[i].getRatingAt(j);
    }
    
   
}