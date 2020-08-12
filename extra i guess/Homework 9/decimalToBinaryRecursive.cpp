// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework9
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Algorithm:
//Instead of using a loop to change the number and then store it in a string, put the contents of the original loop in the else condition of an if statement that provides the exit condition.
//Then after doing all the mechanics that divide by 2 and put the remainder in a string, 
//return the function inside of itself, and add the binary string to it, so that it comes out the right way when it eventually finishes. 



string decimalToBinaryRecursive(int decimal)
{
    string binary = "";//empty string
    int modulus;//int remainder of the division
    if (decimal == 0) //exit condition
    {
        return "0";
    }
    else if (decimal == 1)//edge case coverage / exit condition
    {
        return "1";
    }
    else
    {
        modulus = decimal % 2;//find remainder of division by 2 
        if (modulus == 1)
        {
            binary += "1";//put 1 into string if remainder of 1
        }
        else if (modulus == 0)
        {
            binary += "0";//put 0 into string if remainder is 0
        }
        decimal = decimal / 2;//update decimal to be number after division
        return decimalToBinaryRecursive(decimal) + binary;//call the function again and add the string to its
    }
    
}

int main()
{
    cout << "13 in binary is: " << decimalToBinaryRecursive(13) << endl;
    cout << "55 in binary is: " << decimalToBinaryRecursive(55) << endl;
    cout << "22 in binary is: " << decimalToBinaryRecursive(22) << endl;
    cout << "5 in binary is: " << decimalToBinaryRecursive(5) << endl;
}