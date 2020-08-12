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

#ifndef TEAM_H
#define TEAM_H

class Team
{
    
public:
    Team(); //default constructor
    Team(string); //parameterized constructor
    void setTeamName(string); //name setter
    string getTeamName(); //name getter
    void readRoster(string); //reading players
    string getPlayerName(int); //player name getter 
    double getPlayerPoints(int); //point getter
    int getNumPlayers(); //number of player getter

private:
    string teamName; // name storage
    vector<Player> players; // players vector
};
#endif