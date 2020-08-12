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
#include "Team.h"
using namespace std;

/*
Algorithm: 
1.
Input parameters: 
Output (prints to screen): 
Returns: none
*/
int split (string str, char c, string words[], int arrayLength)
{
    if (str.length() == 0) {
        return 0;
    }
    string word = "";
    int j = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c) 
        {
        	if (word.length() == 0) continue;
            words[j] = word;
            j++;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return j;
}


Team::Team()
{
    teamName = "";
    //vector<Player> players;
}

Team::Team(string teamCall)
{
    teamName = teamCall;
    //vector<Player> players;
}

void Team::setTeamName(string teamCall)
{
    teamName = teamCall;
}

string Team::getTeamName()
{
    return teamName;
}

void Team::readRoster(string fileName)
{
    ifstream myfile;
    myfile.open(fileName);
    string line = "";
    Player player;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            string str[line.length()];
            
            int splitNum = split(line, ',', str, 2);
            
            
            player = Player();
            
            
            player.setName(str[0]);
            player.setPoints(stod(str[1]));
                
            
            players.push_back(player);
            
        }
        //return players;
    }
}

string Team::getPlayerName(int index)
{
    if (index < 0 || index > players.size() - 1)
    {
        return "ERROR";
    }
    else
    {
        return players[index].getName();
    }
    
}

double Team::getPlayerPoints(int index)
{
    if (index < 0 || index > players.size() - 1)
    {
        return -1;
    }
    else
    {
        return players[index].getPoints();
    }
}

int Team::getNumPlayers()
{
    return players.size();
}
