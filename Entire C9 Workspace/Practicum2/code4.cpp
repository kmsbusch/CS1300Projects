// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Algorithm: 
1.
Input parameters: 
Output (prints to screen): 
Returns: none
*/


int calcPay(string fileName)
{
    
    ifstream myfile;
    myfile.open(fileName);
    string words[20];
    if(myfile.is_open())
    {
        int numEntries = 0;
        string line = "";
        double totalpay = 0;
        while (getline(myfile, line))
        {
            if(line != "")
            {
                
                split(line, ',', words, 20);
                string name = words[0];
                // double hrs = str[1];
                // double rate = str[2];
                double pay = stod(words[1]) * stod(words[2]);
                
                cout << words[0] << ": " << pay << endl;
                totalpay += pay;
                numEntries++;
            }
        }
        cout << "Total: " << totalpay << endl;
        return numEntries; 
    }
    else
    {
        return -1;
    }
}