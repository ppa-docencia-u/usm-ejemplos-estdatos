/**
 * @brief Encuentra las palabras en un grid de letras
 * 
 * @details El presente código representa una posible solución para la entrega 2 de la tarea 2.
 *  Esta solucuón no es la única posible, y no necesariamente es la mejor, sin embargo 
 *  cumple con los requerimientos de la tarea.
 *  La diferencia entre esta solución y solucion2_Tarea2Etapa1.cpp está en la implementación
 *  del algoritmo de búsqueda en profundidad (DFS).
 * 
 *  Esta solución utiliza backtracking, pero no utiliza un trie.
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

// DFS solution with backtracking (no trie)
// DFS stands for Depth-First Search
void dfs(const string& grid, 
            int row, 
            int col, 
            string& current_word, 
            unordered_set<string>& found_words, 
            int grid_size, 
            vector<bool>& visited, 
            const unordered_set<string>& dictionary
) {
    // if already visited or out of bounds, return
    int index = row * grid_size + col;
    if (row < 0 || row >= grid_size || col < 0 || col >= grid_size || visited[index]) {
        return;
    }

    // add current letter to current word and mark as visited
    current_word += grid[index];
    visited[index] = true;

    // if current word is in dictionary, add it to found words
    if (current_word.length() > 2 && dictionary.count(current_word)) {
        found_words.insert(current_word);
    }

    // explore all directions
    dfs(grid, row + 1, col, current_word, found_words, grid_size, visited, dictionary);  // Explore down
    dfs(grid, row - 1, col, current_word, found_words, grid_size, visited, dictionary);  // Explore up
    dfs(grid, row, col + 1, current_word, found_words, grid_size, visited, dictionary);  // Explore right
    dfs(grid, row, col - 1, current_word, found_words, grid_size, visited, dictionary);  // Explore left

    // back to initial state (backtrack)
    visited[index] = false;
    current_word.pop_back();
}

// find words in grid
vector<string> find_words_in_grid(const string& grid, const unordered_set<string>& dictionary) {
    // grid is a square, so we can get the grid size by getting the square root of the grid length
    int grid_size = static_cast<int>(sqrt(grid.length()));
    // initialize variables
    unordered_set<string> found_words;
    vector<bool> visited(grid.size(), false);

    // for each letter in the grid, explore all directions
    for (int row = 0; row < grid_size; ++row) {
        for (int col = 0; col < grid_size; ++col) {
            string current_word = "";
            dfs(grid, row, col, current_word, found_words, grid_size, visited, dictionary);
        }
    }

    // return the found words as vector from unordered_set
    return vector<string>(found_words.begin(), found_words.end());
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
