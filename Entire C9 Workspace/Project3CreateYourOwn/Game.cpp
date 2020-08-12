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
#include "Game.h"
using namespace std;

//
// 
// 
// 
// 
// 



///////////////////////////////// Starting game functions {
int split(string str, char c, string words[], int arrayLength)
{
    if (str.length() == 0) {
        return 0;
    }
    string word = "";
    int j = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c) 
        {
        	if (word.length() == 0) continue;
            words[j] = word;
            j++;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return j;
}

string Game::getRaceString(Player p)
{
	if (p.getRace() == 1)
	{
		return "Human";
	}
	else if (p.getRace() == 2)
	{
		return "Elven";
	}
	return "invalid";
}

string Game::getRoleString(Player p)
{
	if (p.getRole() == 1)
	{
		return "Warrior";
	}
	else if (p.getRole() == 2)
	{
		return "Wizard";
	}
	return "invalid";
}

Player Game::startMenu(){
	cout << "Welcome to CSCIHack!" << endl;
	cout << "This is a Nethack inspired roguelike game where you finds yourself exploring a monster infested labyrinth, looking for a famed chest with infinite riches!" << endl << "...Or something like that anyway." << endl;
	cout << "What would you like to be called?" << endl;
	cout << "---------------------------------------" << endl;
	cout << "=> ";
	string namechoice;
	getline (cin, namechoice);
	
	//base stats
	int strength = 10;
	int health = 100;
	int intelligence = 10;
	vector<Item> stuff;
	string raceinput = "0";
	int racechoice = 0;
	while (racechoice < 1 || racechoice > 2)
	{
    	
    // 	int agility = 10;
    	cout << "Please choose a race below, or press 3 for more information about each race and their differences." << endl;
    	cout << "1. Human" << endl;
    	cout << "2. Elf" << endl;
    	cout << "3. More information" << endl;
    	cout << "---------------------------------------" << endl;
    	cout << "=> ";
    	getline (cin, raceinput);
    	if (!isdigit(raceinput[0]))
    	{
    	    cout << "Invalid input, please choose an input from 1-3." << endl;
    	    cout << "---------------------------------------" << endl;
    	   continue;
    	}
    	else
    	{
    	    racechoice = stoi(raceinput);
    	}
    	if (racechoice == 1)
    	{
    		intelligence = 8;
    		break;
    	}
    	else if (racechoice == 2)
    	{
    	    strength = 8;
    	    health = 85;
    	    intelligence = 12;
    	}
    	else if (racechoice == 3)
    	{
    	    cout << "Humans have a good overall build, with 10 strength and 8 intelligence, and 100 health to start with. Elves start with only 85 health, and 8 strength, but they have 12 intelligence." << endl;
    	    cout << "---------------------------------------" << endl;
    	}
    	else
    	{
    	    cout << "Invalid input, please choose an input from 1-3." << endl;
    	    cout << "---------------------------------------" << endl;
    	}
	}
	
	string roleinput;
	
	int rolechoice = 0;
	while (rolechoice < 1 || rolechoice > 2)
	{
    	cout << "Please choose a role below, or press 3 for more information about the differences between each role." << endl;
    	cout << "1. Warrior" << endl;
    	cout << "2. Wizard" << endl;
    	cout << "3. More information" << endl;
    	cout << "---------------------------------------" << endl;
    	cout << "=> ";
    	getline (cin, roleinput);
    	if (!isdigit(roleinput[0]))
    	{
    	    cout << "Invalid input, please choose an input from 1-3." << endl;
    	    cout << "---------------------------------------" << endl;
    	   continue;
    	}
    	else
    	{
    	    rolechoice = stoi(roleinput);
    	}
    	if (rolechoice == 1)
    	{
    	    strength += 2;
    	}
    	else if (rolechoice == 2)
    	{
    	    intelligence += 2;
    	}
    	else if (rolechoice == 3)
    	{
    	    cout << "Warriors get a +2 to the strength stat, Wizards get a +2 to intelligence." << endl;
    	    cout << "---------------------------------------" << endl;
    	}
    	else 
    	{
    	    cout << "Invalid input, please choose an input from 1-3." << endl;
    	    cout << "---------------------------------------" << endl;
    	}
	}
	
	
	Player p1(namechoice, racechoice, rolechoice, health, strength, intelligence, stuff);
	cout << "You have chosen to play as " << p1.getPlayerName() << ", a " << getRaceString(p1) << " " << getRoleString(p1) << endl;
	return p1;
	
}


