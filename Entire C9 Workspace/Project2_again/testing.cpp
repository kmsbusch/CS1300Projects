#include <iostream>
#include <fstream>
#include "Library.h"
using namespace std;
int main()
{
    // getRecommendations : newUser cannot be the most similar user
    Library l28 = Library();
    cout << "readbooks = " << l28.readBooks("books.txt") << endl;
    cout << "readRatings = " << l28.readRatings("ratings.txt") << endl;
    cout << "add newUser1 = " << l28.addUser("newUser1") << endl;
    cout << "add newUser2 = " << l28.addUser("newUser2") << endl;
    cout << "add newUser3 = " << l28.addUser("newUser3") << endl;
    cout << "checkOutbook = " << l28.checkOutBook("newUser2", "Naruto", 3) << endl;
    cout << endl;
    l28.getRecommendations("newUser1");
}
