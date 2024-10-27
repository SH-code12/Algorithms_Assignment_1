#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
int sequentialSearchIterative(const vector<T>& arr, T target) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

template <typename T>
int sequentialSearchRecursive(const vector<T>& arr, T target, size_t index = 0) {
    if (index >= arr.size()) {
        return -1;
    }
    if (arr[index] == target) {
        return index;
    }
    return sequentialSearchRecursive(arr, target, index + 1);
}

// Binary Search Iterative
int search(int sorted[], int target, int size) {
    int ri = size - 1;
    int le = 0;
    while (le <= ri) {
        int mid = le + (ri - le) / 2;
        if (sorted[mid] == target) {
            return mid;
        } else if (sorted[mid] < target) {
            le = mid + 1;
        } else {
            ri = mid - 1;
        }
    }
    return -1;
}

// Binary Search Recursive
int bin_se_re(int arr[], int target, int l, int h) {
    if (l > h) {
        return -1;
    }
    int mi = (h + l) / 2;
    if (arr[mi] == target) {
        return mi;
    } else if (arr[mi] > target) {
        return bin_se_re(arr, target, l, mi - 1);
    } else {
        return bin_se_re(arr, target, mi + 1, h);
    }
}

int main() {
    // Sequential Search Test
    cout << "Test Sequential Search\n------------------------------------------------\n";
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 20;

    int result = sequentialSearchIterative(arr, target);
    int result2 = sequentialSearchRecursive(arr, target);

    cout << "Testing sequentialSearchIterative:\n";
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found!" << endl;
    }

    cout << "\nTesting sequentialSearchRecursive:\n";
    if (result2 != -1) {
        cout << "Target found at index: " << result2 << endl;
    } else {
        cout << "Target not found!" << endl;
    }

    // Binary Search Test
    cout << "\nTest Binary Search\n------------------------------------------------\n";
    int arrB[8];
    cout << "Please enter a sorted array of 8 elements:\n";
    for (int i = 0; i < 8; i++) {
        cin >> arrB[i];
    }
    sort(arrB, arrB + 8);

    int targetB;
    cout << "Please enter the target value:\n";
    cin >> targetB;

    int res = search(arrB, targetB, 8);
    int res2 = bin_se_re(arrB, targetB, 0, 7);

    cout << "\nTesting Binary Search Iterative:\n";
    if (res != -1) {
        cout << "Target found at index: " << res << endl;
    } else {
        cout << "Target not found." << endl;
    }

    cout << "\nTesting Binary Search Recursive:\n";
    if (res2 != -1) {
        cout << "Target found at index: " << res2 << endl;
    } else {
        cout << "Target not found." << endl;
    }

    return 0;
}
