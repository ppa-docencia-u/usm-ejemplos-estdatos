#include <iostream>

using namespace std;

// Nodo del árbol AVL
class AVLNode {
public:
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// Árbol AVL
class AVLTree {
private:
    AVLNode* root;

    int getHeight(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalance(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Rota a la derecha el subárbol con raíz en y
    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    // Rota a la izquierda el subárbol con raíz en x
    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    // Inserta un nodo en el árbol AVL
    AVLNode* insertNode(AVLNode* node, int key) {
        if (node == nullptr)
            return new AVLNode(key);

        if (key < node->key)
            node->left = insertNode(node->left, key);
        else if (key > node->key)
            node->right = insertNode(node->right, key);
        else
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rotateRight(node);

        if (balance < -1 && key > node->right->key)
            return rotateLeft(node);

        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    // Recorrido en orden simétrico del árbol AVL
    // (imprime los nodos en orden ascendente)
    void inorderTraversal(AVLNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->key << " ";
            inorderTraversal(node->right);
        }
    }

public:
    AVLTree() {
        root = nullptr;
    }

    void insert(int key) {
        root = insertNode(root, key);
    }

    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    AVLTree avlTree;
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);
    avlTree.insert(60);
    avlTree.insert(70);

    cout << "Recorrido en orden simétrico (Inorder Traversal): ";
    avlTree.inorder();

    return 0;
}
