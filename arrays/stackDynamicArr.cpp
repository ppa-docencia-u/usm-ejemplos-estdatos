#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Stack {
private:
    T* stackArray;   // Dynamic array para almacenar los elementos del stack 
    int capacity;    // Capacidad del stack
    int top;         // Index al elemento al tope del stack

public:
    // Constructor
    Stack(int stackCapacity) {
        if (stackCapacity <= 0) {
            throw std::invalid_argument("La capacidad del stack debe ser positiva.");
        }
        capacity = stackCapacity;
        stackArray = new T[capacity];
        top = -1;  // Stack esta vacio inicialmente
    }

    // Destructor
    ~Stack() {
        delete[] stackArray;
    }

    // Comprueba si el stack esta vacio
    bool isEmpty() const {
        return top == -1;
    }

    // Comprueba si el stack esta lleno
    bool isFull() const {
        return top == capacity - 1;
    }

    // Push un elemento en el stack
    void push(const T& item) {
        if (isFull()) {
            throw overflow_error("Stack repleto. No puede agregar más elementos.");
        }
        stackArray[++top] = item;
    }

    // Pop elemento del tope del stack
    void pop() {
        if (isEmpty()) {
            throw underflow_error("Stack vacío. No hay elementos.");
        }
        --top;
    }

    // Vistazo al elemento al tope del stack
    T& peek() const {
        if (isEmpty()) {
            throw underflow_error("Stack vacio. No hay elementos.");
        }
        return stackArray[top];
    }
};

int main() {
    Stack<int> stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Elemento al tope del stack: " << stack.peek() << endl;

    stack.pop();
    stack.pop();

    cout << "Elemento al tope del stack: " << stack.peek() << endl;

    return 0;
}
