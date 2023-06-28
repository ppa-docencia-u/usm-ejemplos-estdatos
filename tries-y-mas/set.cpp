#include <set>
#include <iostream>

int main() {
    std::set<int> uniqueNumbers;

    // Insert elements
    uniqueNumbers.insert(5);
    uniqueNumbers.insert(2);
    uniqueNumbers.insert(7);

    // Check if an element exists
    if (uniqueNumbers.find(5) != uniqueNumbers.end()) {
        std::cout << "Number 5 is in the set." << std::endl;
    }

    // Iterate over the set
    for (const auto& element : uniqueNumbers) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
