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
#include <algorithm>
#include "Player.h"

using namespace std;

//
// 
// 
// 
// 
// 


/////////////////////// Basic Player Functions{
Player::Player()
{
    name = "";
    race = 0;
    role = 0;
    health = 100;
    strength = 10;
    intelligence = 10;
    //agility = 10;
    items.reserve(4);   // Reserve 4 empty slots
}
Player::Player(string playerName, int playerRace, int playerRole, int playerHealth, int playerStrength, int playerIntelligence, vector<Item> vItems)
{
    name = playerName;
    race = playerRace;
    role = playerRole;
    health = playerHealth;
    strength = playerStrength;
    intelligence = playerIntelligence;
    items = vItems;
}

void Player::setPlayerName(string playerName)
{
    name = playerName;
}
string Player::getPlayerName()
{
    return name;
}
void Player::setRace(int playerRace)
{
    race = playerRace;
}
int Player::getRace()
{
    return race;
}
void Player::setRole(int playerRole)
{
    role = playerRole;
}
int Player::getRole()
{
    return role;
}
void Player::setHealth(int playerHealth)
{
    health += playerHealth;
}
int Player::getHealth()
{
    return health;
}
void Player::setStrength(int playerStrength)
{
    strength += playerStrength;
}
int Player::getStrength()
{
    return strength;
}
void Player::setIntelligence(int playerIntelligence)
{
    intelligence += playerIntelligence;
}
int Player::getIntelligence()
{
    return intelligence;
}
void Player::setItem(Item item)
{
    items.push_back(item);
}
Item Player::getItem(int i)
{
    return items[i];
}

///////////////////}

void Player::useItem(int choiceNum)
{
    Item item = items[choiceNum - 1];
    setHealth(item.getHealthStat());
    setStrength(item.getStrengthStat());
    setIntelligence(item.getIntelligenceStat());
    items.erase(items.begin() + (choiceNum - 1));
}

void Player::showInventory()
{
    int counter;
    for (counter = 0; counter < items.size(); ++counter)
    {
        cout << counter + 1 << ". " << items[counter].getItemName() << endl;
    }
        cout << "Q. Go back" << endl;
}


void print_items(Item item)
{
    item.dumpItemStats();
}


void Player::dumpStats()
{
    string actualRace = "";
    if (race == 1)
    {
        actualRace += "Human";
    }
    else if (race == 2)
    {
        actualRace += "Elf";
    }
    
    string actualRole = "";
    if (role == 1)
    {
        actualRole += "Warrior";
    }
    else if (role == 2)
    {
        actualRole += "Wizard";
    }
    cout << "\nCharacter stats:" << endl <<
             " ================" << endl <<
    "name         = " << name << endl <<
    "race         = " << actualRace << endl <<
    "role         = " << actualRole << endl <<
    "health       = " << health << endl <<
    "strength     = " << strength << endl <<
    "intelligence = " << intelligence << endl;
    

    // cout << "\nItem List\n"
    //      << "==========" << endl;
    // for_each(items.begin(), items.end(), print_items);
}
    