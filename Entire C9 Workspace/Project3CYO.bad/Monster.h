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

#ifndef MONSTER_H
#define MONSTER_H

class Monster
{
public:
    Monster();
    Monster(string);
    void setMonsterName(string);
    string getMonsterName();
    void setMonsterType(int);
    int getMonsterType();
    void setMonsterStrength(int); //maybe make this take in two ints, second one is monster type, then in implementaion, if statements section them apart
    int getMonsterStrength(); //if i do that, get rid of getter and setter for type. also do this for each "type" thing
    void setMonsterAgility(int);
    int getMonsterAgility();
    
private:
    string monstername;
    int monstertype;
    int monsterstrength;
    int monsteragility;
    
};
#endif