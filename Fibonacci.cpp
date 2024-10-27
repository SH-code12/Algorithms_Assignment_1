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
int f[2][2] = {{1, 1}, {1, 0}};
int M[2][2] = {{1, 1}, {1, 0}};
void multiplacation (int f[2][2],int  M[2][2]){
    int a = f[0][0]*M[0][0]+ f[0][1]*M[1][0];
    int b= f[0][0]*M[0][1] + f[0][1]*M[1][1];
    int c= f[1][0]*M[0][0]+ f[1][1]*M[1][0];
    int d= f[1][0]*M[0][1]+ f[1][1]*M[1][1];
    f[0][0]= a;
    f[0][1]= b;
    f[1][0]=c;
    f[1][1]=d;
}
void power(int f[2][2], int n ){
    if (n==0 || n==1){ return ;}
    power(f, n/2);
    multiplacation(f, f);
    if (n%2!=0){
        multiplacation( f, M);
    }
}
int fibo (int n){
    if (n==0)
        return 0;
    else{
        power(f, n-1);
        return f[0][0];
    }
}

// Fibonacci series using dynamic programming

template <typename T>
T fibonacciDynamic(T n) {
    vector<T> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;

    for (T i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

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
                            cout << "Please enter Positive number: ";
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
                            int n;
                            cout << "Please enter Positive number: ";
                            cin >> n;
                            cout << "Fibonacci of number " << n << " = " << fibo(n) << "\n";
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

            case 3:
                while (true) {
                    cout << "1. Continue\n2. Return\nPlease Enter choice: ";
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            cout << "You are now testing Fibonacci function using dynamic programming.\n";
                            int n;
                            cout << "Please enter Positive number: ";
                            cin >> n;
                            cout << "Fibonacci of number " << n << " = " << fibonacciDynamic(n) << "\n";
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

