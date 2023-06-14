#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Clase para lista enlazada simple
class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Función para verificar si la lista simple% enlazada está vacía o no
    bool isEmpty() {
        return head == nullptr;
    }

    // Función para insertar un nodo al principio de la L.S.E.
    void insertAtBeginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Función para insertar un nodo al final de la L.S.E.
    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Función para borrar un nodo desde la L.S.E.
    void deleteNode(int data) {
        if (head == nullptr) {
            return;
        }
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data != data) {
            current = current->next;
        }
        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Función para mostrar contenido de la L.S.E.
    void display() {
        Node* current = head;
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
    sll.insertAtEnd(30);
    sll.insertAtEnd(40);
    
    std::cout << "Lista enlazada simple: ";
    sll.display();  // Output: 20 10 30 40
    
    sll.deleteNode(30);
    
    std::cout << "Lista enlazada simple después de eliminar un nodo: ";
    sll.display();  // Output: 20 10 40
    
    return 0;
}