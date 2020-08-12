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
void printNormalHeartRates(string patientNames[], int heartRate[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if ((heartRate[i] >= 70) && (heartRate[i] <= 190))
        {
            cout << patientNames[i] << " " << heartRate[i] << endl;
        }
    }
}
int main()
{
    string patients[4] = {"Joe", "Jack", "Amy", "Bob"};
    int heart_rate[4] = {70, 80, 190, 100};
    printNormalHeartRates(patients, heart_rate, 4);
}