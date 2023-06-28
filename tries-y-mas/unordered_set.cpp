#include <iostream>
#include <unordered_set>

int main() {
    // Create an unordered_set
    std::unordered_set<int> mySet;

    // Insert elements
    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(8);
    mySet.insert(3);

    // Check if an element exists
    if (mySet.count(2) > 0) {
        std::cout << "The element 2 exists in the unordered_set." << std::endl;
    }

    // Iterate over the unordered_set
    for (const auto& element : mySet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
