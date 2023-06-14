#include <iostream>

using namespace std;

/*
A singly linked list is a type of linked list that is unidirectional, that is, 
it can be traversed in only one direction from head to the last node (tail). 
Each element in a linked list is called a node. A single node contains data 
and a pointer to the next node which helps in maintaining the structure of the 
list.
*/

struct Nodo {
    int data;
    Nodo* next;
};

class SinglyLinkedList {
private:
    Nodo* head;
public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Function to check if the singly linked list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Function to insert a node at the beginning of the singly linked list
    void insertAtBeginning(int data) {
        Nodo* newNodo = new Nodo();
        newNodo->data = data;
        newNodo->next = head;
        head = newNodo;
    }

    // Function to insert a node at the end of the singly linked list
    void insertAtEnd(int data) {
        Nodo* newNodo = new Nodo();
        newNodo->data = data;
        newNodo->next = nullptr;
        if (head == nullptr) {
            head = newNodo;
            return;
        }
        Nodo* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNodo;
    }

    // Function to delete a node from the singly linked list
    void deleteNode(int data) {
        if (head == nullptr) {
            return;
        }
        if (head->data == data) {
            Nodo* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Nodo* current = head;
        while (current->next != nullptr && current->next->data != data) {
            current = current->next;
        }
        if (current->next != nullptr) {
            Nodo* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Function to display the singly linked list
    void display() {
        Nodo* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList sll;
    
    sll.insertAtBeginning(10);
    sll.insertAtBeginning(20);
    sll.insertAtEnd(40);
    sll.insertAtEnd(30);
    
    std::cout << "Singly linked list: ";
    sll.display();  // Output: 20 10 30 40
    
    sll.deleteNode(30);
    
    std::cout << "Singly linked list after deletion: ";
    sll.display();  // Output: 20 10 40
    
    return 0;
}
