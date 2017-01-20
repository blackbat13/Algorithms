//
// Created by Damian Kurpiewski on 28.10.2016.
//

#include <iostream>
using namespace std;

/// Given integer n print its prime factors
/// \param n - number to check
void distribute(int n) {
    int i = 2;
    while(n > 1) {
        if(n % i == 0) {
            cout << i << " ";
            n /= i;
        } else {
            i++;
        }
    }
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << "Prime factors of " << n << ": ";
    distribute(n);

    return 0;
}