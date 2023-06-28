#include <map>
#include <iostream>

int main() {
    std::map<std::string, int> dictionary;

    // Insert key-value pairs
    dictionary["apple"] = 10;
    dictionary["banana"] = 5;
    dictionary["orange"] = 8;

    // Access values by keys
    std::cout << "Number of apples: " << dictionary["apple"] << std::endl;

    // Iterate over the dictionary
    for (const auto& pair : dictionary) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
