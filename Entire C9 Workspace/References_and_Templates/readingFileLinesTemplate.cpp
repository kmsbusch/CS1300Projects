#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int main(){
    //create an output file stream for writing to file
    ifstream myfile;
    //open the file file1.txt with the file stream
    myfile.open("examplefile.txt");
    if (myfile.is_open()){
        // do things with the file
        string line = "";
        int lineidx = 0;
        // read each line from the file
        while (getline(myfile, line)) {
            // print each line read from the file
            cout << lineidx << ": " << line << endl;
            // increment index(count of lines in the file)
            lineidx++;
        }
    }
    else {
    cout << "file open failed" << endl;
    }
    // closing the file
    myfile.close();
}

