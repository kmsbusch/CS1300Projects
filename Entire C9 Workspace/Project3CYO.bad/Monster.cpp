// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project 3
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Monster.h"
using namespace std;

//
// 
// 
// 
// 
// 

Monster()
{
    string monstername = "";
    int monstertype = 0;
    int monsterstrength = 0;
    int monsteragility = 0;
}
Monster(string nameMonster, int typeMonster, int strengthMonster, int agilityMonster)
{
    string monstername = nameMonster;
    int monstertype = typeMonster;
    int monsterstrength = strengthMonster;
    int monsteragility = agilityMonster;
}
void setMonsterName(string)
{
    string monstername = nameMonster;
}
string getMonsterName()
{
    return monstername;
}
void setMonsterType(int)
{
    int monstertype = typeMonster;
}
int getMonsterType()
{
    return monstertype;
}
void setMonsterStrength(int)
{
    int monsterstrength = strengthMonster;
}
int getMonsterStrength()
{
    return monsterstrength;
}
void setMonsterAgility(int)
{
    int monsteragility = agilityMonster;
}
int getMonsterAgility()
{
    return monsteragility;
}
