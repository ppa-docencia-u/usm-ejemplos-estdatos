#include <iostream>
#include <queue>
using namespace std;

// Estructura del nodo del árbol binario 
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Clase BinaryTree que representa un árbol binario
class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    // Método para insertar un valor en el árbol binario
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Función auxiliar para insertar recursivamente un nodo
    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    // Buscar un valor en el árbol binario
    bool search(int value) {
        return searchRecursive(root, value);
    }

    // Función auxiliar para buscar recursivamente un valor
    bool searchRecursive(Node* current, int value) {
        if (current == nullptr) {
            return false;
        }

        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            return searchRecursive(current->left, value);
        } else {
            return searchRecursive(current->right, value);
        }
    }

    // Realiza recorrido en orden simétrico (Inorder) del árbol binario
    void inorderTraversal() {
        inorderRecursive(root);
        cout << endl;
    }

    // Función auxiliar para realizar recursivamente un recorrido en orden simétrico
    void inorderRecursive(Node* current) {
        if (current != nullptr) {
            inorderRecursive(current->left);
            cout << current->data << " ";
            inorderRecursive(current->right);
        }
    }

    // Realiza recorrido en orden previo (Preorder) del árbol binario
    void preorderTraversal() {
        preorderRecursive(root);
        cout << endl;
    }

    // Función auxiliar para realizar recursivamente un recorrido en orden previo
    void preorderRecursive(Node* current) {
        if (current != nullptr) {
            cout << current->data << " ";
            preorderRecursive(current->left);
            preorderRecursive(current->right);
        }
    }

    // Realiza recorrido en orden posterior (Postorder) del árbol binario
    void postorderTraversal() {
        postorderRecursive(root);
        cout << endl;
    }

    // Función auxiliar para realizar recursivamente un recorrido en orden posterior
    void postorderRecursive(Node* current) {
        if (current != nullptr) {
            postorderRecursive(current->left);
            postorderRecursive(current->right);
            cout << current->data << " ";
        }
    }

    // Realiza recorrido en orden de nivel (Level Order) del árbol binario
    void levelOrderTraversal() {
        if (root == nullptr) {
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            cout << current->data << " ";
            q.pop();

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        cout << endl;
    }
};

int main() {
    BinaryTree binaryTree;
    binaryTree.insert(50);
    binaryTree.insert(30);
    binaryTree.insert(20);
    binaryTree.insert(40);
    binaryTree.insert(70);
    binaryTree.insert(60);
    binaryTree.insert(80);

    cout << "Recorrido en orden simétrico (Inorder Traversal): ";
    binaryTree.inorderTraversal();

    cout << "Recorrido en orden previo (Preorder Traversal): ";
    binaryTree.preorderTraversal();

    cout << "Recorrido en orden posterior (Postorder Traversal): ";
    binaryTree.postorderTraversal();

    cout << "Recorrido en orden de nivel (Level Order Traversal): ";
    binaryTree.levelOrderTraversal();

    int value = 40;
    cout << "Buscando " << value << ": " << (binaryTree.search(value) ? "Encontrado" : "No Encontrado") << endl;

    value = 90;
    cout << "Buscando " << value << ": " << (binaryTree.search(value) ? "Encontrado" : "No Encontrado") << endl;

    return 0;
}
