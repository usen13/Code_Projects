/***************************************** 
Implementing a smart pointer — specifically a simplified version of unique_ptr.

Takes ownership of a raw pointer on construction
Automatically deletes the pointer on destruction
Support * and -> operators
Not copyable but movable
Has a get() method returning the raw pointer
Has a release() method that relinquishes ownership and returns the raw pointer
******************************************/
#include <iostream>

template <typename T>
class UniquePtr {
public:
    UniquePtr(T* obj) : variable(obj) {}
    
    ~UniquePtr () {
        delete variable;
    }

    T& operator*() {
        return *variable;
    }

    T* operator->() {
        return variable;
    }

    UniquePtr (const UniquePtr& obj) = delete; 
    UniquePtr& operator=(const UniquePtr&) = delete; 
    
    // Move semantics

    UniquePtr (UniquePtr&& obj) : variable(obj.variable) {
        obj.variable = nullptr;
    }

    UniquePtr operator=(UniquePtr&& obj) {
        if (this != &obj) {
            delete variable;
            variable = obj.variable;
            obj.variable = nullptr;
        }
        return *this;
    } 

    T* get() const {
        return variable;
    }

    T* release() {
        T* temp = variable;
        variable = nullptr;
        return temp;
    }

private:
    T* variable; 
};

int main() {
    UniquePtr<int> p1(new int(42));
    std::cout << *p1 << std::endl;         // 42

    UniquePtr<int> p2 = std::move(p1);
    std::cout << *p2 << std::endl;         // 42
    std::cout << p1.get() << std::endl;    // 0 (nullptr)
    std::cout << p1.release() << std::endl;
}