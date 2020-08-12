// CSCI1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 7 - Problem #9

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Book.h"
#include "User.h"
using namespace std;



//other helper functions...{
////////////////////////////////////////////////////////////////////////
// other helper functions... split 
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

//}


//////////////////////////////////////////////////////////////////////////

// readBooks area{

/* readBooks function
 * the function reads a book file from the text into book and author arrays
 *
 * @param: fileName, string, name of the book file
 * @param: titles, string array, titles of the books are stored
 * @param: authors, string array, authors of the books are stored
 * @param: numBookStored, int, the number of books currently stored in the arrays
 * @param: size, int, the size of the arrays (titles and authors)
 * @return: the number of books read into the array (number of lines in the file)
 *          or appropriate return code
 */

//////////////////////////////////////////////////////////////////////////
// ToDo: implement readBooksfunction

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

// your readBooks function goes here
//}

//////////////////////////////////////////////////////////////////////////

// readRatings area{
/* readRatings function
 * Read the user ratings from the file and store them
 * into users array and ratings array
 *
 * @param: fileName, string, the name of user rating file
 * @param: users, string array, the array of users
 * @param: ratings, int 2D array, the ratings of each user
 *         row i is user, and column j is a book.
 *         ratings[i][j] is the user_i rated book_j
 * @param: numUsers, int, the number of users currently stored in the array
 * @param: sizeRow, int, the number of rows in the 2D array (capacity)
 * @param: sizeCol, int, the number of column in the 2D array (capacity)
 * @return: the number of users in total or appropriate return code
 */

