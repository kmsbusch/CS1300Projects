// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project 3
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Player.h"
using namespace std;

//
// 
// 
// 
// 
// 

Player()
{
    string name = "";
    int race = 0;
    int role = 0;
    int strength = 0;
    int faith = 0;
    int agility = 0;
    Item items[4] = {-1, -1, -1, -1};//-1 means empty slot (Maybe change this to 0 later) 
}
Player(string playerName, int playerRace, int playerRole, int playerStrength, int playerFaith, int playerAgility, Item items[4])
{
    string name = playerName;
    int race = playerRace;
    int role = playerRole;
    int strength = playerStrength;
    int faith = playerFaith;
    int agility = playerAgility;
    Item items[4];//-1 means empty slot (Maybe change this to 0 later)
}

void setPlayerName(string playerName)
{
    string name = playerName;
}
int getPlayerName()
{
    return name;
}
void setRace(int playerRace)
{
    int race = playerRace;
}
int getRace()
{
    return race;
}
void setRole(int playerRole)
{
    int role = playerRole;
}
int getRole()
{
    return role;
}
void setStrength(int playerStrength)
{
    int strength = playerStrength;
}
int getStrength()
{
    return strength;
}
void setFaith(int playerFaith)
{
    int faith = playerFaith;
}
int getFaith()
{
    return faith;
}
void setAgility(int playerAgility)
{
    int agility = playerAgility;
}
int getAgility()
{
    return agility;
}
void setItem(int, Item)
{
    
}
int getItem(int)
{
    
}

    