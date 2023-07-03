/**
 * @brief Encuentra las palabras en un grid de letras
 * 
 * @details El presente código representa una posible solución para la entrega 2 de la tarea 2.
 *  Esta solucuón no es la única posible, y no necesariamente es la mejor, sin embargo 
 *  cumple con los requerimientos de la tarea.
 *  
 *  Esta solución utiliza backtracking, pero no un trie.
 * 
 *  Recopilado, adaptado y comentado por Pablo Poblete A., 2023
 *  Para alumnos de:
 *  ASIGNATURA: Ciencias de la Ingenieria I Estructura de Datos
 *  SIGLA: EIN423-B
 * 
 * @param grid grid de letras, como un string
 * @param dictionary diccionario de palabras, como un unordered_set
 * @return vector<string> Un vector con las palabras encontradas
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// dfs solution with backtracking not using trie 
// dfs function that will be used to explore all directions 
// dfs stands for depth first search
void dfs(const string& grid, 
            int row, 
            int col, 
            string& current_word, 
            unordered_set<string>& found_words, 
            int grid_size, 
            vector<bool>& visited, 
            const unordered_set<string>& dictionary) {
    // if already visited or out of bounds, return
    if (row < 0 || row >= grid_size || col < 0 || col >= grid_size || visited[row * grid_size + col]) {
        return;
    }

    // add current letter to current word and mark as visited
    current_word += grid[row * grid_size + col];
    // mark as visited
    visited[row * grid_size + col] = true;

    // if current word is in dictionary, add it to found words
    if (current_word.length() > 2 && dictionary.count(current_word) > 0) {
        found_words.insert(current_word);
    }

    // explore all directions
    static const int dx[] = {1, -1, 0, 0}; // directions: down, up, right, left
    static const int dy[] = {0, 0, 1, -1};

    // for each direction, explore
    for (int i = 0; i < 4; i++) {
        int next_row = row + dx[i];
        int next_col = col + dy[i];
        dfs(grid, next_row, next_col, current_word, found_words, grid_size, visited, dictionary);
    }

    // back to initial state (backtrack)
    visited[row * grid_size + col] = false;
    current_word.pop_back();
}

// find words in grid
vector<string> find_words_in_grid(const string& grid, const unordered_set<string>& dictionary) {
    // grid is a square, so we can get the grid size by getting the square root of the grid length
    int grid_size = static_cast<int>(sqrt(grid.length()));

    // initialize variables
    unordered_set<string> found_words;
    // visited is a vector of booleans, where each position represents a letter in the grid
    vector<bool> visited(grid.length(), false);
    // current word is a string that will be used to build the words found in the grid
    string current_word = "";

    // for each letter in the grid, explore all directions
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            dfs(grid, i, j, current_word, found_words, grid_size, visited, dictionary);
        }
    }

    // return the found words as a vector of strings
    vector<string> result(found_words.begin(), found_words.end());
    return result;
}

int main() {
    string grid = "CATOSKPYU";

    unordered_set<string> dictionary = {
        "CAT", "COPY", "ASK", "SOS"
    };

    vector<string> found_words = find_words_in_grid(grid, dictionary);

    cout << "Palabras encontradas: ";
    for (const string& word : found_words) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
