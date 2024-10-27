#include <iostream>
#include "vector"
using namespace std;
#include <vector>

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





int main() {


    return 0;
}
