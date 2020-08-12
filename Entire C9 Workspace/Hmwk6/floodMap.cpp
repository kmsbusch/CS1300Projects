// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 6 - Problem #2
#include <iostream>
#include <string>
using namespace std;

/*
Algorithm: Nest for loops that run through the row and then column, and checks if value at the index is less than specified #. If it is, cout *, otherwise, cout _
Input parameters: 2d array of the map, number of rows, double of water level.
Output (prints to screen):couts the image for value for each index. 
Returns: none
*/

void floodMap (double map[][4], int numRows, double waterLevel)
{
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if(map[row][col] <= waterLevel)
            {
                cout << "*";
            }
            else
            {
                cout << "_";
            }
        }
        cout << endl;
    }
}

int main()
{
    double map1[3][4] = {{1.2, 3.8, 7.8, 10.2}, {1.2, 5.2, 2.8, 4.5}, {1.1, 2.2, 3.3, 4.4}};
    floodMap(map1, 3, 4.2);
    
    cout << endl;
    
    double map2[4][4] = {{1.1, 2.2, 3.3, 2.1}, {0.1, 21.0, 3.0, 2.4}, {0.1, 3.1, 1.9, 9.0}, {1.1, 2.8, 5.4, 7.6}};
    floodMap(map2, 4, 2.6);
}