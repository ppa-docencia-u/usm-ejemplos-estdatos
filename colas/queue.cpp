#include <iostream>
#include <stdexcept>

template<typename T>
class Queue {
private:
    T* queueArray;  // Array para almacena los elementos de la cola
    int capacity;   // Capacidad del array
    int front;      // Index del elemento frontal
    int rear;       // Index del elemento trasero
    int count;      // Cantidad de elementos en la cola

public:
    // Constructor
    Queue(int queueCapacity) {
        if (queueCapacity <= 0) {
            throw std::invalid_argument("Capacidad de cola debe ser positiva.");
        }
        capacity = queueCapacity;
        queueArray = new T[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor
    ~Queue() {
        delete[] queueArray;
    }

    // Comprueba si la cola esta vacia
    bool isEmpty() const {
        return count == 0;
    }

    // Comprueba si la cola esta llena
    bool isFull() const {
        return count == capacity;
    }

    // Obtiene el numero de elementos en la cola
    int size() const {
        return count;
    }

    // Agrega un elemento a la cola (rear)
    void enqueue(const T& item) {
        if (isFull()) {
            throw std::overflow_error("Queue repleta. No se puede encolar más elementos.");
        }
        rear = (rear + 1) % capacity;  // Si llega al final del array, wrap around
        queueArray[rear] = item;
        count++;
    }

    // Remueve y retorna el elemento frontal de la cola
    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue vacía. No se puede desencolar elementos.");
        }
        T frontItem = queueArray[front];
        front = (front + 1) % capacity;  // Si llega al final del array, wrap around
        count--;
        return frontItem;
    }

    // Obtiene el elemento frontal de la cola sin removerlo
    T getFront() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue vacía. No se puede obtener elemento frontal.");
        }
        return queueArray[front];
    }
};

int main() {
    Queue<int> queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Elemento frontal: " << queue.getFront() << std::endl;

    while (!queue.isEmpty()) {
        std::cout << "Element desencolados: " << queue.dequeue() << std::endl;
    }

    return 0;
}
