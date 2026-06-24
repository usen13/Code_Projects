#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> input_array(int array_size);

int main() {
    int temp = 0;
    vector<int> arr = input_array(10);
    int array_size = arr.size();
    std::cout <<"The Original Array:" << std::endl;
    std::cout << "Array Size: " << array_size << std::endl;
    for (int i = 0; i < array_size; i++) {
        std::cout << arr[i] << std::endl;
    }
    // Bubble sort algorithm
    for (int i = 0; i < array_size; i++) {
        for (int j = 0; j < array_size; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            } else {
                continue;
            }
        }
    }
    std::cout << "The Sorted Array:" << std::endl;
    for (int i = 0; i < array_size; i++) {
        std::cout << arr[i];
    }
    std::cin.get();
    return 0;
}

vector<int> input_array(int array_size) {
    vector<int> arr(array_size);
    std::cout << "Enter values you want to be sorted, max values allowed is 10: " << std::endl;
    for (int i = 0; i < array_size; i++) {
        std::cout << "Enter value " << i+1 << ": ";
        std::cin >> arr[i];
    }
    return arr;
}