#pragma once
#include <iostream>

struct Node {
    int a;
    Node* next = nullptr;
};

class LinkedList {
    
    public:
    Node* head;

    LinkedList () : head(nullptr) {}
    ~LinkedList () {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void insertNode(const int& data) {
        Node* node = new Node{data, head};
        head = node;
    }

    LinkedList (const LinkedList&) = delete;
    LinkedList (LinkedList&&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
    LinkedList& operator=(LinkedList&&) = delete;

    Node checkDataByTraversal() {
        Node* current = head;
        while (current != nullptr) {
            // Process current node
            current = current->next;
        }
        return *head;
    }
};


class MoveConstructorExample {
    private:
    int* data, size;

    public:
    MoveConstructorExample(int s) : size(s) {
        data = new int[size];
        std::cout<< "Constructor called, allocated size: " << size << std::endl;
    }
    ~MoveConstructorExample() {
        delete[] data;
        std::cout << "Destructor called, deallocated size: " << size << std::endl;
    }
    
    // Disable copy constructor and copy assignment operator
    MoveConstructorExample (const MoveConstructorExample& other) = delete;
    MoveConstructorExample& operator=(const MoveConstructorExample& other) = delete;

    MoveConstructorExample(MoveConstructorExample&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move Constructor called, moved size: " << size << std::endl;
    }

    MoveConstructorExample& operator=(MoveConstructorExample&& other) noexcept {
        if (this != &other) {
            delete[] data; // Free existing resource
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            std::cout << "Move Assignment Operator called, moved size: " << size << std::endl;
        }
        return *this;
    }

    void SetData(const int& value) {
        this->size = value;
        this->data = &size;
    }

    const int* GetPointerData() const {
        return data;
    }
    const int GetSize() const {
        return size;
    }

};
