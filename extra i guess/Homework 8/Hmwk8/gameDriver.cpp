// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Hmwk8
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Player.h"
#include "Team.h"
using namespace std;

/*
Algorithm: 
1.
Input parameters: 
Output (prints to screen): 
Returns: none
*/

double teamTotalPoints(Team teamInput)
{
    double total = 0;
    int teamPlayerNum = teamInput.getNumPlayers();
    
    for (int i = 0; i < 3; i++)
    {
        total += teamInput.getPlayerPoints(i);
    }
    return total;
}

string game(Team team1, Team team2)
{
    
    int t1NumPlayers = team1.getNumPlayers();
    int t2NumPlayers = team2.getNumPlayers();
    
    if (t1NumPlayers < 4 || t2NumPlayers < 4)
    {
        return "forfeit";
    }
    
    double t1Total = teamTotalPoints(team1);
    cout << "t1Total: " << t1Total << endl;
    
    double t2Total = teamTotalPoints(team2);
    cout << "t2Total: " << t2Total << endl;
    if (t1Total == t2Total)
    {
        return "draw";
    }
    else if (t1Total > t2Total)
    {
        return team1.getTeamName();
    }
    else if (t2Total > t1Total)
    {
        return team2.getTeamName();
    }
    
}

int main()
{
    Team team1("Seg Faultline");
    team1.readRoster("roster1.txt");
    Team team2("Team Maim");
    team2.readRoster("roster2.txt");
    string winner = game(team1, team2);
    cout << "The winner is: " << winner << endl;
}