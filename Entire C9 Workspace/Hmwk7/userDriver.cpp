// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 7 - Problem #
#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
using namespace std;

/*
Algorithm: 
1.
Input parameters: 
Output (prints to screen): 
Returns: none
*/

int main()
{
    User u1 = User();
    int nRating = 45;
    u1.setNumRatings(nRating);
    int rating = 3;
    int idx = 40;
    cout << "set/get setRatingAt(" << idx << "," << rating << ") [numRating=" << nRating  << "]" << endl;
    cout << "Setting rating at " << idx << " to " << rating << endl;
    string ratingset = u1.setRatingAt(idx,rating) ? "true": "false";
    cout << "setRatingAt(" << idx << "," << rating << ") returned: " << ratingset << endl;
    cout << "getRatingAt(" << idx << ") returned: " << u1.getRatingAt(idx) << endl;
}
