#include <iostream>
#include "vector"
using namespace std;

template <typename T>
int sequentialSearchIterative(const std::vector<T>& arr, T target) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

template <typename T>
int sequentialSearchRecursive(const std::vector<T>& arr, T target, size_t index = 0) {
    if (index >= arr.size()) {
        return -1;
    }

    if (arr[index] == target) {
        return index;
    }

    return sequentialSearchRecursive(arr, target, index + 1);
}
int main() {

    std::vector<int> arr = {10, 20, 30, 40, 50};
    int target = 20;

    int result = sequentialSearchIterative(arr, target);
    int result2 = sequentialSearchRecursive(arr, target, 0);

    if (result != -1) {
        std::cout << "Target found at index: " << result << std::endl;
        std::cout << "Target found at index: " << result2 << std::endl;
    } else {
        std::cout << "Target not found!" << std::endl;
    }

    return 0;
}
