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
#include "Item.h"
#include "Monster.h"
using namespace std;

//
// 
// 
// 
// 
// 

#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();
    bool runGame(Player);
    Monster initializeMonster(string, Monster);
    Item initializeItem(string, Item);
    void initializeLeaderboard(string);
    Player startMenu();

private:
    void turnMenu();
    void fightMenu();
    string getRaceString(Player);
    string getRoleString(Player);
    Player fightFunc(Player);
    Player roomFunc(Player);
    Player restFunc(Player);
    Player useItemMenu(Player);
    bool chestFound = false;
    bool dead = false;
    bool monsterdead = false;
    bool quit = false;
    bool escaped = false;
    
    
};
#endif