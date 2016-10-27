//
// Created by Damian Kurpiewski on 27.10.2016.
//

//
// Created by Damian Kurpiewski on 27.10.2016.
//
#include <iostream>
#include <cmath>
using namespace std;

/// Check if n is prime
bool is_prime(int n) {
    if(n<2){
        return false;
    }

    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    if(is_prime(n)) {
        cout << n << " is prime" << endl;
    } else {
        cout << n << " is not prime" << endl;
    }

    return 0;
}