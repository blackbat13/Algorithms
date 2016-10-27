//
// Created by Damian Kurpiewski on 27.10.2016.
//

#include <iostream>

using namespace std;

/// Count gcd(a,b) using iterative method
int gcd_iterative(int a, int b) {
    while(b != 0) {
        int b2 = b;
        b = a%b;
        a = b2;
    }

    return a;
}

/// COunt gcd(a,b) using recursive method
int gcd_recursive(int a, int b) {
    if(b == 0) {
        return a;
    }

    return gcd_recursive(b, a%b);
}

int main() {
    int a, b;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << "iterative gcd(" << a << "," << b << ") = " << gcd_iterative(a,b) << endl;
    cout << "recursive gcd(" << a << "," << b << ") = " << gcd_recursive(a,b) << endl;
    return 0;
}