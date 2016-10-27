//
// Created by Damian Kurpiewski on 27.10.2016.
//

#include <iostream>
#include <cmath>
using namespace std;

/// Check if n is perfect
bool is_perfect(int n) {
    int sum = 0;

    for(int i = 1; i < n; i++) {
        if(n % i == 0) {
            sum += i;
        }
    }

    return sum == n;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    if(is_perfect(n)) {
        cout << n << " is perfect" << endl;
    } else {
        cout << n << " is not perfect" << endl;
    }

    return 0;
}