Game::Game()
{
    cout << endl;
}

/////////////////////////////////////////////}


void Game::turnMenu(){
    cout << "What would you like to do? You can:" << endl;
	cout << "1. Go North" << endl;
	cout << "2. Go West" << endl;
	cout << "3. Go East" << endl;
	cout << "4. View Stats" << endl;
	cout << "5. Rest Here" << endl;
	cout << "6. View & Use Items" << endl;
	cout << "7. Help" << endl;
	cout << "8. Quit Game" << endl;
	cout << "---------------------------------------" << endl;
}

void Game::fightMenu(){
    cout << "1. Attack" << endl;
    cout << "2. Block" << endl;
    cout << "3. View / Use Items" << endl;
    cout << "4. View Stats" << endl;
    cout << "5. Help" << endl;
    cout << "6. Run Away" << endl;
    cout << "---------------------------------------" << endl;
}



Monster Game::initializeMonster(string fileName, Monster m1)
{
    
    string line = "";
    string stats[3];
    
    ifstream myfile;
    myfile.open(fileName);
    
    int outcome = rand() % 8;
    if (myfile.is_open())
    {
        
        
        for (int i = 0; i < outcome - 1; i++)
        {
            getline(myfile, line);
        }
        getline(myfile, line);
        
        
        split(line, ',', stats, 3);
        m1.setMonsterName(stats[0]);
        m1.setHealth(stoi(stats[1]));
        m1.setMonsterStrength(stoi(stats[2]));
    }
    else 
    {
        cout << endl;
    }
    
    //cout << m1.getMonsterName() << endl;
    return m1;
}

Item Game::initializeItem(string fileName, Item item1)
{
    
    string line = "";
    string stats[4];
    
    ifstream myfile;
    myfile.open(fileName);
    
    int outcome = rand() % 7;
    if (myfile.is_open())
    {
        for (int i = 0; i < outcome - 1; i++)
        {
            getline(myfile, line);
        }
        getline(myfile, line);
        
        split(line, ',', stats, 4);
        item1.setItemName(stats[0]);
        item1.setHealthStat(stoi(stats[1]));
        item1.setStrengthStat(stoi(stats[2]));
        item1.setIntelligenceStat(stoi(stats[3]));
    }
    else 
    {
        cout << "error" << endl;
    }
    
return item1;
}


