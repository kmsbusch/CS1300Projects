// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Hmwk8
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Team.h"
using namespace std;

/*
Algorithm: 
1.
Input parameters: 
Output (prints to screen): 
Returns: none
*/

int main()
{
    // checking parameterized constructor
    Team team3("Seg Faultline");
    cout << team3.getTeamName() << endl;
    cout << team3.getNumPlayers() << endl;
    
    // checking readRoster gets the right number of players (getNumPlayers)
    Team team4("Thats so Ravenclaw");
    cout << team4.getTeamName() << endl;
    team4.readRoster("roster1.txt");
    int n3 = team4.getNumPlayers();
    cout << n3 << endl;
    
    // checking readRoster gets the right number of players (getNumPlayers)
    
    team4.readRoster("roster1.txt");
    int n4 = team4.getNumPlayers();
    for (int i = 0; i < n4; i++) {
        cout << team4.getPlayerName(i) << " ";
        cout << team4.getPlayerPoints(i) << endl;
    }
    
    // checking readRoster, multiple files
    Team team5("Awkward Turtles");
    cout << team5.getTeamName() << endl;
    team5.readRoster("roster3.txt");
    team5.readRoster("roster1.txt");
    int n5 = team5.getNumPlayers();
    for (int i = 0; i < n5; i++) {
        cout << team5.getPlayerName(i) << " ";
        cout << team5.getPlayerPoints(i) << endl;
    }
    
    // checking getter player name functions
    Team team6("Llamas Pajamas");
    cout << team6.getTeamName() << endl;
    team6.readRoster("roster3.txt");
    cout << team6.getPlayerName(-1) << endl;
   


}