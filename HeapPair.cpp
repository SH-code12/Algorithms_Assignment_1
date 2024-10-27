#include <bits/stdc++.h>
using namespace std;

// Heap
class Heap {
public:
    vector<pair<int, int>> vec;

    void Heapify(int position) {
        int left = (2 * position) + 1;
        int right = (2 * position) + 2;
        int max = position;

        if (left < vec.size() && vec[left].first > vec[max].first) {
            max = left;
        }
        if (right < vec.size() && vec[right].first > vec[max].first) {
            max = right;
        }
        if (max != position) {
            swap(vec[position], vec[max]);
            Heapify(max);
        }
    }

    void BuildMaxHeap(vector<pair<int, int>>& input_vec) {
        vec = input_vec;
        for (int i = vec.size() / 2 - 1; i >= 0; i--) {
            Heapify(i);
        }
    }

    bool isEmpty() const {
        return vec.empty();
    }

    void Insert(int priority, int value) {
        vec.push_back({priority, value});
        int new_pos = vec.size() - 1;

        while (new_pos > 0) {
            int parent = (new_pos - 1) / 2;
            if (vec[new_pos].first > vec[parent].first) {
                swap(vec[new_pos], vec[parent]);
                new_pos = parent;
            } else {
                break;
            }
        }
    }


    pair<int, int> extractMax() {
        if (isEmpty()) {
            cout << "OOPS, Heap Empty!\n";
            return {-1, -1};
        }
        pair<int, int> maxElement = vec[0];
        vec[0] = vec.back();
        vec.pop_back();
        Heapify(0);
        return maxElement;
    }

    pair<int, int> extractMin() {
        if (isEmpty()) {
            cout << "OOPS, Heap Empty!\n";
            return {-1, -1};
        }
        int minIndex = 0;
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].first < vec[minIndex].first) {
                minIndex = i;
            }
        }
        pair<int, int> minElement = vec[minIndex];
        vec[minIndex] = vec.back();
        vec.pop_back();
        Heapify(minIndex);
        return minElement;
    }


    void PrintHeap() {
        for (const auto& p : vec) {
            cout << "(Priority: " << p.first << ", Value: " << p.second << ") ";
        }
        cout << "\n";
    }
};

// HeapSort
class HeapSort {
public:
    Heap heap;

    void sort(vector<pair<int, int>>& arr) {
        heap.BuildMaxHeap(arr);

        for (int i = arr.size() - 1; i >= 0; i--) {
            arr[i] = heap.extractMax();
        }
    }
};

// PriorityQueue

class PriorityQueue {
public:
    Heap heap;

    void push(int priority, int value) {
        heap.Insert(priority, value);
    }

    pair<int, int> pop() {
        return heap.extractMax();
    }

    void PrintPriorityQueue() {
        heap.PrintHeap();
    }
};




void Menu(){
    cout<<"Welcome to Task 3\n"
          "1.Heap \n"
          "2.Priority Queue\n"
          "3.Heap Sort\n"
          "4.Terminate Program\n";
}

void TestFunction() {
    bool status = true;
    while (status) {
        Menu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        Heap testHeap;
        PriorityQueue testPQ;
        pair<int,int> minElem, maxElem , pqElem;
        HeapSort testHeapSort;
        vector<pair<int, int>> vec;
        int size;

        switch (choice) {
            case 1:
                cout << "Testing Heap:\n";
                cout<<"Enter size of Inserting Numbers:  ";
                cin >> size;
                cout << "Enter (priority, value) pairs:\n";
                for (int i = 0; i < size; ++i) {
                    int priority, value;
                    cin >> priority >> value;
                    testHeap.Insert(priority, value);
                }
                cout << "Heap elements: ";
                testHeap.PrintHeap();
                cout<<"-----------------------------------\n";
                cout << "Extracted max element: ";
                maxElem = testHeap.extractMax();
                cout << "(Priority: " << maxElem.first << ", Value: " << maxElem.second << ")\n";
                cout << "Heap after extracting max: ";
                testHeap.PrintHeap();
                cout<<"-----------------------------------\n";
                cout << "Extracted min element: ";
                minElem = testHeap.extractMin();
                cout << "(Priority: " << minElem.first << ", Value: " << minElem.second << ")\n";
                cout << "Heap after extracting min: ";
                testHeap.PrintHeap();
                cout<<"-----------------------------------\n";

                break;

            case 2:
                cout << "Testing Priority Queue:\n";
                cout<<"Enter size of Inserting Numbers:  ";
                cin >> size;
                cout << "Enter (priority, value) pairs:\n";
                for (int i = 0; i < size; ++i) {
                    int priority, value;
                    cin >> priority >> value;
                    testPQ.push(priority, value);
                }
                cout << "Priority Queue elements: ";
                testPQ.PrintPriorityQueue();
                cout<<"-----------------------------------\n";
                cout << "Extracted highest priority element: ";
                pqElem = testPQ.pop();
                cout << "(Priority: " << pqElem.first << ", Value: " << pqElem.second << ")\n";
                cout << "Priority Queue after extraction: ";
                testPQ.PrintPriorityQueue();
                cout<<"-----------------------------------\n";
                break;

            case 3:
                cout << "Testing Heap Sort:\n";
                cout<<"Enter size of Inserting Numbers:  ";
                cin >> size;
                cout << "Enter (priority, value) pairs:\n";
                for (int i = 0; i < size; ++i) {
                    int priority, value;
                    cin >> priority >> value;
                    vec.push_back({priority, value});
                }
                cout << "Array before sorting: ";
                for (const auto& elem : vec) {
                    cout << "(Priority: " << elem.first << ", Value: " << elem.second << ") ";
                }
                cout << "\n";
                testHeapSort.sort(vec);
                cout<<"-----------------------------------\n";
                cout << "Array after sorting: ";
                for (const auto& elem : vec) {
                    cout << "(Priority: " << elem.first << ", Value: " << elem.second << ") ";
                }
                cout << "\n";
                cout<<"-----------------------------------\n";

                break;

            case 4:
                cout << "Thank you! Exiting the program.\n";
                status = false;
                break;

            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
}

int main() {
    TestFunction();
    return 0;
}
