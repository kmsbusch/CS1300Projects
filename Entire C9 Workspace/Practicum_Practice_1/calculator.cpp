// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project 1 - Problem # 
#include <iostream>
using namespace std;

/*
Algorithm: 
Input parameters: 
Output (prints to screen): 
Returns: none
*/

int calculator(double num1, double num2, char operation)
{
    double finalVal;
    switch (operation)
    {
        case '-':
        finalVal = num1 - num2;
        cout << num1 << " " << operation << " " << num2 << " = " << finalVal << endl;
        break;
        case '+':
        finalVal = num1 + num2;
        cout << num1 << " " << operation << " " << num2 << " = " << finalVal << endl;
        break;
        case '/':
        finalVal = num1 / num2;
        cout << num1 << " " << operation << " " << num2 << " = " << finalVal << endl;
        break;
        case '*':
        finalVal = num1 * num2;
        cout << num1 << " " << operation << " " << num2 << " = " << finalVal << endl;
        break;
        default:
        cout << "Invalid operator!" << endl;
    }
    
}