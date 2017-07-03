//
// Created by Damian Kurpiewski on 27.10.2016.
//

#include <iostream>

using namespace std;

/// Count gcd(a,b) using iterative method
/// \return gcd(a,b)
int gcd_iterative(int a, int b) {
    while(b != 0) {
        int b2 = b;
        b = a%b;
        a = b2;
    }

    return a;
}

/// Count gcd(a,b) using recursive method
/// \return gcd(a,b)
int gcd_recursive(int a, int b) {
    if(b == 0) {
        return a;
    }

    return gcd_recursive(b, a%b);
}

int subtraction_gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }

    if (a == 0) {
        return b;
    } else {
        return a;
    }
}

int main() {
    int a, b;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << "iterative gcd(" << a << "," << b << ") = " << gcd_iterative(a,b) << endl;
    cout << "recursive gcd(" << a << "," << b << ") = " << gcd_recursive(a,b) << endl;
    cout << "subtraction gcd(" << a << "," << b << ") = " << subtraction_gcd(a, b) << endl;
    return 0;
}