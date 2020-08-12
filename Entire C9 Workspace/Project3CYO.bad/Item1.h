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
    Item(string);
    void setItemName(string);
    string getItemName();
    void setItemType(int);
    int getItemType();
    void setStrengthStat(int);
    int getStrengthStat();
    void setFaithStat(int);
    int getFaithStat();
    void setAgilityStat(int);
    int getAgilityStat();
    void isItFire(bool); //
    bool itMightBeFire();
    
private:
    string itemname;
    int itemtype;
    int strengthstat;
    int faithstat;
    int agilitystat;
    bool fire;
    
    
    
};
#endif