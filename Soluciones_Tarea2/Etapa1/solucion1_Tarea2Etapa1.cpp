/*
Created on Fri May 26 12:15:27 2023

@author: Pablo Poblete Arrué
@description: Solución para iterativa simple para Tarea 2 Entrega 1
@version: 1.05
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isInGrid(const string& word, const string& chars, const int size = 3) {
    vector<pair<int, int>> used; // Remembers positions already used for the actual word
    int row = -1, col = -1; // row, col position of the last found character
    for (char ch : word) {
        auto ch_pos = chars.find(ch);
        if (ch_pos != string::npos) { // ch_pos <> -1 (character found)
            int row_ch = ch_pos / size; // 0 based row number of the character
            int col_ch = ch_pos % size; // 0 based column number of the character
            if (    
                (row < 0 || col < 0) || // First character of the word
                ( ( 
                    (row_ch == row && abs(col_ch - col) == 1) // Same row, Adjacent column
                    ||
                    (col_ch == col && abs(row_ch - row ) == 1) // Same column, Adjacent row
                  ) &&
                  find(used.begin(), used.end(), make_pair(row_ch, col_ch)) == used.end() // Not used position
                ) 
            ) { 
                row = row_ch; // Remember the position of the row where the char was found (last valid row selected)
                col = col_ch; // Remember the position of the column where the char was found (last valid column selected)
                used.push_back({row, col}); // mark as used position
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