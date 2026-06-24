#include <iostream>
#include <vector>

using namespace std;

// Declare the Parser function before main
void Parser (vector<int> a);

static vector<int> randArray;

int main () {

    randArray.push_back(1);
    randArray.push_back(2);
    randArray.push_back(3);
    randArray.push_back(4);

    Parser (randArray);
    return 0;

}

// Using the Parser function to parse the array using recurssion
void Parser (vector<int> a) {
    if (a.size() == 0) {
        return;
    }
    cout << a[0] << " ";
    a.erase(a.begin());
    Parser(a);
}