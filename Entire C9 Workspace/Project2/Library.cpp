// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project 2 - Problem #
#include <iostream>
#include <fstream>
#include <string>

#include "Book.h"
#include "User.h"

#include "Library.h"


using namespace std;

/*
Algorithm: 
1.
Input parameters: 
Output (prints to screen): 
Returns: none
*/


// HELPER FUNCTIONS {
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
    int h = 0; //h keeps count of times through loop
    if (users[0].getUsername() != "")
    {
        string temp = makeLower(users[0].getUsername()); //assigns first indexed string in arr[] variable string temp (after using makeLower func on it)
        string test = makeLower(target); //assigns lowercase target string to variable string test
        
        while(temp != test && h < storageMax) // while the strings don't match (meaning target hasn't been found), and still within arr bounds
        {   
            h++; //increment here because before this, arr index was set to zero so that while case would run, and it would default to look for first term
            if(h < storageMax) // if still in array bounds
                temp = makeLower(users[h].getUsername()); //checks rest of array by reassigning temps value, and then it'll be checked by while statement
        }
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

bool isGoodRatings(User user, int numRatings)
{
    for (int i = 0; i < numRatings; i++)
    {
        if (user.getRatingAt(i) > 0) //this checks to find if there is at least one rating.
            return true;
    }
    return false;
}




////////////////////////////////////////////////////////////////////}

// EVERYTHING UP TO GETRATING {
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
        //int numBookStored = 0;
        while (getline(myfile, line))
        {
            
            if (line.length() != 0)
            {
                string str[line.length()];
                
                if (numBooks < sizeBook)
                {
                    split(line, ',', str, sizeBook);
                    
                    book = Book();
                    
                    // authors[countingVariable] = str[k];
                    // titles[countingVariable] = str[k + 1];
                    book.setAuthor(str[0]);
                    book.setTitle(str[1]);
                    
                    books[countingVariable] = book;
                    
                    countingVariable++;
                    numBooks++;
                }
                if (numBooks >= sizeBook)
                {
                    return numBooks;
                    break;
                }
            }
        }
        return numBooks;
    }
    // if (!myfile.is_open())  // Since you check is_open above, don't need to check not case. This avoids a warning about return type.
    // {
    return -1;
    // }
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
    
    // int numUsersAdjusted = numUsers - 1;
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
            int ratingNum = 0;
            if (numUsers == 100)
            {
                return numUsers;
            }
    
            if(line != "")
            {
                ratingNum = split(line, ',', str, 100) - 1;
                 
                if (numUsers >= 100)
                {
                    return numUsers;
                }
                user.setUsername(str[0]);
                users[numUsers] = user;
                if (numUsers < 100)
                {
                    for (int j = 1; j < 51; j++)
                    {
                        if (str[j] != "")
                        {
                            //user.setNumRatings(stoi(str[j]));
                            
                            //cout << user.getNumRatings() << endl;
                            user.setRatingAt(j - 1, stoi(str[j]));
                            user.setNumRatings(ratingNum);
                            //ratings[j] = user.setRatingAt(j, stoi(str[j]));
                        }
                    }
                    users[numUsers] = user;
                    numUsers++;
                    
                }    
            }    
        }
        return numUsers; //Adjusted + 1;
        
    }
    else
    {
        return - 1;
    }
}

//}

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

// GETCOUNTREADBOOKS - CALCAVGRATING {

int Library::getCountReadBooks(string userName)
{
    User user;
    Book book;
    
    int i = searchUserFunc(users, sizeUser, userName);
    // int j = searchBookFunc(books, numBooks, bookTitle);
    if (i == -3)
    {
        return -3;
    }
    else 
    {
        int rateCount = users[i].getNumRatings(); //this stores ratings but includes zeros, so assign to variable to use in loop
        int minusCount = 0;
        for (int k = 0; k < rateCount; k++)
        {
            int checkNonZero = users[i].getRatingAt(k);
            if (checkNonZero == 0) //is j the right variable to use here? it is the index of the book search that was returned so i think thats right
            {
                minusCount++;
            }
        }
        return rateCount - minusCount;
    }
}

void Library::viewRatings(string userName)
{   
    User user;
    Book book;
    
    
    int i = searchUserFunc(users, numUsers, userName);
    // int j = searchBookFunc(books, numBooks, bookTitle);
    
    
    if (i == -3)
    {
        cout << userName << " does not exist." << endl;
    }
    else if (isGoodRatings(users[i], users[i].getNumRatings()))
    {
        int rateCount = users[i].getNumRatings(); //this stores ratings but includes zeros, so assign to variable to use in loop
        
        cout << "Here are the books that " << userName << " rated" << endl;
        
        for (int k = 0; k < rateCount; k++)
        {
            if (users[i].getRatingAt(k) != 0) //this might need to be chenged to variable n2s
            {
                cout << "Title : " << books[k].getTitle() << endl;
                cout << "Rating : " << users[i].getRatingAt(k) << endl;
                cout << "-----" << endl;
            }
        }
    }
    else
    {
        cout << userName << " has not rated any books yet." << endl;
    }
}


// Algorithm:
// bookTitle is input
// int totalRatings = 0
// for each user in users, 
//   find the index of rating for bootTitle
//    if rating > 0, add rating to totalRatings, increment divisionNum
// return totalRatings / divisionNum

