// CS1300 Spring 2019
// Author: my name
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project 2
#include <iostream>
#include <fstream>
#include <string>
#include "Library.h"
using namespace std;


//////////////////////////////////////////////////////////////////////////////////
// -- book class...{
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
//}
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// -- user class...{
User::User()
{
    //cout << "default" << endl;
    username = "";
    numRatings = 0;
    size = 50;
    for (int i = 0; i < 50; i++)
    {
        ratings[i] = 0;
    }
}
User::User(string inputName, int userRatings[], int ratingsCount)
{
    //User();
    username = "";
    numRatings = 0;
    size = 50;
    username = inputName;
    for (int i = 0; i < 50; i++)
    {
        ratings[i] = userRatings[i];
    }
    numRatings = ratingsCount;
    for (int i = ratingsCount; i < size; i++) //set the array after what has a value equal to zero. 
    {
        ratings[i] = 0;
    }
}
void User::setUsername(string inputName)
{
    username = inputName;
}
string User::getUsername()
{
    return username;
}
bool User::setRatingAt(int index, int value)
{
    
    if (index < 50 && value >= 0 && value <= 5) //error might show up here from syntax
    {
        ratings[index] = value;
        return true;
    }
    else 
    {
        return false;
    }
}
int User::getRatingAt(int index)
{
    if (index < 50)
    {
        return ratings[index];
    }
    else 
    {
        return -1;
    }
}
void User::setNumRatings(int ratingCount)
{
    numRatings = ratingCount;
}
int User::getNumRatings()
{
    return numRatings;
}
int User::getSize()
{
    return size;
}
//}
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// -- library class...{



  //////////////////////////////////////////////////////////////////////////////////
// -- helper functions...{
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

//function for recommendation, calculates the sum squared difference score
int ssdCalc(User target, User comparison)
{
    int targetSize = target.getNumRatings();
    int comparisonSize = comparison.getNumRatings();
    int loopSize = 0;
    int diff = 0;
    int ssd = 0;
    if (targetSize > comparisonSize) //make sure subtract doesn't error from smaller loop
    {
        loopSize = targetSize;
    }
    else
    {
        loopSize = comparisonSize;
    }
    
    for (int x = 0; x < loopSize; x++)
    {
        diff = target.getRatingAt(x) - comparison.getRatingAt(x);
        ssd += (diff * diff); 
    }
    return ssd;
}


//function to loop through users and find index of user with lowest ssd
int findBestMatch(string userName, User users[], int usersSize)
{
    
    int i = searchUserFunc(users, usersSize, userName);
    int currentBestDiff = 9999; //huge num so if statement in loop always(theoretically) starts
    int currentBestIndex;
    int ssd;
    User user_i = users[i];
    User user_k;
    for (int k = 0; k < usersSize; k++)
    {

        if (k != i) //if statement so user isn't compared to themself. As long as not the same user, ssd is calculated.
        {
            user_k = users[k];
            ssd = ssdCalc(user_i, user_k);
            
            if (ssd < currentBestDiff)
            {
                currentBestDiff = ssd;
                
                currentBestIndex = k; //currentBestDiff is the index of the lowest ssd
            }
            
        }
        
       
    }
    return currentBestIndex; //currentBestDiff is the index of the lowest ssd   
}

//function to loop through users books and store books with good ratings into array that is called through later
void findBestBooks(User target, User comparison, int booksArray[])
{
    int targetSize = target.getNumRatings();
    int comparisonSize = comparison.getNumRatings();
    int loopSize = 0;
    int diff = 0;
    int ssd = 0;
    if (targetSize > comparisonSize) //make sure subtract doesn't error from smaller loop
    {
        loopSize = targetSize;
    }
    else
    {
        loopSize = comparisonSize;
    }
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////}
  //////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GETRATING - GETRECOMMENDATIONS {
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




/*
// Algorithm:
// Use the user search function as a base for this problem
// First check if the max number of people is already in array, if so return -2
// Next, check if the user is found anywhere in the array, and if they are, return a zero
// Lastly, if the search returns a -3, meaning not found, increment number of users, and then use User member functions to set the username and then put in the user array. Then return 1
*/
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
        numUsers++;
        user.setUsername(userName); //this may need to be makeLowered later
        users[numUsers] = user;
        
        return 1;
    }
}


