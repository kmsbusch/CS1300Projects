// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 9
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Algorithm:
//While number isnt equal to zero, mod the number by 2 and store the remainder in a string
//Once the number is zero, run a loop that reverses the string and then return that string 

string decimalToBinaryIterative(int decimal)
{
    string binary = "";//string to hold binary string
    string binary2; //string for the reversed binary later
    int modulus;//int for division remainder
    if (decimal == 0)//edge case for if input is zero
    {
        binary += "0";
    }
    else
    {
        while (decimal > 0)//while the number to be divided is greater than zero
        {
            modulus = decimal % 2;//find remainder of division by 2
            if (modulus == 1)//if remainder is 1
            {
                binary += "1"; //add 1 to the string
            }
            else if (modulus == 0)//if remainder is 0
            {
                binary += "0";//add 0 to string
            }
            decimal = decimal / 2;//divide the number by 2 and repeat loop till number is 0
        }    
    }
    int stringsize = binary.size() - 1; //make variable to put in loop
    for (int i = stringsize; i >= 0; i--)// for loop to reverse string
    {
        binary2 += binary[i];
    }
    return binary2;//return new reversed string
}

int main()
{
    cout << "13 in binary is: " << decimalToBinaryIterative(13) << endl;
    cout << "55 in binary is: " << decimalToBinaryIterative(55) << endl;
    cout << "22 in binary is: " << decimalToBinaryIterative(22) << endl;
    cout << "5 in binary is: " << decimalToBinaryIterative(5) << endl;
}