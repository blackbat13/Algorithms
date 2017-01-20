//
// Created by Damian Kurpiewski on 28.10.2016.
//
#include <iostream>
using namespace std;

int coins[8] = {200, 100, 50, 20, 10, 5, 2, 1};

/// Get minimal numbers of coins used to give out amount using greedy algorithm
/// \param amount - amount to give out
/// \return minimum number of coins from array coins used to give out amount
int change_greedy(int amount) {
    int result = 0;
    int i = 0;

    while(a > 0) {
        result += amount / coins[i];
        amount %= coins[i];
        i++;
    }

    return result;
}

int main() {
    int amount;
    cout << "Enter amount: ";
    cin >> amount;

    cout << "Amount " << amount << " can be given out using " << change_greedy(amount) << " coins." << endl;

    return 0;
}