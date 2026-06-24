#include <iostream>

struct Node
{
    Node* prev;
    int data;
    Node* next;
};


class Doubly_Linked_List {
private:
    int size;
    Node* head;
    Node* tail;

    public:

    Doubly_Linked_List() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        size++;
    }

    void remove(int data) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                size--;
                return;
            }
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

    void print_reverse() {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

};

int main () {
    Doubly_Linked_List list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.print();
    list.print_reverse();
    list.remove(3);
    list.print();
    list.print_reverse();
    list.remove(1);
    list.print();
    list.print_reverse();
    list.remove(5);
    list.print();
    list.print_reverse();
    list.remove(2);
    list.print();
    list.print_reverse();
    list.remove(4);
    list.print();
    list.print_reverse();
    return 0;
}
