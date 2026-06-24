#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> rand_Num_Gen(int array_size);

int main () {
    vector<int> myArray = rand_Num_Gen(10);
    cout << "Size of the array: " << myArray.size() << endl;
    cout << "Before Sorting: " << endl;
    for (int i=0; i<10; i++) {
        cout << myArray[i] << " ";
    }
    cin.get();
    cout << endl;
    for (int i = 0; i<10; i++) {
        int min_x = i;
        for (int j = i+1; j<10; j++) {
            if (myArray[j] < myArray[min_x]) min_x = j;
        }
        if (min_x != i) swap(myArray[i], myArray[min_x]);
    }
    cout << "After Sorting: " << endl;
    for (int i=0; i<10; i++) {
        cout << myArray[i] << " ";
    }
    // Pausing before program terminates
    cin.get();
    return 0;
}

vector<int> rand_Num_Gen(int array_size) {
    vector<int> myArray;
    cout << "Enter values you want to be sorted, max values allowed is 10: " << endl; 
    for (int i=0; i < array_size; i++) {
        cout << "Enter value " << i+1 << ": ";
        int input;
        cin >> input;
        myArray.push_back(input);
        
    }
    return myArray;
}