double Library::calcAvgRating(string bookTitle)
{
    User user;
    Book book;
        
    
    // int i = searchUserFunc(users, numUsers, userName);
    int j = searchBookFunc(books, numBooks, bookTitle); //j is the index of the book that is having average ratings calculated
    
    if (j == -3)
    {
        return -3;
    }
    double ratingSum = 0.0; //ratings sum for average score
    double divisionNum = 0.0; //number of books added, which is then used to divide
    
    for (int k = 0; k < numUsers; k++)
    {
        int rating = users[k].getRatingAt(j);
        
        if (rating != 0)
        {
            ratingSum += rating;
            divisionNum++;
        }
        
    }
    if (divisionNum == 0)
    { 
      return 0;  
    }
    return ratingSum / divisionNum;
}

//}


// Algorithm:
// Use the user search function as a base for this problem
// First check for 

int Library::addUser(string userName)
{
    User user;
    Book book;
    
    int i = searchUserFunc(users, numUsers, userName);
    //int j = searchBookFunc(books, numBooks, bookTitle);
    
    if (numUsers == sizeUser)
    {
        return -2;
    }
    if (i >= 0)
    {
        return 0;
    }
    if (i == -3)
    {

        user.setUsername(userName); //this may need to be makeLowered later
        users[numUsers] = user; // Remember: numUsers is 1 greater than last used index. 50 users means 0 - 49 filled
        numUsers++;
        return 1;
    }
}

int Library::checkOutBook(string userName, string bookTitle, int rating)
{
    
    int i = searchUserFunc(users, numUsers, userName);
    int j = searchBookFunc(books, numBooks, bookTitle);
    
    if (rating >= 0 && rating <= 5 && i > 0 && j > 0) //formatting may cause error?
    {
        int userRatings = users[i].getNumRatings() + 1;
        users[i].setRatingAt(j, rating);
        users[i].setNumRatings(userRatings);
        return 1;
    }
    else if (rating < 0 || rating > 5)
    {
        return -4;
    }
    return -3;
}


int ssdCalc(User target, User comparison, int loopSize)
{
    // int targetSize = target.getNumRatings();
    // int comparisonSize = comparison.getNumRatings();
    // int loopSize = 0;
    int diff = 0;
    int ssd = 0;
    // // if (targetSize > comparisonSize) //make sure subtract doesn't error from smaller loop
    // {
    //     loopSize = targetSize;
    // }
    // else
    // {
    //     loopSize = comparisonSize;
    // }
    
    
    for (int x = 0; x < loopSize; x++)
    {
        diff = target.getRatingAt(x) - comparison.getRatingAt(x);
        ssd += (diff * diff); 
    }
    return ssd;
}

int findBestMatch(string userName, User users[], int usersSize, int bookSize)
{
    
    int i = searchUserFunc(users, usersSize, userName);
    int currentBestDiff = 9999; //huge num so if statement in loop always(theoretically) starts
    int currentBestIndex = -1;
    double ssd = -1.0;
    User user_i = users[i];
    User user_k = User();
    int k = 0;

    for ( k = 0; k < usersSize; k++)
    {

        if (k == i) //if statement so user isn't compared to themself. As long as not the same user, ssd is calculated.
        {
            continue;
        }
        else
        {
        
            user_k = users[k];
            ssd = ssdCalc(user_i, user_k, bookSize);
            
            if (ssd < currentBestDiff && ssd > 0)
            {
                currentBestDiff = ssd;
                
                currentBestIndex = k; //currentBestDiff is the index of the lowest ssd
            }
            
        }
        
       
    }
    return currentBestIndex; //currentBestDiff is the index of the lowest ssd   
}


void findBestBooks(User target, User comparison, int booksArray[], int loopSize)
{
    int y = 0;
    for (int x = 0; x < loopSize; x++)
    {
        // diff = target.getRatingAt(x) - comparison.getRatingAt(x);
        // ssd += (diff * diff);
        int comp = comparison.getRatingAt(x);
        int targ = target.getRatingAt(x);
        if ( comp >= 3 && targ == 0)
        {
            booksArray[y] = x;
            y++;
            if (y >= 5)
            {
                break;
            }
        }
        
    }
    if (y == 0)
    {
        cout << "There are no recommendations for " << target.getUsername() << " at present." << endl;
    }
    
}

string Library::getRecommendations(string userName)
{
    int foundBooks[] = {-1, -1, -1, -1, -1};
    int i = searchUserFunc(users, numUsers, userName); //get index of target person
    if (i == -3)
    {
        cout << userName << " does not exist." << endl;
        return "";
    }
    
    User targetUser = users[i];
    int ssd = findBestMatch(userName, users, numUsers, numBooks); // this gives the index of the person with the lowest ssd, stored in variable ssd
    User mostSimilarUser = users[ssd]; // sets user object to the user that has lowest ssd
    int rateCount = mostSimilarUser.getNumRatings(); //this stores ratings but includes zeros, so assign to variable to use in loop
    
    findBestBooks(targetUser, mostSimilarUser, foundBooks, numBooks);
    if (foundBooks[0] != -1)
    {
        cout << "Here is the list of recommendations" << endl;
        for (int n = 0; n < 5; n++)
        {
            int rec = foundBooks[n];
            if (rec >= 0)
            {
                Book recommendedBook = books[rec]; 
                
                string title = recommendedBook.getTitle();
                string author = recommendedBook.getAuthor();
                cout << title << " by " << author << endl;
            }
        }
    }
    return userName;
}