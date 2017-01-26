//
// Created by Damian Kurpiewski on 27.01.2017.
//

#include <iostream>

using namespace std;

/// Count gcd(a,b) using iterative method
/// \return gcd(a,b)
int binary_gcd_iterative(int a, int b) {
    int shift;

    if (a == 0) {
        return b;
    }

    if (b == 0) {
        return a;
    }

    for (shift = 0; ((a | b) & 1) == 0; shift++) {
        a >>= 1;
        b >>= 1;
    }

    while ((a & 1) == 0) {
        a >>= 1;
    }

    while (b != 0) {
        while ((b & 1) == 0) {
            b >>= 1;
        }

        if (a > b) {
            swap(a, b);
        }

        b = b - a;
    }

    return a << shift;
}

/// Count gcd(a,b) using recursive method
/// \return gcd(a,b)
int binary_gcd_recursive(int a, int b) {
    if (a == b) {
        return a;
    }

    if (a == 0) {
        return b;
    }

    if (b == 0) {
        return a;
    }

    if (~a & 1) {
        if (b & 1) {
            return binary_gcd_recursive(a >> 1, b);
        } else {
            return binary_gcd_recursive(a >> 1, b >> 1) << 1;
        }
    }

    if (~b & 1) {
        return binary_gcd_recursive(a, b >> 1);
    }

    if (a > b) {
        return binary_gcd_recursive((a - b) >> 1, b);
    }

    return binary_gcd_recursive((b - a) >> 1, a);
}

int main() {
    int a, b;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << "iterative binary gcd(" << a << "," << b << ") = " << binary_gcd_iterative(a, b) << endl;
    cout << "recursive binary gcd(" << a << "," << b << ") = " << binary_gcd_recursive(a, b) << endl;
    return 0;
}