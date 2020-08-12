// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project 3
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <random>
#include <sys/time.h>
#include "Monster.h"
using namespace std;

//
// 
// 
// 
// 
// 

Monster::Monster()
{
    monstername = "";
    monsterhealth = 0;
    monsterstrength = 0;
    // monsteragility = 0;
}
Monster::Monster(string nameMonster, int healthMonster, int strengthMonster)
{
    monstername = nameMonster;
    monsterhealth = healthMonster;
    monsterstrength = strengthMonster;
    // monsteragility = agilityMonster;
}
void Monster::setMonsterName(string nameMonster)
{
    monstername = nameMonster;
}
string Monster::getMonsterName()
{
    return monstername;
}
void Monster::setHealth(int healthMonster)
{
    monsterhealth += healthMonster;
}
int Monster::getHealth()
{
    return monsterhealth;
}
void Monster::setMonsterStrength(int strengthMonster)
{
    monsterstrength = strengthMonster;
}
int Monster::getMonsterStrength()
{
    return monsterstrength;
}


void Monster::dumpStats()
{
    cout << "\n Monster stats:" << endl <<
             " ================" << endl <<
    "name         = " << monstername << endl <<
    "health       = " << monsterhealth << endl <<
    "strength     = " << monsterstrength << endl;
}