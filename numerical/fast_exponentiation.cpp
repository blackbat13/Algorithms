//
// Created by Damian Kurpiewski on 22.01.2017.
//
#include <iostream>

using namespace std;

/// Count a^n using binary representation of n
/// \param a - number to rise
/// \param n - power
/// \return a^n
int fast_exp(int a, int n) {
    int w = 1;

    while (n > 0) {
        if (n % 2 == 1) {
            w *= a;
        }

        a *= a;
        n /= 2;
    }

    return w;
}

int main() {
    cout << fast_exp(2, 10);
    return 0;
}