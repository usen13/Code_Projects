#include <iostream>


int main () {
    std::string str = "Hello, World!";
    std::string reversed_str = "";
    int length = str.length();

    for (int i = length - 1; i >= 0; i--) {
        reversed_str.push_back(str[i]);
    }

    std::cout << reversed_str << std::endl;
    return 0;
}