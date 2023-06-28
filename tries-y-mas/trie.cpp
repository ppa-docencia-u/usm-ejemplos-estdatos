#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
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

    void insert(string word) {
        TrieNode* current = root;

        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }

            current = current->children[ch];
        }

        current->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* current = root;

        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }

            current = current->children[ch];
        }

        return current->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* current = root;

        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }

            current = current->children[ch];
        }

        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("banana");
    trie.insert("orange");

    cout << trie.search("apple") << endl;     // Output: 1 (true)
    cout << trie.search("orange") << endl;    // Output: 1 (true)
    cout << trie.search("grape") << endl;     // Output: 0 (false)

    cout << trie.startsWith("app") << endl;   // Output: 1 (true)
    cout << trie.startsWith("ora") << endl;   // Output: 1 (true)
    cout << trie.startsWith("ban") << endl;   // Output: 1 (true)
    cout << trie.startsWith("gr") << endl;    // Output: 0 (false)

    return 0;
}
