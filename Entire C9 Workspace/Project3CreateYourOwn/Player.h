// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project 3
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

//
// 
// 
// 
// 
// 


class Player
{
public:
    Player();
    Player(string , int , int , int , int , int , vector<Item>);
    void setPlayerName(string);
    string getPlayerName();
    void setRace(int);
    int getRace();
    void setRole(int);
    int getRole();
    void setHealth(int);
    int getHealth();
    void setStrength(int);
    int getStrength();
    void setIntelligence(int);
    int getIntelligence();
    void setItem(Item);
    Item getItem(int);
    void useItem(int);
    void dumpStats();
    void showInventory();
    
private:
    string name;
    int race;
    int role;
    int health;
    int strength;
    int intelligence;
    // int agility;
    vector<Item> items;
    
};
#endif