/*
Algorithm: 
Input parameters: 
Output (prints to screen): 
Returns: none
*/
 //////////////////////////////////////////////////////////////////////////
 // ToDo: implement readRatings function
 
 int readRatings (string fileName, User users[], int numUsersStored, int usersArrSize, int maxColumns)
{
    ifstream myfile;
    myfile.open(fileName);
    string str[51]; //string that split takes, 51 bc ratings + name = 51
    User user;
    int countingVariable = 0;
    if (numUsersStored != 0)
    {
        countingVariable += numUsersStored;
    }
    //string userRatings[maxColumns];
    
    int numUsersAdjusted = numUsersStored - 1;
    if (numUsersStored == usersArrSize)
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
             if ((numUsersStored == 99) || (numUsersAdjusted >= usersArrSize))
            {
                return numUsersStored;
            }
    
            if(line != "")
            {
                split(line, ',', str, usersArrSize);
                numUsersAdjusted++;
                if (numUsersAdjusted >= usersArrSize)
                {
                    return numUsersAdjusted;
                }
                user.setUsername(str[0]);
                users[numUsersAdjusted] = user;
                if (numUsersStored < usersArrSize)
                {
                    for (int j = 1; j < maxColumns + 1; j++)
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

 // your readRatings function goes here
 
 //}
 
 //////////////////////////////////////////////////////////////////////////

// printAllBooks area{
/* printBookList function (helper function)
 * print the list of books in the array
 *
 * @param: titles, string, the title of books
 * @param: authors, string, the author of books
 * @param: numBooks, int, the number of books
 * @return: void
 */


//////////////////////////////////////////////////////////////////////////
// ToDo: implement printAllBooks functionvoid printAllBooks(string titles[], string authors[], int bookNum)
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

// your printAllBooks function goes here
//}

//////////////////////////////////////////////////////////////////////////

// getRating area{

/* getRating function 
 * Search for a rating given the user's name and 
 * book's title and return that value
 *
 * @param: string, username 
 * @param: string, title of the book 
 * @param: string, array, user names
 * @param: string, array, titles
 * @param: 2D int array, list of ratings for each user
 * @param: int, number of users whose names/ratings are currently 
 *         stored in the string array/2D array respectively
 * @param: int, number of books whose titles/ratings are currently 
 *         stored in the string array/2D array respectively
 * @return: int, users's rating value or appropriate return code
 */

//////////////////////////////////////////////////////////////////////////
// ToDo: implement getRating function
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
// your getRating function goes here
//}

//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
void displayMenu(){
  cout << "Select a numerical option:" << endl;
  cout << "======Main Menu=====" << endl;
  cout << "1. Read book file" << endl;
  cout << "2. Read user file" << endl;
  cout << "3. Print book list" << endl;
  cout << "4. Get rating" << endl;
  cout << "5. Quit" << endl;
}


int main(int argc, char const *argv[]) {

    // taking menu choice 
    string choice;

    // number of books and users stored in the arrays
    int numBooks = 0;
    int numUsers = 0;
    
    // Use the these values to declare your
    // titles, authors, users and ratings arrays
    const static int  userArrSize = 100;
    const static int  bookArrSize = 50;


    // variables to store user inputs 
    string bookFileName;
    string userFileName;
    string userName, bookTitle;    

    //my variables here
    Book books[bookArrSize];
    User users[userArrSize];
    
    while (choice != "5") {
        displayMenu();

        // take an opton (1, 2, 3, or 4)
        getline(cin, choice);

        // convert the `choice` to an integer 
        int menuChoice = stoi(choice); 
        switch (menuChoice) 
        {
            case 1:
                // read book file
                cout << "Enter a book file name:" << endl;
                getline(cin, bookFileName);

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                int choice1 = readBooks(bookFileName, books[], numBooks, bookArrSize);
                
                if (choice1 == -1)
                {
                    cout << "No books saved to the database." << endl;
                }
                else if (choice1 == -2)
                {
                    cout << "Database is already full. No books were added." << endl;
                }
                else if (choice1 == 50)
                {
                    cout << "Database is full. Some books may have not been added." << endl;
                }
                else if (numBooks < 50)
                {
                    cout << "Total books in the database: " << numBooks << endl;
                }
                //////////////////////////////////////////////////////////////////////////

                // Use the below messages and match them to the return code. Update variables as needed.
                // cout << "No books saved to the database." << endl;
                // cout << "Database is already full. No books were added." << endl;     
                // cout << "Database is full. Some books may have not been added." << endl;     
                // cout << "Total books in the database: " << numBooks << endl;
                
                cout << endl;
                break;

            case 2:
                // read ratings file
                cout << "Enter a user file name:" << endl;
                getline(cin, userFileName);

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                int choice2 = readRatings(fileName, users[], numUsersStored, usersArrSize, maxColumns);
                if (choice2 == -1)
                {
                    cout << "No users saved to the database." << endl;
                }
                else if (choice2 == -2)
                {
                    cout << "Database is already full. No users were added." << endl; 
                }
                else if (numUsersStored == 100)
                {
                    cout << "No users saved to the database." << endl;
                }
                else if (choice2 < 100)
                {
                    cout << "Total users in the database: " << numUsers << endl;
                }
                //////////////////////////////////////////////////////////////////////////

                // Use the below messages and match them to the return code. Update variables as needed.
                // cout << "No users saved to the database." << endl;
                // cout << "Database is already full. No users were added." << endl; 
                // cout << "Database is full. Some users may have not been added." << endl;
                // cout << "Total users in the database: " << numUsers << endl;

                cout << endl;
                break;

            case 3:
                // print the list of the books
                
                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                printAllBooks(books, bookNum);
                //////////////////////////////////////////////////////////////////////////

                cout << endl;
                break;

            case 4:
                // get user's rating 
                // take user name
                cout << "Enter username:" << endl;
                getline(cin, userName);

                // take book title 
                cout << "Enter book title:" << endl;
                getline(cin, bookTitle);

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                int choice3 = getRating(userName, bookTitle, users[], book[], numBooks, bookNum)
                if (choice3 = 0)
                {
                    cout << userName << " has not rated " << bookTitle << endl; 
                }
                else if (choice3 = -3)
                {
                    cout << userName << " or " << bookTitle << " does not exist" << endl;
                }
                else if (choice3 > 0)
                {
                    cout << userName << " rated " << bookTitle << " with " << rate << endl;
                }
                //////////////////////////////////////////////////////////////////////////

                // Use the below messages and match them to the return code. Update variables as needed.
                // cout << userName << " has not rated " << bookTitle << endl; 
                // cout << userName << " or " << bookTitle << " does not exist" << endl; 
                // cout << userName << " rated " << bookTitle << " with " << rate << endl; 


                cout << endl;
                break;
            case 5:
                // quit
                cout << "good bye!" << endl;
                break;

            default:
                cout << "invalid input" << endl;
        }
    }

    return 0;
}