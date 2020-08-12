// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project 3
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//
// 
// 
// 
// 
// 
#ifndef PLAYER_H
#include PLAYER_H

class Player
{
public:
    Player();
    Player(string, int, int, int, int);
    void setPlayerName(string);
    int getPlayerName();
    // void setMoney(int);
    // int getMoney();
    void setRace(int):
    int getRace();
    void setRole(int);
    int getRole();
    void setStrength(int);
    int getStrength();
    void setFaith(int);
    int getFaith();
    void setAgility(int);
    int getAgility();
    void setItem(int, Item);
    int getItem(int);
    
private:
    string name;
    int race;
    int role;
    // int money;
    int strength;
    int faith;
    int agility;
    Item items[4];
    
};
#endif