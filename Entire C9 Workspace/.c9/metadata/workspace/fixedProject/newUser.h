{"filter":false,"title":"newUser.h","tooltip":"/fixedProject/newUser.h","undoManager":{"mark":0,"position":0,"stack":[[{"start":{"row":5,"column":0},"end":{"row":40,"column":6},"action":"remove","lines":["#include <iostream>","#include <fstream>","#include <string>","using namespace std;","","#ifndef USER_H","#define USER_H","/*","Algorithm: ","1.","Input parameters: ","Output (prints to screen): ","Returns: none","*/","","class User","{","","public:","    User(); //default constructor","    User(string, int[], int); //parameterized constructor","    void setUsername(string); //setter for username string","    string getUsername(); //getter for username","    bool setRatingAt(int, int); //setter for rating at specified indices","    int getRatingAt(int); //getter for rating at index","    void setNumRatings(int); //setter for numratings","    int getNumRatings(); //getter for numratings","    int getSize();","","private:","    string username;","    int ratings[50];","    int numRatings;","    int size; //n2s does this need to be initializedabove ratings and then go into the brackets for ratings?","};","#endif"],"id":2},{"start":{"row":5,"column":0},"end":{"row":41,"column":6},"action":"insert","lines":["#ifndef USER_H","#define USER_H","","#include <iostream>","#include <fstream>","#include <string>","using namespace std;","","/*","Algorithm: ","1.","Input parameters: ","Output (prints to screen): ","Returns: none","*/","","class User","{","","public:","   User(); //default constructor","   User(string, int[], int); //parameterized constructor","   void setUsername(string); //setter for username string","   string getUsername(); //getter for username","   bool setRatingAt(int, int); //setter for rating at specified indices","   int getRatingAt(int); //getter for rating at index","   void setNumRatings(int); //setter for numratings","   int getNumRatings(); //getter for numratings","   int getSize();","","private:","   string username;","   int ratings[50];","   int numRatings;","   int size; //n2s does this need to be initializedabove ratings and then go into the brackets for ratings?","};","#endif"]}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":41,"column":6},"end":{"row":41,"column":6},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":9,"state":"start","mode":"ace/mode/c_cpp"}},"timestamp":1553282804587,"hash":"b87d11b1f0b9d086693b7bcbd1a4f93742c94d7b"}