int Library::checkOutBook(string userName, string bookTitle, int rating)
{
    User user;
    Book book;
    
    int i = searchUserFunc(users, numUsers, userName);
    int j = searchBookFunc(books, numBooks, bookTitle);
    
    if (rating >= 0 && rating <= 5 && i > 0 && j > 0) //formatting may cause error?
    {
        users[i].setRatingAt(j, rating);
        return 1;
    }
    else if (rating < 0 || rating > 5)
    {
        return -4;
    }
    return -3;
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
    int ssd = findBestMatch(userName, users, numUsers); // this gives the index of the person with the lowest ssd, stored in variable ssd
    User mostSimilarUser = users[ssd]; // sets user object to the user that has lowest ssd
    int rateCount = mostSimilarUser.getNumRatings(); //this stores ratings but includes zeros, so assign to variable to use in loop
    
    findBestBooks(targetUser, mostSimilarUser, foundBooks);
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
//}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//-END OF LIBRARY CLASS HIDER//}
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// -- library class: constructor

// -- library class: getters/setters

// -- library class: methods (and other functions)


// printAllBooks
// cout << "Here is a list of books" << endl;

// viewRatings
// cout << username << " does not exist." << endl;
// cout << username << " has not rated any books yet." << endl;
// cout << "Here are the books that "<< name << " rated" << endl;
// cout << "Title : " << title << endl;
// cout << "Rating : " << rating << endl;
// cout << "-----" << endl;

// getRecommendations
// cout << username << " does not exist." << endl;
// cout << "Here is the list of recommendations" << endl;
// cout << title << " by " << author << endl;
// cout << "There are no recommendations for " << username <<" at present."<<endl;



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
	cout << "5. Find number of books user rated" << endl;
	cout << "6. View ratings" << endl;
	cout << "7. Get average rating" << endl;
	cout << "8. Add a user" << endl;
	cout << "9. Checkout a book" << endl;
	cout << "10. Get recommendations" << endl;
	cout << "11. Quit" << endl;
}


