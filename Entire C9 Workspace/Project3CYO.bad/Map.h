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

#ifndef MAP_H
#include MAP_H

class Map
{
public:
    Map();
    Map(int[][], int); //2d array & row number
    void setRow(int);
    int getRow();
    void setColumn(int);
    int getColumn();
    void setChestRoom(int, int)
    
   
    
private:
    int row;
    int column;
    
    
};
#endif