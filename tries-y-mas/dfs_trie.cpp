#include <iostream>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    vector<TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        children.resize(ALPHABET_SIZE, nullptr);
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    void dfs(TrieNode* node, string currentWord) {
        if (node->isEndOfWord)
            cout << currentWord << endl;

        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (node->children[i] != nullptr) {
                char ch = i + 'a';
                dfs(node->children[i], currentWord + ch);
            }
        }
    }

    void dfsTraversal() {
        dfs(root, "");
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("car");
    trie.insert("cat");
    trie.insert("dog");
    trie.insert("zebra");

    cout << "Words in the Trie (DFS traversal):" << endl;
    trie.dfsTraversal();

    return 0;
}
