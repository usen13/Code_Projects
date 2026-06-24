#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {

private:
    int size;
    Node* head;

    public:

    LinkedList() {
        size = 0;
        head = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        size++;
    }

    void remove(int data) {
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr) {
            if (current->data == data) {
                if (previous == nullptr) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                size--;
                return;
            }
            previous = current;
            current = current->next;
        }
    }
    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main () {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.print();
    list.remove(3);
    list.print();
    list.remove(1);
    list.print();
    list.remove(5);
    list.print();
    list.remove(2);
    list.print();
    list.remove(4);
    list.print();
    return 0;
}