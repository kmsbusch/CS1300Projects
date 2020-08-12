// CSCI1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 - Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project1
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////
// Step1: Steps to solve this problem
// write an algorithm in pseudocode explaining how you are approaching the problem, step by step
///////////////////////////////////////////////////////////////////////////////////////////////////

/*
Algorithm:
Input parameters:
Output (prints to screen):
Returns: none
*/

///////////////////////////////////////////////////////////////////////////////////////////////////
// Step2: Code it up!
// After finishing up your pseudocode, translate them into c++
// IMPORTANT: rollDie() and main() are already written for you.
// You need to complete game function as well as at least 3 other additional functions
	// 1 function needs at least 1 input parameter
	// 1 function must return a value
	// 1 function shouldn't return anything but should print/display something
///////////////////////////////////////////////////////////////////////////////////////////////////



//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX TRASH AREA XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX TRASH AREA XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX



//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX TRASH AREA XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX TRASH AREA XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX





/*
 * rollDie
 * returns a random integer between 1 and 6, works as rolling a dice.
 * return value, int number (1-6)
*/

int rollDie()
{
	return random() % 6 + 1;
}

// your 3 + functions go in here

/*
 * game
 * driver function to play the game
 * the function does not return any value
*/


void startGame() //function to introduce the game, outputs greeting.
{
   cout << "Welcome to Jeopardy Dice!" << endl; 
}
/*
 * function rollValue
 * int roll 
 */

int rollValue(int roll, int turnTotal) // function that determines what happens based on each roll value
{
    if ((roll == 2) || (roll == 5)) // rule for when die value is 2 or 5
    {
        turnTotal = 0; // assign turnTotal 0
    }
    else if (roll == 4) // rule for getting a 4
    {
        turnTotal = 15; // turnTotal is 15
    }
    else if ((roll == 1) || (roll == 3) || (roll == 6)) // rule for 1 3 and 6
    {
        turnTotal += roll; //value is added to roll
    }
    return turnTotal; // return the turnTotal value 
}


/* 
 * function humanTurn represents human's side of the game / rolling the die.
 * returns playerTurnTotal, which is value for the turn.
 */
 
 
int humanTurn()
{
    char choice; //char for the yes or no choice
    int playerTurnTotal = 0; // the turn total will be zero to start
    cout << "" << endl;
    cout << "It is now human's turn" << endl;
    cout << "" << endl;
    cout << "Do you want to roll a dice (Y/N)?:" << endl;
    cin >> choice;
    while ((choice == 'y') || (choice == 'Y')) // if the input is y or Y, triggers the while loop
    {
        int playerRoll = rollDie(); //playerRoll is number rolled from calling rollDie function
        playerTurnTotal = rollValue(playerRoll, playerTurnTotal); // turn total will be equal to the rollValue function
        
        cout << "You rolled a " << playerRoll << endl;
        cout << "Your turn total is " << playerTurnTotal << endl;
        
        if ((playerRoll == 2) || (playerRoll == 5) || (playerRoll == 4)) // if rolled a 2, 5, or 4, break the loop
        {
            break;
        }
        else if ((playerRoll == 1) || (playerRoll == 3) || (playerRoll == 6)) // if rolled a 1, 3, or 6, give option to roll again.
        {
            cout << "Do you want to roll again (Y/N)?:" << endl;
            cin >> choice;
        }
    }
    return playerTurnTotal; // return the playerTurnTotal
    
}
 
/* 
 *function computerTurn is the computer side of the game
 *returns compTurnTotal, which is value for the computer's turn
 */
 
int computerTurn()
{
    int compTurnTotal = 0; //assigns value for compTurnTotal to zero
    while (compTurnTotal < 10) // loop for when the value is less than 10
    {
        int compRoll = rollDie(); // compRoll is the number that is rolled for rollDie
        compTurnTotal = rollValue(compRoll, compTurnTotal); // compTurnTotal will equal the rollValue
        
        cout << "Computer rolled a " << compRoll << endl;
        cout << "Computer turn total is " << compTurnTotal << endl;
        if ((compRoll == 2) || (compRoll == 5) || (compRoll == 4)) // break the loop for any of these values
        {
            break;
        }
    }
    return compTurnTotal; // return value
}



 
/*
 * actualGameFunction is where all of the actual things are run from. 
 * switches the turns, tracks the scores, and prints winner statements
 * no return
 */
 
int actualGameFunction()
{
    int humanPoints = 0; // human total points
    int playerTurnTotal = 0; // human turn points
    int computerPoints = 0; // computer total points
    int compTurnTotal = 0; // computer turn points
    
    while ((humanPoints <= 80) || (computerPoints <= 80)) // as long as nobody has score over 80
    {
        playerTurnTotal = humanTurn(); // set equal because playerTurnTotal is the value after the function humanTurn() is finished
        humanPoints += playerTurnTotal; // the points from the humans turn are added to their total. statements below then keep track of each players current score
        cout << "computer: " << computerPoints << endl;
        cout << "human: " << humanPoints << endl;
        cout << "" << endl;
        if (humanPoints >= 80) //if human gets 80 or more, prints victory statement, ends loop
        {
            cout << "Congratulations! human won this round of Jeopardy Dice!" << endl;
            break;
        }
        
        cout << "It is now computer's turn" << endl;
        cout << "" << endl;
        compTurnTotal = computerTurn(); // assigned to be same because compTurnTotal happens after the computerTurn
        computerPoints += compTurnTotal; // points from the turn are added to total, scores are printed below
        cout << "computer: " << computerPoints << endl;
        cout << "human: " << humanPoints << endl;
        if (computerPoints >= 80) // if computer gets more than 80 points, prints victory statement and breaks.
        {
            cout << "" << endl;
            cout << "Congratulations! computer won this round of Jeopardy Dice!" << endl;
            break;
        }
    }
}


void game() //game function just runs the introductory statement and then the function that runs everything else.
{
    startGame(); //introduction
    actualGameFunction(); //actual game
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// don't change the main.
// Once you finished please paste your code above this line
///////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	// start the game!
    srand(2548);
	game();
	
	return 0;
}