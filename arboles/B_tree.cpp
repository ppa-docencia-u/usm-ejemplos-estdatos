#include <iostream>
using namespace std;

// Nodo del árbol B
class BTreeNode {
    int *keys;
    int t; // Grado mínimo (define el rango para el número de claves)
    BTreeNode **childPointers;
    int numKeys;
    bool isLeaf;

public:
    BTreeNode(int t, bool isLeaf);
    void insertNonFull(int k);
    void splitChild(int i, BTreeNode *y);
    void traverse();

    // Para proporcionar acceso a la clase principal que representa la estructura de datos
    friend class BTree; // Declara a BTree como una clase amiga para que pueda acceder a los miembros privados de BTreeNode
};

// B-tree
class BTree {
    BTreeNode *root;
    int t; // Grado mínimo (define el rango para el número de claves)

public:
    BTree(int t);
    void insert(int k);
    void traverse();
};

// Constructor para inicializar un nodo B-tree
BTreeNode::BTreeNode(int t, bool isLeaf) {
    this->t = t;
    this->isLeaf = isLeaf;

    keys = new int[2 * t - 1];
    childPointers = new BTreeNode *[2 * t];
    numKeys = 0;
}

// Recorre el árbol B
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < numKeys; i++) {
        if (!isLeaf)
            childPointers[i]->traverse();
        cout << " " << keys[i];
    }

    if (!isLeaf)
        childPointers[i]->traverse();
}

// Constructor para inicializar un árbol B
BTree::BTree(int t) {
    this->t = t;
    root = nullptr;
}

// Inserta una nueva clave en el árbol B
void BTree::insert(int k) {
    if (root == nullptr) {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->numKeys = 1;
    } else {
        if (root->numKeys == (2 * t - 1)) {
            BTreeNode *s = new BTreeNode(t, false);
            s->childPointers[0] = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->childPointers[i]->insertNonFull(k);
            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}

// Inserta una nueva clave en el árbol B no lleno
void BTreeNode::insertNonFull(int k) {
    int i = numKeys - 1;

    if (isLeaf) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
        numKeys++;
    } else {
        while (i >= 0 && keys[i] > k)
            i--;

        if (childPointers[i + 1]->numKeys == (2 * t - 1)) {
            splitChild(i + 1, childPointers[i + 1]);

            if (keys[i + 1] < k)
                i++;
        }
        childPointers[i + 1]->insertNonFull(k);
    }
}

// Dividir el hijo de un nodo de árbol B
void BTreeNode::splitChild(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->t, y->isLeaf);
    z->numKeys = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (!y->isLeaf) {
        for (int j = 0; j < t; j++)
            z->childPointers[j] = y->childPointers[j + t];
    }

    y->numKeys = t - 1;

    for (int j = numKeys; j >= i + 1; j--)
        childPointers[j + 1] = childPointers[j];

    childPointers[i + 1] = z;

    for (int j = numKeys - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];
    numKeys++;
}

// Recorre el árbol B
void BTree::traverse() {
    if (root != nullptr)
        root->traverse();
}


int main() {
    BTree tree(3); // Árbol B con grado mínimo 3

    int keys[] = {10, 20, 5, 6, 12, 30, 7, 17};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
        tree.insert(keys[i]);

    cout << "Recorrido del árbol B: ";
    tree.traverse();
    cout << endl;

    return 0;
}
