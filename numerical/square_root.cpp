//
// Created by Damian Kurpiewski on 22.01.2017.
//
#include <iostream>

using namespace std;

/// Count absolute value of n
double abs(double n) {
    return n < 0 ? -n : n;
}

/// Count square root of n with precision p using Heron method
/// \param n - number to count square root of
/// \param p - precision
/// \return square root of n with precision p
double square_root(double n, double p) {
    double x1 = n / 2;
    double x2 = (x1 + n / x1) / 2.0;
    while (abs(x2 - x1) > p) {
        x1 = (x2 + n / x2) / 2.0;
        swap(x1, x2);
    }

    return x2;
}

int main() {
    cout << square_root(9, 0.00001);
    return 0;
}