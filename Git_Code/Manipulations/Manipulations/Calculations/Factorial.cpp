#include <iostream>

int main () {
    int num = 5;
    int result = 1;
    std::cout << "The value whose factorial you want is :" << num << std::endl;
    //std::cin >> num;
    
    for (int i = 1; i <= num; i++) {
        //std::cout << result;
        result = result * i;
    }
    std::cout << "The factorial is:" << result << std::endl;
    return 0;
}