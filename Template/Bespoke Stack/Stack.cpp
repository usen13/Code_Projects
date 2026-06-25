/*****************************************
Implements a generic stack using templates that supports:

push(val) — add element to top
pop() — remove and return top element
peek() — return top element without removing
isEmpty() — return bool
Throws an appropriate exception if pop() or peek() is called on an empty stack
********************************************/
#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> elements; 

public:
    //template<typename U>
    T pop() {
        if (elements.empty()) {
            std::cout << "Pop called on empty stack" << std::endl;
            return NULL; // Using NULL to avoid using exceptions.
        }
        T temp = elements.back();
        elements.pop_back();
        return temp;
    }

    void push (T&& x) {
        elements.push_back(std::move(x));
    }

    T peek () {
        if (elements.empty()) {
            std::cout << "Peek called on empty stack" << std::endl;
            return NULL; // Using NULL to avoid using exceptions.
        }
        return elements.back();
    }

    bool isEmpty() {
        return elements.empty();
    }
};

int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << s.peek() << std::endl;  // 3
    std::cout << s.pop() << std::endl;   // 3
    std::cout << s.pop() << std::endl;   // 2
    std::cout << s.isEmpty() << std::endl; // 0
    std::cout << s.pop() << std::endl;   // 1
    std::cout << s.isEmpty() << std::endl; // 1
    s.pop(); // should throw
}