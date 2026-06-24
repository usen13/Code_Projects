#include <iostream>

int main () {
    int arr[] = {1, 23, 122, 4, 65};
    int length = sizeof(arr) / sizeof(arr[0]);
    int largest = arr[0];

    for (int i = 0; i < length; i++) {
        if (largest < arr[i]) largest = arr[i];
    }

    std::cout << "Largest number: " << largest << std::endl;
    return 0;
}