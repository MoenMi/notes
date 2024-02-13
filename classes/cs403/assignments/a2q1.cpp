// Write three functions in C or C++: one that declares a large array
// statically, one that declares the same large array on the stack, and one
// that creates the same large array from the heap. Call each of the
// subprograms a large number of times (at least 100,000) and output the
// time required by each. Explain the results.

#include <iostream>
#include <ctime>

const int ARRAY_SIZE = 100000;
const int ITERATIONS = 5000000;

void staticArray() {
    static int arr[ARRAY_SIZE];
}

void stackArray() {
    int arr[ARRAY_SIZE];
}

void heapArray() {
    int *arr = new int[ARRAY_SIZE];
    delete[] arr;
}

int main() {
    clock_t startTime, endTime;
    double duration;

    startTime = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        staticArray();
    }
    endTime = clock();
    duration = (endTime - startTime) / (double) CLOCKS_PER_SEC;
    std::cout << "Static array:\t" << duration << " seconds" << std::endl;

    startTime = clock();
    for (int i = 0; i < 100000; i++) {
        stackArray();
    }
    endTime = clock();
    duration = (endTime - startTime) / (double) CLOCKS_PER_SEC;
    std::cout << "Stack array:\t" << duration << " seconds" << std::endl;

    startTime = clock();
    for (int i = 0; i < 100000; i++) {
        heapArray();
    }
    endTime = clock();
    duration = (endTime - startTime) / (double) CLOCKS_PER_SEC;
    std::cout << "Heap array:\t" << duration << " seconds" << std::endl;

    return 0;
}