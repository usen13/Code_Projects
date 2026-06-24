#include <iostream>

int main () {
    std::string str = "madam";
    std::string reversed_str = "";
    int length = str.length();

    for (int i = length - 1; i >= 0; i--) {
        reversed_str.push_back(str[i]);
    }

    if (str == reversed_str) {
        std::cout << "The string is a palindrome" << std::endl;
    } else {
        std::cout << "The string is not a palindrome" << std::endl;
    }
    return 0;
}