//
//

#include "Player.h"
#include "Item.h"
#include "Monster.h"
#include "Game.h"
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <sys/time.h>
using namespace std;


int main()
{
	Game g1;

	Player p1 = g1.startMenu();
	
	g1.runGame(p1);
}