Player Game::fightFunc(Player p1)
{
    string choice = "";
        Monster m1;
        m1 = initializeMonster("monster.txt", m1);
        monsterdead = false;
        escaped = false;
        cout << "You've ran into a: " << m1.getMonsterName() << endl;
        cout << m1.getMonsterName() << " health: " << m1.getHealth() << endl;
        cout << m1.getMonsterName() << " strength: " << m1.getMonsterStrength() << endl;
        cout << "---------------------------------------" << endl;
        while (!dead && !quit && !monsterdead && !escaped)
        {
            fightMenu(); //1.attack 2.defend 3.use item 4.run away
            cout << "=> ";
            getline (cin, choice);
            
            if (choice != "" && isdigit(choice[0]))
            {
                int menuChoice = stoi(choice);
                switch (menuChoice)
                {
                    case 1: //attack
                    {
                        //monster attack
                        p1.setHealth(-m1.getMonsterStrength());
                        if (p1.getHealth() <= 0)
                        {
                            dead = true;
                        }
                        
                        
                        //player attack
                        if (getRoleString(p1) == "Warrior")
                        {
                            m1.setHealth(-p1.getStrength());
                        }
                        else if (getRoleString(p1) == "Wizard")
                        {
                            m1.setHealth(-p1.getIntelligence());
                        }
                        if (m1.getHealth() <= 0)
                        {
                            monsterdead = true;
                        }
                        cout << "Player health: " << p1.getHealth() << endl;
                        if (m1.getHealth() > 0)
                        {
                            cout << m1.getMonsterName() << " health: " << m1.getHealth() << endl;
                        }
                        else if (m1.getHealth() <= 0)
                        {
                            cout << m1.getMonsterName() << " health: 0" << endl;
                        }
                        break;
                    }
                    case 2: //defend / block
                    {
                        int blockedDamage = m1.getMonsterStrength() / 2;
                        p1.setHealth(-blockedDamage);
                        if (p1.getHealth() <= 0)
                        {
                            dead = true;
                        }
                        cout << "Player health: " << p1.getHealth() << endl;
                        cout << m1.getMonsterName() << " health: " << m1.getHealth() << endl;
                        break;
                        
                    }
                    case 3: //use item
                    {
                        //item func
                        cout << "Inventory: " << endl <<
                        "---------------------------------------" << endl;
                        p1.showInventory();
                        cout << "Which item would you like to use?" << endl;
                        cout << "=> ";
                        getline (cin, choice);
                        if (choice == "Q" || choice == "q")
                        {
                            break;
                        }
                        else
                        {
                            if (isdigit(choice[0]))
                            {
                                int menuChoice = stoi(choice);
                                Item item5;
                                string nameStored = item5.getItemName();
                                p1.useItem(menuChoice);
                                cout << nameStored << " was used. New stats are: " << endl;
                                cout << "---------------------------------------" << endl;
                                p1.dumpStats();
                                cout << "---------------------------------------" << endl;
                            }
                            else
                            {
                                cout << "Invalid input, please try one of the numbers corresponding to the menu options." << endl;
    	                        cout << "---------------------------------------" << endl;
                            }
                        }
                        break;
                    }
                    case 4: //view stats
                    {
                        //view stats
                        p1.dumpStats();
                        cout << endl;
                        break; 
                    }
                    case 5: //help
                    {
                        cout << "Attack deals damage to the enemy based on your strength if you are a warrior, or based on your intelligence if you are a wizard." << endl;
                        cout << "Block halves the damage done to you" << endl;
                        cout << "View / Use items allows you to use items in your inventory" << endl;
                        cout << "View stats shows your character's stats" << endl;
                        cout << "Running away has a 50 percent chance of allowing you to escape a fight" << endl;
                    }
                    case 6: //run away
                    {
                        int runSuccess = rand() % 100;
                        if (runSuccess < 50)
                        {
                            p1.setHealth(-m1.getMonsterStrength());
                            if (p1.getHealth() <= 0)
                            {
                                dead = true;
                            }
                            cout << "You tried to escape ... and failed! The " << m1.getMonsterName() << " hit you while you were trying to escape." << endl;
                            cout << "Player health: " << p1.getHealth() << endl;
                            break;
                        }
                        else if (runSuccess >= 50)
                        {
                            cout << "You successfully escaped the encounter with the " << m1.getMonsterName() << ". " << endl;
                            escaped = true;
                            break;
                        }
                    }
                }   
            }
            else
            {
    	        cout << "Invalid input, please try one of the numbers corresponding to the menu options." << endl;
    	        cout << "---------------------------------------" << endl;
            }
        }

    return p1;
}





Player Game::roomFunc(Player p1)
{
    int outcome = rand() % 100;
    if (outcome <= 60)
    {
        fightFunc(p1);
        
    }
    else if (outcome > 60 && outcome < 93)
    {
        //item here
        Item item3;
        item3 = initializeItem("items.txt", item3);
        cout << "You've found a: " << item3.getItemName() << "!" << endl;
        cout << "---------------------------------------" << endl;
        p1.setItem(item3);
    }
    else if (outcome >= 93)
    {
        chestFound = true;
        cout << "---------------------------------------" << endl;
    }
    return p1;
}



Player Game::restFunc(Player p1)
{
    int outcome = rand() % 100;
    if (outcome <= 57)
    {
        //regain 4 health from resting
        // int tiredHealth = p1.getHealth();
        p1.setHealth(4);
        cout << "You decide to set up camp and try to sleep through the night. It pays off, and you regain 4 health with a good night's rest." << endl;
        cout << "You now have " << p1.getHealth() << " health" << endl;
        cout << "---------------------------------------" << endl;
    }
    else if (outcome > 43)
    {
        //make a monster and begin a fight
        Monster m1;
        cout << "You decide to set up camp and try to sleep through the night." << endl <<
        "But just as you are about to get into your bed, a " << m1.getMonsterName() << " walks into the room, interrupting your much needed rest!" << endl;
        cout << "---------------------------------------" << endl;
        fightFunc(p1);
    }
    return p1;
}



void Game::initializeLeaderboard(string line)
{
    ofstream myfileout;
    myfileout.open("leaderboard.txt", ios_base::app);
    myfileout << line << endl;
}



