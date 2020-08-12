// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project 2 - Problem #
#include <iostream>
#include <fstream>
#include <string>
#include "Library.h"
using namespace std;

/*
Algorithm: 
1.
Input parameters: 
Output (prints to screen): 
Returns: none
*/
////////////////////////// HELPER FUNCTIONS ////////////////////////{
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
////////////////////////////////////////////////////////////////////}


Library::Library() //Sets both numBooks and numUsers to value 0.
{
    numBooks = 0;
    numUsers = 0;
}

int Library::getSizeBook() //GETTER - Returns sizeBook as an integer
{
    return sizeBook;
}

int Library::getSizeUser() //GETTER - Returns sizeUser as an integer
{
    return sizeUser;
}

int Library::getNumBooks() //GETTER - Returns numBooks as an integer
{
    return numBooks;
}

int Library::getNumUsers() //GETTER - Returns numUsers as an integer
{
  
    return numUsers;
}

int Library::readBooks(string fileName) //GETTER - Takes string (filename) & populates books array. Returns total # of books in books array as int
{
    ifstream myfile;
    myfile.open(fileName);
    //int k = 0;
    int countingVariable = 0;
    Book book;
    if (numBooks != 0)
    {
        countingVariable += numBooks;
    }
    string line = "";
    
    if (numBooks >= 50) //moved out to put higher priority than -1
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
                    book.setAuthor(str[0]);
                    book.setTitle(str[1]);
                    
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

int Library::readRatings(string fileName) //GETTER - Takes string (filename) & populates users array. Returns total number users in users array as int.
{
    ifstream myfile;
    myfile.open(fileName);
    string str[51]; //string that split takes, 51 bc ratings + name = 51
    User user;
    int countingVariable = 0;
    if (numUsers != 0)
    {
        countingVariable += numUsers;
    }
    
    int numUsersAdjusted = numUsers - 1;
    if (numUsers == 100)
    {
        return -2;
    }
    
    if (myfile.is_open())
    {
        int j = 0;
        string line = ""; //empty string to contain the extracted line in the file 
    
        while (getline(myfile, line))//line for each line in the file
        {
            user = User(); //declaration of instance of user object made for each line.
             if ((numUsers == 99) || (numUsersAdjusted >= 100))
            {
                return numUsers;
            }
    
            if(line != "")
            {
                split(line, ',', str, 100);
                numUsersAdjusted++;
                if (numUsersAdjusted >= 100)
                {
                    return numUsersAdjusted;
                }
                user.setUsername(str[0]);
                users[numUsersAdjusted] = user;
                if (numUsers < 100)
                {
                    for (int j = 1; j < 51; j++)
                    {
                        if (str[j] != "")
                        {
                            //user.setNumRatings(stoi(str[j]));
                            
                            //cout << user.getNumRatings() << endl;
                            user.setRatingAt(j - 1, stoi(str[j]));
                            //ratings[j] = user.setRatingAt(j, stoi(str[j]));
                        }
                    }
                    users[numUsersAdjusted] = user;
                    
                }    
            }    
        }
        return numUsersAdjusted + 1;
        
    }
    else
    {
        return - 1;
    }
}

int Library::getRating(string userName, string bookTitle)
{
    User user;
    Book book;
    
    int i = searchUserFunc(users, numUsers, userName);
    int j = searchBookFunc(books, numBooks, bookTitle);
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

void Library::printAllBooks()
{
    
    if (numBooks <= 0){
       cout << "No books are stored" << endl;
    }
    else{
        cout << "Here is a list of books" << endl;
        for (int i = 0; i < numBooks; i++){
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
        }
    }
}

int Library::getCountReadBooks(string username)
{
    User user;
    Book book;
    
    int i = searchUserFunc(users, numUsers, userName);
    int j = searchBookFunc(books, numBooks, bookTitle);
    if ((i == -3) || (j == -3))
    {
        return -3;
    }
    else 
    {
        int rateCount = users[i].getNumRatings(j); //this stores ratings but includes zeros, so assign to variable to use in loop
        int actualCount = 0;
        for (int k = 0; k < actualCount; k++)
        {
            if (users[i].getRatingAt(j) != 0) //is j the right variable to use here? it is the index of the book search that was returned so i think thats right
            {
                actualCount++;
            }
        }
        return actualCount++;
    }
}


bool isGoodRatings(User users, int numRatings) //helper to check wheter there are any books that have been rated
{
    for (int i == 0; i < numRatings; i++)
    {
        if books[i] > 0; //doesn't this not work because if it runs into any book that hasnt been rated, it will return a false?
            return true;
    }
    return false;
}

void Library::viewRatings(string userName)
{   
    User user;
    Book book;
    
    
    int i = searchUserFunc(users, numUsers, userName);
    int j = searchBookFunc(books, numBooks, bookTitle);
    
    
    if (i == -3)
    {
        cout << userName << " does not exist." << endl;
    }
    else if (isGoodRatings(books, users[i].getNumRatings()))
    {
        int rateCount = users[i].getNumRatings(j); //this stores ratings but includes zeros, so assign to variable to use in loop
        cout << "Here are the books " << userName << " rated" << endl;
        for (int k = 0; k < rateCount; k++)
        {
            if (users[i].getRatingAt(k) != 0) //this might need to be chenged to variable n2s
            {
                cout << "Title : " << books[k].getTitle() << endl;
                cout << "Rating : " << users[k].getRating() << endl;
                cout << "-----" << endl;
            }
        }
    }
    else
    {
        cout << userName << " has not rated any books yet." << endl;
    }
}





// double Library::calcAvgRating(string bookTitle)
// {
//     //idk how to do this
//     //just dont know how to take in the ratings, after that its going to add them, and increment a  counting variable that divides by at end.
//     return avgRating;
// }

// int Library::addUser(string username)
// {
    
// }