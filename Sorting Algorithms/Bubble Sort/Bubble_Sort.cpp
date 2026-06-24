#include <iostream>

int main () {

    int arr[5] = {5, -4, 3, 2, -1};
    int temp;
    int array_size = sizeof(arr) / sizeof(arr[0]);
    std::cout <<"The Original Array:" << std::endl;
    for (int i; i < array_size; i++) {
        std::cout << arr[i] << std::endl;
    }
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
    for (int i = 0; i < array_size; i++) {
        std::cout << arr[i];
    }
    return 0;
    // Print the runtime of the program
    std::cout << "The runtime of the program is: " << clock() << "ms" << std::endl;
}