//
// Created by Shahd Elnassag on 10/20/2024.
//
#include <bits/stdc++.h>

using namespace std;
// Fibonacci series using recursion
template<typename T>
T Fibonacci(T num){
    if (num== 0 || num == 1){
        return num;
    }
    return Fibonacci(num-1) + Fibonacci(num-2);
}

// Fibonacci series using divide and conquer
int bin_se_re( int arr[8], int target, int l, int h) {
    if (l > h) {
        return -1;
    }
    int mi = (h + l) / 2;
    if (arr[mi] == target) {
        return mi;
    }
    else if (arr[mi] > target) {
        return bin_se_re(arr, target, l, mi - 1);
    }
    else {
        return bin_se_re(arr, target, mi + 1, h);
    }

}

// Fibonacci series using dynamic programming

void Menu(){
    cout<<"Welcome to Fibonacci Series\n"
          "1.Fibonacci series using recursion\n"
          "2.Fibonacci series using divide and conquer\n"
          "3.Fibonacci series using dynamic programming\n"
          "4.Terminate Program\n";
}

int ChoiceFunction() {
    bool status = true;
    // used in testing Fibonacci series using divide and conquer
    int arr [8];
    int res;
    while (status) {
        int choice;
        Menu();
        cout << "Enter Your Choice From above Menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                while (true) {
                    cout << "1. Continue\n2. Return\nPlease Enter choice: ";
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            cout << "You are now testing Fibonacci function using recursion.\n";
                            int n;
                            cout << "Please enter a number: ";
                            cin >> n;
                            cout << "Fibonacci of number " << n << " = " << Fibonacci(n) << "\n";
                            cout<<"-------------------------------------------\n";
                            break;
                        case 2:
                            break;
                        default:
                            cout << "Invalid Choice, Press Enter to choose Valid Choice again ^_^:" << endl;
                    }
                    if (choice == 2) break;
                }
                break;

            case 2:
                while (true) {
                    cout << "1. Continue\n2. Return\nPlease Enter choice: ";
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            cout << "You are now testing Fibonacci function using divide and conquer.\n";
                            cout <<"please enter sorted array of 8 elements"<< endl;
                            for (int i=0; i<8;i++){
                                cin >> arr[i];
                            }
                            int target;
                            cout <<"please enter the target value"<< endl;
                            cin >> target;

                            res = bin_se_re(arr, target, 0, 7);

                            if (res != -1) {
                                cout << "Target found at index: " << res << endl;
                            } else {
                                cout << "Target not found" << endl;
                            }
                            break;
                        case 2:
                            break;
                        default:
                            cout << "Invalid Choice, Press Enter to choose Valid Choice again ^_^:" << endl;
                    }
                    if (choice == 2) break;
                }
                break;

            case 3:
                while (true) {
                    cout << "1. Continue\n2. Return\nPlease Enter choice: ";
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            cout << "Not added yet, See You Later ^_^\n";
                            break;
                        case 2:
                            break;
                        default:
                            cout << "Invalid Choice, Press Enter to choose Valid Choice again ^_^:" << endl;
                    }
                    if (choice == 2) break;
                }
                break;

            case 4:
                cout << "Thank You, See You Later ^_^\n";
                return 0;

            default:
                cout << "Invalid Choice, Press Enter to choose Valid Choice again ^_^:" << endl;

        }
    }
}

int main(){
    ChoiceFunction();
}

