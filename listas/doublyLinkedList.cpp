#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to check if the doubly linked list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Function to insert a node at the beginning of the doubly linked list
    void insertAtBeginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    // Function to insert a node at the end of the doubly linked list
    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    // Function to delete a node from the doubly linked list
    void deleteNode(int data) {
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
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    // Function to display the doubly linked list in forward direction
    void displayForward() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to display the doubly linked list in reverse direction
    void displayBackward() {
        Node* current = head;
        if (current == nullptr) {
            return;
        }
        while (current->next != nullptr) {
            current = current->next;
        }
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    
    dll.insertAtBeginning(10);
    dll.insertAtBeginning(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);
    
    cout << "Doubly linked list hacia adelante: ";
    dll.displayForward();  // Output: 20 10 30 40

    cout << "Doubly linked list en reversa: ";
    dll.displayBackward();  // Output: 40 30 10 20
    
    dll.deleteNode(30);
    
    cout << "Doubly linked list despues de eliminar nodos: ";
    dll.displayForward();  // Output: 20 10 40
    
    return 0;
}