#include <iostream>
#include <unordered_map>

int main() {
    // Create an unordered_map
    std::unordered_map<std::string, int> myMap;

    // Insert key-value pairs
    myMap["apple"] = 10;
    myMap["banana"] = 5;
    myMap["orange"] = 8;

    // Access values by keys
    std::cout << "Number of apples: " << myMap["apple"] << std::endl;

    // Check if a key exists
    if (myMap.count("banana") > 0) {
        std::cout << "The key 'banana' exists in the unordered_map." << std::endl;
    }

    // Iterate over the unordered_map
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
