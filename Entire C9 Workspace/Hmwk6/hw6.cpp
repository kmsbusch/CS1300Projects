// CSCI1300 Spring 2019
// Author: <Your name>
// Recitation: <123> – <Your TA name>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/ .....>
// hmwk6 


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;



//////////////////////////////////////////////////////////////////////////
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

int searchFunc(string arr[], int storageMax, string target)
{
    string makeLower(string x);
    string temp = makeLower(arr[0]);
    string test = makeLower(target);
    int h = 0;
    while(temp != test && h < storageMax)
    {   
        h++;
        if(h<storageMax)
            temp = makeLower(arr[h]);
    }
    if (h == storageMax)
    {
        return -3;
    }
    return h;
}


string makeLower(string nameIn)
{
    int length = nameIn.length();
    for (int i = 0; i < length; i++)
    {
        int m = nameIn[i];
        if (!islower(m))
        {
            nameIn[i] = tolower(m);
        }
        else
        {
            nameIn[i] = tolower(m);
        }
    }
    return nameIn;
}
//////////////////////////////////////////////////////////////////////////


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

int readBooks(string fileName, string titles[], string authors[], int numBookStored, int size) //numBookstored = # of books currently in arrays. size = capacity of the arrays
{
    ifstream myfile;
    myfile.open(fileName);
    int k = 0;
    int countingVariable = 0;
    if (numBookStored != 0)
    {
        countingVariable += numBookStored;
    }
    string line = "";
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            
            if (line.length() != 0)
            {
                string str[line.length()];
                
                if (numBookStored == size)
                {
                    return -2;
                }
                if (numBookStored < size)
                {
                    split(line, ',', str, size);
                    authors[countingVariable] = str[k];
                    titles[countingVariable] = str[k + 1];
                    countingVariable++;
                    numBookStored++;
                }
                if (numBookStored >= size)
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
//////////////////////////////////////////////////////////////////////////


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

 //////////////////////////////////////////////////////////////////////////
 // ToDo: implement readRatings function
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

/*
Algorithm: 
Input parameters: 
Output (prints to screen): 
Returns: none
*/
int readRatings (string fileName, string users[], int ratings[][50], int numUsers, int maxRows, int maxColumns)
{
    ifstream myfile;
    myfile.open(fileName);
    string str[100]; //string that split takes, 51 bc ratings + name = 51
    
    int ratingCount = 0;
    
    string userRatings[maxColumns];
    
    int rowShift = numUsers - 1;
    //int userShift = maxRows - 1;
    if (numUsers == maxRows)
    {
        return -2;
    }
    
    if (myfile.is_open())
    {
        string line = ""; //empty string to contain the extracted line in the file 
    
        while (getline(myfile, line))//line for each line in the file
        {
            if (numUsers == (maxRows - 1))      //////////////////////////////////////////////////
            {
                return numUsers;
            }
    
            if(line != "")
                {
                    split(line, ',', str, maxRows);
                    rowShift++;
                    if (rowShift >= maxRows)
                    {
                        return rowShift;
                    }
                    users[rowShift] = str[0];
                    if (numUsers < maxRows)
                    {
                        for (int j = 1; j < maxColumns + 1; j++)
                        {
                            if (str[j] != "")
                            {
                                ratings[rowShift][j-1] = stoi(str[j]);
                            }
                        }
                    }    
                }    
        }
        return rowShift + 1;
    }else
    {
        return -1;
    }
}
 // your readRatings function goes here
 //////////////////////////////////////////////////////////////////////////

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
void printAllBooks(string titles[], string authors[], int bookNum)
{
    if (bookNum == 0){
       cout << "No books are stored" << endl;
    }
    else{
        cout << "Here is a list of books" << endl;
        for (int i = 0; i < bookNum; i++){
            cout << titles[i] << " by " << authors[i] << endl;
        }
    }
}

// your printAllBooks function goes here
//////////////////////////////////////////////////////////////////////////

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
// your getRating function goes here
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

    while (choice != "5") {
        displayMenu();

        // take an opton (1, 2, 3, or 4)
        getline(cin, choice);

        // convert the `choice` to an integer 
        int menuChoice = stoi(choice); 
        switch (menuChoice) {
            case 1:
                // read book file
                cout << "Enter a book file name:" << endl;
                getline(cin, bookFileName);

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
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