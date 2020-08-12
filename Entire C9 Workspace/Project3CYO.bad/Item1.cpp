// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project 3
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

Item()
{
    string itemname = "";
    int itemtype = 0;
    int strengthstat = 0;
    int faithstat = 0;
    int agilitystat = 0;
    bool fire = 0;
}
Item(string nameItem, int typeItem, int statStrength, int statFaith, int statAgility, bool fuego)
{
    string itemname = nameItem;
    int itemtype = typeItem;
    int strengthstat = statStrength;
    int faithstat = statFaith;
    int agilitystat = statAgility;
    bool fire = fuego;
}
void setItemName(string)
{
    string itemname = nameItem;
}
string getItemName()
{
    return itemname;
}
void setItemType(int)
{
    int itemtype = typeItem;
}
int getItemType()
{
    return itemtype;
}
void setStrengthStat(int)
{
    int strengthstat = statStrength;
}
int getStrengthStat()
{
    return strengthstat;
}
void setFaithStat(int)
{
    int faithstat = statFaith;
}
int getFaithStat()
{
    return faithstat;
}
void setAgilityStat(int)
{
    int agilitystat = statAgility;
}
int getAgilityStat()
{
    return agilitystat;
}
void isItFire(bool)
{
    bool fire = fuego;
}
bool itMightBeFire()
{
    return fire;
}

