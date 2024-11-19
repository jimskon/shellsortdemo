#include <iostream>
#include <vector>
#include <iomanip> // For formatting output
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand()

// Function to print the array with the current step
void printArray(const std::vector<int>& arr, int step) {
    std::cout << "Step " << step << ": ";
    for (int num : arr) {
        std::cout << std::setw(3) << num << " ";
    }
    std::cout << std::endl;
}

// Shell Sort algorithm with step-by-step visualization
void shellSort(std::vector<int>& arr) {
    int n = arr.size();
    int step = 0; // Counter for steps

    // Start with a large gap and reduce it
    for (int gap = n / 2; gap > 0; gap /= 2) {
        std::cout << "\nCurrent Gap: " << gap << "\n";

        // Perform a gapped insertion sort
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            // Shift elements until the correct position is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;

            // Print the array after each insertion
            printArray(arr, ++step);
        }
    }
}

// Function to generate a random array
std::vector<int> generateRandomArray(int size, int minValue, int maxValue) {
    std::vector<int> arr(size);
    for (int& num : arr) {
        num = minValue + (std::rand() % (maxValue - minValue + 1));
    }
    return arr;
}

// Main function
int main() {
    std::srand(std::time(0)); // Seed the random number generator

    const int arraySize = 10; // Size of the random array
    const int minValue = 1;   // Minimum value for random numbers
    const int maxValue = 100; // Maximum value for random numbers

    // Generate a random array
    std::vector<int> arr = generateRandomArray(arraySize, minValue, maxValue);

    // Print the initial array
    std::cout << "Initial Array: ";
    for (int num : arr) {
        std::cout << std::setw(3) << num << " ";
    }
    std::cout << "\n";

    // Perform Shell Sort
    shellSort(arr);

    // Print the sorted array
    std::cout << "\nSorted Array: ";
    for (int num : arr) {
        std::cout << std::setw(3) << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
