#include <iostream>
#include <stdexcept>

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        int next;  // Index del next nodeen el array
    };

    Node* nodeList;  // Array almacena los nodos de la lista enlazada 
    int capacity;    // Capacidad del array
    int head;        // Index del nodo head
    int free;        // Index del primer nodo libre

public:
    // Constructor
    LinkedList(int listCapacity) {
        if (listCapacity <= 0) {
            throw std::invalid_argument("Capacidad de lista debe ser positiva.");
        }
        capacity = listCapacity;
        nodeList = new Node[capacity];
        head = -1;  // List esta inicialmente vacia
        free = 0;   // Index primer nodo libre en el array inicialmente

        // Inicializa el puntero next de cada nodo en el array
        // para apuntar al siguiente nodo en array
        for (int i = 0; i < capacity - 1; ++i) {
            nodeList[i].next = i + 1;
        }
        nodeList[capacity - 1].next = -1;  // Ultimo nodo apunta -1 ya que np hay mas nodos
    }

    // Destructor
    ~LinkedList() {
        delete[] nodeList;
    }

    // Comprueba si lista esta vacia
    bool isEmpty() const {
        return head == -1;
    }

    // Comprueba si lista esta llena
    bool isFull() const {
        return free == -1;
    }

    // Inserta un elemento al inicio de la lista
    void insertAtBeginning(const T& item) {
        if (isFull()) {
            throw std::overflow_error("Lista repleta. No se pude insertar más elementos.");
        }
        int newNodeIndex = free;
        free = nodeList[newNodeIndex].next;

        nodeList[newNodeIndex].data = item;
        nodeList[newNodeIndex].next = head;
        head = newNodeIndex;
    }

    // Inserta un elemento al final de la lista
    void insertAtEnd(const T& item) {
        if (isFull()) {
            throw std::overflow_error("Lista repleta. No se pude insertar más elementos.");
        }
        int newNodeIndex = free;
        free = nodeList[newNodeIndex].next;

        nodeList[newNodeIndex].data = item;
        nodeList[newNodeIndex].next = -1;

        if (isEmpty()) {
            head = newNodeIndex;
        } else {
            int currentNodeIndex = head;
            while (nodeList[currentNodeIndex].next != -1) {
                currentNodeIndex = nodeList[currentNodeIndex].next;
            }
            nodeList[currentNodeIndex].next = newNodeIndex;
        }
    }

    // Imprime la lista
    void printList() const {
        int currentNodeIndex = head;
        while (currentNodeIndex != -1) {
            std::cout << nodeList[currentNodeIndex].data << " ";
            currentNodeIndex = nodeList[currentNodeIndex].next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList<int> list(5); // Lista con capacidad 5, usualmente se usa 30 o 40 

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);

    list.printList();

    return 0;
}
