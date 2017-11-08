//
// Created by Damian Kurpiewski on 27.10.2016.
//

#include <iostream>

using namespace std;

/// Count n'th fibonacci number using iterative method
/// \param n - index of fibonacci number to count
/// \return n'th fibonacci number
int fibonacci_iterative(int n) {
    if (n <= 2) {
        return 1;
    }

    int f1 = 1, f2 = 1;
    for (int i = 3; i <= n; i++) {
        int f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }

    return f2;
}

/// Count n'th fibonacci number using recursive method
/// \param n - index of fibonacci number to count
/// \return n'th fibonacci number
int fibonacci_recursive(int n) {
    if (n <= 2) {
        return 1;
    }

    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int n;
    cout << "Enter number to compute: ";
    cin >> n;

    cout << "Iterative: " << fibonacci_iterative(n) << endl;
    cout << "Recursive: " << fibonacci_recursive(n) << endl;

    return 0;
}