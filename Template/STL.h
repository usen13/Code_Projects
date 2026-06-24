#pragma once
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <cmath>

class TemplateClass {

    private:
    int value;
    int placeHolder;
    public:

    template <typename T> T Addition (const T &a, const T &b) {
        return a + b;
    }

    template <typename T> T LargestNum (const T &a, const T &b) {
        return (a >= b) ? a : b;
    }
    TemplateClass() {
        std::cout << "Template Class Constructor" << std::endl;
        std::cout << "Addition of 5 and 10: " << Addition(5, 10) << std::endl;
        std::cout << "Addition of 5.5 and 10.5: " << Addition(5.5, 10.5) << std::endl;
        std::cout << "Larger of 5.5 and 10.5 is: " << LargestNum(5.5, 10.5) << std::endl;
    }

    void setValue(int& a, int& b) { 
        value = a;
        placeHolder = b; 
    }
    int getValue() { return value;  }
    int getPlaceHolder() { return placeHolder;  }
};


template <class T> class StringClass {
    private:
    T str;
    public:
    StringClass() {}
    StringClass(T s) : str(s) {}
    ~StringClass() {
        std::cout << "StringClass Destructor called" <<  std::endl;
    }
    T getString() { return str; }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long original = x;
        long long rev = 0;
        int temp = x;
        while (temp != 0) {
            rev = rev * 10 + (temp % 10);
            temp /= 10;
        }
        return rev == original;
    }
};

class Singleton {

    private: 
    int a;
    Singleton() : a(25) {
        std::cout << "Singleton Instance Created" << std::endl;
    }
    ~Singleton() = default;

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
    
    int getA() {
        return a;
    }
    void setA(int val) {
        a = val;
    }

    void showMessage() {
        std::cout << "Singleton Instance Accessed" << std::endl;
    }

};

template <typename T> T divide (const T& a, const T& b) {
    return a/b;
}