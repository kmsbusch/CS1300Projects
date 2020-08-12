// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 6 - Problem #4
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Algorithm: 
1. set up inputstream and open file
2. int to count numbers and if statement for if file is open
3. empty string to store stuff
4. while loop to go line by line through file
5. if the line isn't empty, take the string in the file and convert from string to integer with stoi
6. put integer into array and increment array index/number counter
7. if number count is bigger than array can store, return how many numbers are stored and break loop
8. if file doesn't open, return -1
Input parameters: string for file name, array of int, int defining array length
Output (prints to screen): none
Returns: how many integers in file
*/

int getLinesFromFile(string fileName, int arr[], int length){
    ifstream mystream;
    mystream.open(fileName);
    int numCount = 0;
    if (mystream.is_open())
    {
        string line = "";
        int i = 0;
        while (getline(mystream, line) && i < length)
        {
            if (line.length() != 0)
            {
                arr[numCount] = stoi(line);
                numCount++;
                //cout << "arr[i] in function: " << arr[i] << endl;
            }
            if (numCount >= length)
            {
                return numCount;
                break;
            }    
        }
        
    }
    else
    {
        return -1;
    }
    return numCount;
    
}
        

int main()
{
    int numArray[7];
    int x = getLinesFromFile("file1.txt", numArray, 7);
    cout << "Function returned: " << x << "\n";
    for(int i = 0; i < x; i++){
        cout << numArray[i] << endl;
    }
}