bool Game::runGame(Player p1)
{
    struct timeval t1;
    gettimeofday(&t1, NULL);
    srand(t1.tv_usec * t1.tv_sec);
    string choice;
    int turnCount = 0;
    // int viewStatAdjustment = 0;
    while (!chestFound && !dead && !quit)
    {
        //display turnmenu & input needs to be read for a decision
        cout << "Turn number: " << turnCount << endl;
        turnMenu();
        cout << "=> ";
        getline (cin, choice);
        if (choice != "" && isdigit(choice[0]))
        {
                
            int menuChoice = stoi(choice);
            switch (menuChoice)
            {
                case 1:
                {
                    p1 = roomFunc(p1);
                    cout << endl;
                    break;
                }    
                case 2:
                {
                    p1 = roomFunc(p1);
                    cout << endl;
                    break;
                }    
                case 3:
                {
                    p1 = roomFunc(p1);
                    cout << endl;
                    break;
                }   
                case 4:
                {
                    //view stats
                    p1.dumpStats();
                    turnCount--;
                    cout << endl;
                    break;
                }   
                case 5: 
                {
                    //rest func
                    p1 = restFunc(p1);
                    cout << endl;
                    break;
                }
                case 6: 
                {
                    //item func
                    cout << "Inventory: " << endl <<
                    "---------------------------------------" << endl;
                    p1.showInventory();
                    cout << "Which item would you like to use?" << endl;
                    cout << "=> ";
                    getline (cin, choice);
                    if (choice == "Q" || choice == "q")
                    {
                        turnCount--;
                        break;
                    }
                    else
                    {
                        if (isdigit(choice[0]))
                        {
                            int menuChoice = stoi(choice);
                            Item item4;
                            string nameStored = item4.getItemName();
                            p1.useItem(menuChoice);
                            cout << nameStored << " was used. New stats are: " << endl;
                            cout << "---------------------------------------" << endl;
                            p1.dumpStats();
                            cout << "---------------------------------------" << endl;
                        }
                        else
                        {
                	        cout << "Invalid input, please try one of the numbers corresponding to the menu options." << endl;
                	        cout << "---------------------------------------" << endl;
                        }
                    }
                    break;
                }
                case 7: 
                {
                    cout << "Moving in any direction puts you into an unexplored room, which could either have a: " << endl <<
                    "1. Monster -  Which you would have to fight" << endl <<
                    "2. Item - Such as a potion that could buff one of your stats" << endl <<
                    "3. Chest - This is what you are looking for, once you find this, you win the game" << endl;
                    cout << endl;
                    cout << "View stats shows you all of your character's stats" << endl;
                    cout << "Resting allows you to regain a small portion of health by sleeping, but also has a chance of a monster approaching you while sleeping." << endl;
                    cout << "View & Use Items shows all of your items & allows you to choose an item to use" << endl;
                    cout << "Quit game leaves the game." << endl;
                    turnCount--;
                    break;
                }
                case 8:
                {
                    //quit
                    cout << "Later loser :P" << endl;
                    cout << "---------------------------------------" << endl;
                    cout << endl;
                    quit = true;
                    break;
                }    
                default:
                {
                    //invalid input
                    cout << "Invalid input, please try one of the numbers corresponding to the menu options." << endl;
                    cout << "---------------------------------------" << endl;
                    cout << endl;
                }
                
            }
            turnCount++;
        }
        else
        {
	        cout << "Invalid input, please try one of the numbers corresponding to the menu options." << endl;
	        cout << "---------------------------------------" << endl;
        }
        
            //room probability function needs to be made and then called for any movement decision
                //probablity function is "rolled", options are 60% monster odds, 35% item, 5% chest
                
                //if monster is rolled, random monster from monster file needs to be read and monster object created
                //fight menu displayed
                
                //if item is rolled, random item from file needs to be read and item object created
                //message will tell them they got it and display all of their items after pickin it up
                
                //if chest is rolled, while loop is broken, jump to if statement for winning. 
                
            //item menu needs to be displayed if they want to use item
            //health needs to gain 2 points/they need a suprise encounter if they decide to rest
            //if quit is chosen, break loop (maybe have save functionality here to fufill writing to a file)
    }
    if (chestFound)
    {
        string numTurns = to_string(turnCount);
        cout << "You've finally found the chest you were searching for!" << endl <<
        "Congratulations, you've won the game in " << turnCount << " turns!" << endl;
        string successStatement = p1.getPlayerName() + ", a " + getRaceString(p1) + " " + getRoleString(p1) + " - found the chest in " + numTurns + " turns.";
        Game::initializeLeaderboard(successStatement);
        cout << endl;
    }
    if (dead)
    {
        cout << "You died. Loser." << endl;
        cout << endl << endl; 
        cout << "Your adventure ended on turn " << turnCount << endl;
    }
}





