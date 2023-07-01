/*
Created on Fri May 26 12:15:27 2023

@author: Pablo Poblete Arrué
@description: Solución para iterativa simple para Tarea 2 Entrega 1
@version: 1.06
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool isInGrid(const string& word, const string& chars, const int size = 3) {
    unordered_set<int> used; // Remembers positions already used for the actual word
    int row = -1, col = -1; // row, col position of the last found character
    for (char ch : word) {
        auto ch_pos = chars.find(ch);
        if (ch_pos != string::npos) {
            int index = static_cast<int>(ch_pos);
            int row_ch = index / size;
            int col_ch = index % size;
            if ((row < 0 || col < 0) || ((row_ch == row && abs(col_ch - col) == 1) || (col_ch == col && abs(row_ch - row) == 1))) {
                if (used.count(index) == 0) { // Not used position
                    row = row_ch;
                    col = col_ch;
                    used.insert(index); // mark as used position
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    vector<string> words = {"CAT", "COPY", "ASK", "SOS", "ASU", "COS", "COSYU", "CASKU", "TASK", "COSAT", "CASO", "TACOS", "COPYSA", "TASO", "LASY"};
    string chars = "CATOSKPYU";
    const int size = 3; // 3x3 grid

    for (const string& word : words) {
        if (isInGrid(word, chars, size)) {
            cout << word << " encontrada" << endl;
        }
    }

    return 0;
}