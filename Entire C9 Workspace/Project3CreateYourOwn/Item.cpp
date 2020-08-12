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
#include <sys/time.h>
#include "Item.h"
using namespace std;

//
// 
// 
// 
// 
// 

Item::Item()
{
    itemname = "";
    healthstat = 0;
    strengthstat = 0;
    intelligencestat = 0;
}
Item::Item(string nameItem, int statHealth, int statStrength, int statIntelligence)
{
    itemname = nameItem;
    healthstat = statHealth;
    strengthstat = statStrength;
    intelligencestat = statIntelligence;
}
void Item::setItemName(string nameItem)
{
    itemname = nameItem;
}
string Item::getItemName()
{
    return itemname;
}
void Item::setHealthStat(int statHealth)
{
    healthstat = statHealth;
}
int Item::getHealthStat()
{
    return healthstat;
}
void Item::setStrengthStat(int statStrength)
{
    strengthstat = statStrength;
}
int Item::getStrengthStat()
{
    return strengthstat;
}
void Item::setIntelligenceStat(int statIntelligence)
{
    intelligencestat = statIntelligence;
}
int Item::getIntelligenceStat()
{
    return intelligencestat;
}
void Item::dumpItemStats()
{
    cout << "\nItem stats:" << endl <<
             "================" << endl <<
    "name         = " << itemname << endl <<
    "health       = " << healthstat << endl <<
    "strength     = " << strengthstat << endl <<
    "intelligence = " << intelligencestat << endl;
}

