#include <iostream>
#include <vector>
#include <chrono>

int main() {
    // Start tracking time
    auto start = std::chrono::high_resolution_clock::now();
    
    std::vector<int*> allocatedPointers;
    for (int i = 0; i < 100000; ++i) {
        // Dynamically allocating memory
        int* num = new int[100];  // Allocating memory for an array of 100 integers
        for (int j = 0; j < 100; ++j) {
            num[j] = j;  // Initializing the array
        }
        allocatedPointers.push_back(num);  // Storing the pointer
    }

    // Forget to deallocate memory to simulate a memory leak
    // Not calling delete[] for the allocated memory

    allocatedPointers.clear();  // Clear vector, but still no delete[]

    // End tracking time
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Memory-intensive task completed in " << duration.count() << " seconds." << std::endl;

    return 0;
}
