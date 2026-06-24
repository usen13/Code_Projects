#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> rand_Num_Gen(int array_size);

int main () {
    cout << "Before Sorting: " << endl;
    
    vector<int> myArray = rand_Num_Gen(10);
    for (int i=0; i<10; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;
    for (int i = 0; i<10; i++) {
        int min_x = i;
        for (int j = i+1; j<10; j++) {
            if (myArray[j] < myArray[min_x]) min_x = j;
        }
        swap(myArray[i], myArray[min_x]);
    }
    cout << "After Sorting: " << endl;
    for (int i=0; i<10; i++) {
        cout << myArray[i] << " ";
    }
    return 0;
}

vector<int> rand_Num_Gen(int array_size) {
    vector<int> myArray;
    for (int i=0; i < array_size; i++) {
        myArray.push_back(std::rand());  
    }
    return myArray;
}
