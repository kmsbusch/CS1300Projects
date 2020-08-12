// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 6 - Problem #8
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Algorithm: 
Input parameters: 
Output (prints to screen): 
Returns: none
*/

string makeLower(string nameIn)
{
    int length = nameIn.length(); //stores length of input string so it can limit for loop
    for (int i = 0; i < length; i++) //loop through string
    {
        int m = nameIn[i]; //assign character of string to variable (ascii value of letter)
        if (!islower(m)) //if variable ascii isn't a lowercase
        {
            nameIn[i] = tolower(m); // tolower func makes m lowercase and then character of nameIn string is assigned to that value
        }
        else
        {
            nameIn[i] = tolower(m); // even if it is lower, this makes sure that it is lower anyway
        }
    }
    return nameIn; // return the new lowercase string
}

int searchFunc(string arr[], int storageMax, string target)
{
    string temp = makeLower(arr[0]);
    //cout << arr[0] <<" 0 here " << endl;
    string test = makeLower(target);
    int h = 0;
    while(temp != test && h < storageMax)
    {   
        h++;
        if(h<storageMax)
            temp = makeLower(arr[h]);
            //cout << arr[h] << "ree" << endl;
    }
    if (h == storageMax)
    {
        return -3;
    }
    return h;
}




int getRating (string username, string titleOfBook, string users[], string titles[], int rating[100][50], int userCount, int bookCount)
{
    int i = searchFunc(users, userCount, username);
    int j = searchFunc(titles, bookCount, titleOfBook);
    if ((i == -3) || (j == -3))
    {
        return -3;
    }
    else{
        return rating[i][j];
    }
    
   
}

int main()
{
    // //userName and bookTitle exist - mixed up upper and lower case in userName, non zero rating
    // int testRatings[100][50] = {{0,1,2,3},{4,5,5,1},{3,3,3,0},{3,2,1,5},{5,2,4,3}};
    // cout << getRating("bOnNIe", "Three Men In a Boat", testUsers, testTitles, testRatings, 5, 4) << endl;
    
    string users[100] = {"User1", "User2"};
    string titles[50] = {"Title1", "Title2", "Title3"};
    int ratings[100][50] = {{1,4,2},{0,5,3}};
    	
    cout << getRating("User1", "Title2", users, titles, ratings, 100, 50);
}