int main(int argc, char const *argv[]) 
{


	// temp variables
    string choice;
    string bookFileName;
    string userFileName;
    string userName, bookTitle;
    string strRating;

    Library lib1 = Library();

    while (choice != "11") {
        displayMenu();

        // take a menu opton
        getline(cin, choice);
        //cin >> choice;

        // convert the `choice` to an integer
        int menuChoice = stoi(choice);

        switch (menuChoice) {

            case 1:
            {
                // Initialize library -- readBooks
                cout << "Enter a book file name:" << endl;
                getline(cin, bookFileName);

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                int choice1 = lib1.readBooks(bookFileName);
                
                if (choice1 == -1)
                {
                    cout << "No books saved to the database." << endl;
                }
                else if (choice1 == -2)
                {
                    cout << "Database is already full. No books were added." << endl;
                }
                else if (choice1 == lib1.getSizeBook())
                {
                    cout << "Database is full. Some books may have not been added." << endl;
                }
                else
                {
                   cout << "Total books in the database: " << lib1.getNumBooks() << endl; 
                }
                //////////////////////////////////////////////////////////////////////////

                // Use the below messages and match them to the return code.
                // readBooks returned -1
                // cout << "No books saved to the database." << endl;
                // readBooks returned -2
                // cout << "Database is already full. No books were added." << endl;
                // readBooks returned book arr size
                // cout << "Database is full. Some books may have not been added." << endl;
                // readBooks returned otherwise
                // cout << "Total books in the database: " << numBook << endl;



                cout << endl;
                break;
            }
            case 2:
            {
                //  Initialize user catalog -- readRatings

                cout << "Enter a user file name:" << endl;
                getline(cin, userFileName);


                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                int choice2 = lib1.readRatings(userFileName);
                
                if (choice2 == -1)
                {
                    cout << "No users saved to the database." << endl;
                }
                else if (choice2 == -2)
                {
                    cout << "Database is already full. No users were added." << endl;
                }
                else if (choice2 == lib1.getSizeUser())
                {
                    cout << "Database is full. Some users may have not been added." << endl;
                }
                else
                {
                   cout << "Total users in the database: " << lib1.getNumUsers() << endl;
                }
                //////////////////////////////////////////////////////////////////////////

                // Use the below messages and match them to the return code.
                // readRatings returned -1
                // cout << "No users saved to the database." << endl;
                // readRatings returned -2
                // cout << "Database is already full. No users were added." << endl;
                // readRatings returned user arr size
                // cout << "Database is full. Some users may have not been added." << endl;
                // readRatings returned otherwise
                // cout << "Total users in the database: " << numUser << endl;

                cout << endl;
                break;
            }
            case 3:
            {
                // Display library -- printAllBooks

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                if (lib1.getNumBooks() == 0 && lib1.getNumUsers() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    lib1.printAllBooks();
                }
                //////////////////////////////////////////////////////////////////////////


                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;


                cout << endl;
                break;
            }
            case 4:
            {
                //  Get a rating -- getRating

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                if (lib1.getNumBooks() == 0 && lib1.getNumUsers() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    // take user name
                    cout << "Enter username:" << endl;
                    getline(cin, userName);
    
                    // take book title
                    cout << "Enter book title:" << endl;
                    getline(cin, bookTitle);
                    
                    int rating1 = lib1.getRating(userName, bookTitle);
                    if (rating1 == 0)
                    {
                        cout << userName << " has not rated " << bookTitle << endl;
                    }
                    else if (rating1 == -3)
                    {
                        cout << userName << " or " << bookTitle << " does not exist." << endl;
                    }
                    else 
                    {
                        cout << userName << " rated " << bookTitle << " with " << rating1 << endl;
                    }
                }
                //////////////////////////////////////////////////////////////////////////

                // Use the below messages and match them to the return code. Update variables as needed.
                

                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;

        	

                // getRating returned 0
                // cout << userName << " has not rated " << bookTitle << endl;
                // getRating returned -3
                // cout << userName << " or " << bookTitle << " does not exist." << endl;
                // getRating returned other than 0 or -3
                // cout << userName << " rated " << bookTitle << " with " << rate << endl;

                cout << endl;
                break;
            }
            case 5:
            {
                // Get number of books the user has rated -- getCountReadBooks
                if (lib1.getNumBooks() == 0 && lib1.getNumUsers() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    cout << "Enter username:" << endl;
                    getline(cin, userName);
                    int numRated = lib1.getCountReadBooks(userName);
                    if (numRated == 0)
                    {
                        cout << userName << " has not rated any books." << endl;
                    }
                    else if (numRated == -3)
                    {
                        cout << userName << " does not exist." << endl;
                    }
                    else
                    {
                        cout << userName << " rated " << numRated << " books." << endl;
                    }
                }
                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;

                

                // getCountReadBooks returned 0
                // cout << userName << " has not rated any books." << endl;
                // getCountReadBooks returned -3
                // cout << userName << " does not exist." << endl;
                // getCountReadBooks returned other than 0 or -3
                // cout << userName << " rated " << numRated << " books." << endl;


            	cout << endl;
                break;
            }
            case 6:
            {
                // View user’s ratings -- viewRatings
                if (lib1.getNumBooks() == 0 && lib1.getNumUsers() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    cout << "Enter username:" << endl;
                    getline(cin, userName);
                    lib1.viewRatings(userName);
                }
                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;

        		// take user name
                


            	cout << endl;
                break;
            }
            case 7:
            {
                // Calculate the average rating for the book -- calcAvgRating
                if (lib1.getNumBooks() == 0 && lib1.getNumUsers() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    // take book title
                    cout << "Enter book title:" << endl;
                    getline(cin, bookTitle);
                    double avgRating = lib1.calcAvgRating(bookTitle);
                    if (avgRating == -3)
                    {
                        cout << bookTitle << " does not exist." << endl;
                    }
                    else
                    {
                        cout << "The average rating for " << bookTitle << " is " << avgRating << endl;
                    }
                    
                }
                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;

        	

                // calcAvgRating returned -3
                // cout << bookTitle << " does not exist." << endl;
                // calcAvgRating returned other than -3
                // cout << "The average rating for " << bookTitle << " is " << avgRating << endl;

            	cout << endl;
                break;
            }
            case 8:
            {
                // Add a user to the database -- addUser
        		// take user name
                cout << "Enter username:" << endl;
                getline(cin, userName);
                int add1 = lib1.addUser(userName);
                if (add1 == 0)
                {
                    cout << userName << " already exists in the database." << endl;
                }
                else if (add1 == -2)
                {
                    cout << "Database is already full. " << userName << " was not added." << endl;
                }
                else if (add1 == 1)
                {
                    cout << "Welcome to the library " << userName << endl;
                }

                // addUser returned 1
                // cout << "Welcome to the library " << userName << endl;
                // addUser returned 0
                // cout << userName << " already exists in the database." << endl;
                // addUser returned -2
                // cout << "Database is already full. " << userName << " was not added." << endl;

            	cout << endl;
                break;
            }
            case 9:
            {
                // Check out the book -- checkOutBook
                if (lib1.getNumBooks() == 0 && lib1.getNumUsers() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    // take user name
                    cout << "Enter username:" << endl;
                    getline(cin, userName);
    
                    // take book title
                    cout << "Enter book title:" << endl;
                    getline(cin, bookTitle);
    
                    // take rating
                    cout<<"Enter rating for the book:"<<endl;
                    getline(cin, strRating);
                    int newRating = stoi(strRating);
                    
                    int strRating1 = lib1.checkOutBook(userName, bookTitle, newRating);
                    if (strRating1 == -4)
                    {
                        cout << strRating << " is not valid." << endl;
                    }
                    else if (strRating1 == -3)
                    {
                        cout << userName << " or " << bookTitle << " does not exist." << endl;
                    }
                    else if (strRating1 == 1)
                    {
                        cout << "We hope you enjoyed your book. The rating has been updated." << endl;
                    }
                }
                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;

        		

                // checkOutBook returned 1
                // cout << "We hope you enjoyed your book. The rating has been updated." << endl;
                // checkOutBook returned -4
                // cout << strRating << " is not valid." << endl; 
                // checkOutBook returned -3
                // cout << userName << " or " << bookTitle << " does not exist." << endl;

            	cout << endl;
                break;
            }
            case 10:
            {
                // get recommendations  -- getRecommendations
                 if (lib1.getNumBooks() == 0 && lib1.getNumUsers() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    // take user name
                    cout << "Enter username:" << endl;
                    getline(cin, userName);
                    lib1.getRecommendations(userName);
                }
                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;

        		


            	cout << endl;
                break;
            }
            case 11:
            {
                // quit
                cout << "good bye!" << endl;
                break;
            }
            default:
            {
                cout << "invalid input" << endl;
                cout << endl;
            }
        }

    
    }
    return 0;
}