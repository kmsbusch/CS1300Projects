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

#ifndef ITEM_H
#define ITEM_H

class Item
{
public:
    Item();
    Item(string, int, int, int);
    void setItemName(string);
    string getItemName();
    void setHealthStat(int);
    int getHealthStat();
    void setStrengthStat(int);
    int getStrengthStat();
    void setIntelligenceStat(int);
    int getIntelligenceStat();
    void dumpItemStats();
    
private:
    string itemname;
    int healthstat;
    int strengthstat;
    int intelligencestat;
    
};
#endif