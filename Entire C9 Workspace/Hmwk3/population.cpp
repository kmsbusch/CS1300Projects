// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinbusch/csci1300
// Homework 3 - Problem #8
#include <iostream>
#include <math.h>
using namespace std;
/*
Algorithm: calculate population increase in a year with formula:
1. initialpop + number of births + number of immigrants - deaths
Input: initial population (integer)
Output (prints to screen): none
Returns:end population value
*/
int population(int startpop)
{
    int endpop;
    int total_seconds = 365 * 24 * 3600;
    int births = total_seconds / 8;
    int deaths = total_seconds / 12;
    int immigrants = total_seconds / 27;
    endpop = startpop + births + immigrants - deaths; 
    return endpop;
}

int main()
{
    int endpop1 = population(342689);
    cout << "endpop1 = " << endpop1 << endl;
    int endpop2 = population(918273);
    cout << "endpop2 = " << endpop2 << endl;
}