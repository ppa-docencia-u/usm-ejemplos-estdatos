#include <iostream>
#include <stack>
using namespace std;

/*
Las funciones asociadas a stack son: 
empty() – Retona stack vacío o no – Time Complexity : O(1) 
size() – Retorna tamaño del stack – Time Complexity : O(1) 
top() – Retorna referencia al elemento al tope del stack – Time Complexity : O(1) 
push(g) – Agrega el elemento ‘g’ al tope del stack       – Time Complexity : O(1) 
pop() – Borra el elemento más reciente agregado al stack – Time Complexity : O(1) 
*/


int main() {
    // stack de enteros
    stack<int> stack;
    
    stack.push(21);
    stack.push(22);
    stack.push(24);
    stack.push(25);
    int num=0;
      stack.push(num);
    stack.pop();
    stack.pop();
      stack.pop();
   
    while (!stack.empty()) {
        cout << stack.top() <<" ";
        stack.pop();
    }
    cout << endl;
}