//
// Created by Damian Kurpiewski on 28.10.2016.
//
#include <iostream>
using namespace std;

int coins[8] = {200, 100, 50, 20, 10, 5, 2, 1};

/// Return minimal numbers of coins used to give out a
int change_greedy(int a) {
    int result = 0;
    int i = 0;

    while(a > 0) {
        result += a / coins[i];
        a %= coins[i];
        i++;
    }

    return result;
}

int main() {
    int a;
    cout << "Enter amount: ";
    cin >> a;

    cout << "Amount " << a << " can be given out using " << change_greedy(a) << " coins." << endl;

    return 0;
}