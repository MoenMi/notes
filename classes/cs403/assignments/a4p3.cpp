#include <iostream>

template <typename T>
int search(T* arr, T target, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    // Test with an integer array
    int arr[] = {1, 2, 3, 4, 5};
    int target = 4;
    int result = search(arr, target, sizeof(int));
    std::cout << "Integer search: " << result << std::endl;
    // Prints "Integer search: 3"
    
    // Test with a float array
    float arr2[] = {6.0, 7.5, 8.3, 9.1, 10.0};
    float target2 = 7.5;
    int result2 = search(arr2, target2, sizeof(float));
    std::cout << "Float search: " << result2 << std::endl;
    // Prints "Float search: 1"

    return 0;
}