// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Hmwk8
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Player.h"
using namespace std;

/*
Algorithm: 
1.
Input parameters: 
Output (prints to screen): 
Returns: none
*/

Player::Player() //default constructor sets values to empty
{
    name = "";
    points = 0.0;
}

Player::Player(string playerName, double playerPoints) //parameterized constructor, sets name and points
{
    name = playerName;
    points = playerPoints;
}
string Player::getName() //name getter
{
    return name;
}
double Player::getPoints() // point getter
{
    return points;
}
void Player::setName(string playerName) //name setter
{
    name = playerName;
}
void Player::setPoints(double playerPoints) //point setter
{
    points = playerPoints;
}