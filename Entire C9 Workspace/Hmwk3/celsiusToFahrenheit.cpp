// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinbusch/csci1300
// Homework 3 - Problem #9
#include <iostream>
#include <iomanip>
using namespace std;
/*
Algorithm: converts celsius to fahrenheit using formula:
1. (9 / 5) * celsius + 32
Input: celsius (int)
Output (prints to screen): fahrenheit (double)
Returns: none
*/
void celsiusToFahrenheit(int celsius)
{
    double fahrenheit = 9.0 / 5.0 * celsius + 32;
    cout << "The temperature of " << fixed << setprecision(0) << celsius << " in Fahrenheit is " << fixed << setprecision(2) << fahrenheit << endl;
}

int main()
{
    celsiusToFahrenheit(36);
    celsiusToFahrenheit(19);
}
 