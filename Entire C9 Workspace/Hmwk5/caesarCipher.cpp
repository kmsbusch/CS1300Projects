// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Homework 5 - Problem #4
#include <iostream>
#include <string>
using namespace std;

/*
Algorithm: Encode and decode strings based on a int key that is given. Does this by mapping string to ASCII and manipulating based on key.
Input parameters: String message, integer key shift, boolean to determine if decoding or encoding.
Output (prints to screen): none
Returns: Encrypted or decrypted string.
*/

string caesarCipher(string message, int key, bool flag) // returns string, takes in string, integer, and bool
{
    if ((key < 0) || (key > 25)) // checks if number to shift alphabet over is between 0 and 25
    {
        return "ERROR"; //returns error if out of bounds
    }
    
    if (flag == true) // encrypting function
    {
        string result = ""; //string that holds each letter after it is encrypted
        for (int i = 0; i < message.length(); i++) //beginning loop
        {
            if ((int)message[i] == 32) //if value of string is a space
            {
                result += message[i]; // add it to the string as is, no changes
            }
            else if ((int)message[i] + key <= 90) // if value is before a capital z, 
            {
                result += char(int(message[i] + key)); // add the value of the shift to the int value of the character, then change it back to a character
            }
            else if ((int)message[i] + key > 90)  //if value after adding shift is past capital z, 
            {
                result += (((int)message[i] + key - 65) % 26 + 65); // loop back around to a by subtracting A's value, then modulo 26 & + 65
            }
        }
        return result; //return the encrypted message 
    }
    else if  // decryption
    {
        string idfk = "";
        for (int i = 0; i < message.length(); i++)
        {
            if ((int)message[i] == 32)
            {
                idfk += message[i];
            }
            else if ((int)message[i] - key >= 65)
            {
                //cout << (int)message[i] << endl;
                idfk += char(int(message[i] - key));
                //cout << idfk << endl;
            }
            else if (((int)message[i] - key) < 65)
            {
                
                idfk += (((int)message[i] - key) + 26);
                
            }
        }
        return idfk;
    }
    
}

int main()
{
    string string1 = caesarCipher("M LSTI XLMW ASVOW GSVVIGXPC", 4, false);
    cout << string1 << endl;
    cout << caesarCipher("THIS PROBLEM MADE MY HEAD HURT A LOT", 7, true);
}