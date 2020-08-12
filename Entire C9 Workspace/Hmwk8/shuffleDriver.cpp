// CS1300 Spring 2019
// Author: Kevin Busch
// Recitation: 301 – Thanika Reddy
// Cloud9 Workspace Editor Link: https://csci1300-kevinbusch.c9users.io
// Project
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//function returns a vector and takes 2 in
// first, make an edge case for if both vectors are empty.
// after that, use if to check if first vector is bigger or same size as second. If so, within a loop, push_back first vector first value, then change variable, so second is pushed back.
// once for loop reaches size of smaller vector, loop through rest of bigger vector and put into shuffled vector. 
// do the same thing for the else, but the second vector comes first.

vector<int> shuffle(vector<int> first, vector<int> second)
{
    
    
    vector<int> third; //vector with shuffled values
    if (first.empty() && second.empty()) //edge case for both empty
    {
        return third;
    }
    
    int h = 1; //switch variable
    
    if (first.size() >= second.size()) //when first vector is bigger
    {
        for (int i = 0; i < second.size(); i++) //while within bounds of smaller vector, 
        {
            if (h = 1) //begin with first vector and anytime after second vector has pushed
            {
                third.push_back(first[i]);
                h = 2;
            }
            if (h = 2) //after first vector pushed, triggers second to push
            {
                third.push_back(second[i]);
                h = 1;
            }
            
        }
        for (int j = second.size(); j < first.size(); j++) //after smaller vector has no more to push, loop through rest of big vector and push
        {
            third.push_back(first[j]);
        }
        return third;
    }
    else //opposite for if second vector is bigger
    {
        for (int i = 0; i < first.size(); i++) //within bounds of smaller vec
        {
            if (h = 1) //start with second vec and after first has pushed, this is triggered
            {
                third.push_back(second[i]);
                h = 2;
            }
            if (h = 2) //trigger for smaller vec
            {
                third.push_back(first[i]);
                h = 1;
            }
            
        }
        for (int j = first.size(); j < second.size(); j++) //after smaller vector has no more to push, loop through rest of big vector and push
        {
            third.push_back(second[j]);
        }
        return third;
    }
    
}

int main()
{
    vector<int> v1{2,-5,0,19};
    vector<int> v2;
    vector<int> v3 = shuffle(v1,v2);
    for (int i=0; i < v3.size(); i++) 
    {
    cout << v3[i] << " ";
    }
    cout << endl;
    
    vector<int> v4{1,3,5,9};
    vector<int> v5{2,4,6,8,10};
    vector<int> v6 = shuffle(v4,v5);
    for (int i=0; i < v6.size(); i++) 
    {
    cout << v6[i] << " ";
    }
}
