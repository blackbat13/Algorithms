//
// Created by Damian Kurpiewski on 28.10.2016.
//
#include <iostream>
using namespace std;

int coins[8] = {200, 100, 50, 20, 10, 5, 2, 1};

/// Get minimal number of coins used to give out amount using greedy algorithm
/// \param amount - amount to give out
/// \return minimum number of coins from array coins used to give out amount
int change_greedy(int amount) {
    int result = 0;
    int i = 0;

    while (amount > 0) {
        result += amount / coins[i];
        amount %= coins[i];
        i++;
    }

    return result;
}

/// Get minimal number of coins used to give out amount using dynamic algorithm
/// \param amount - amount to give out
void change_dynamic(int amount) {
    int partial_results[amount + 1];
    int used_coins[amount + 1];
    int i, j, number_of_coins, coin_value;
    int infinity = 1000000; //relative big number
    partial_results[0] = 0;
    for (i = 1; i <= amount; i++) {
        partial_results[i] = infinity;
    }

    cout << "Enter number of coins: ";
    cin >> number_of_coins;

    for (j = 0; j < number_of_coins; j++) {
        cout << "Enter next coin value: ";
        cin >> coin_value;
        for (i = 0; i <= amount - coin_value; i++) {
            if (partial_results[i] + 1 < partial_results[i + coin_value]) {
                partial_results[i + coin_value] = partial_results[i] + 1;
                used_coins[i + coin_value] = coin_value;
            }
        }
    }

    if (partial_results[amount] == infinity) {
        cout << "Cannot give out specified value using given coins." << endl;
        return;
    }

    cout << "Amount " << amount << " can be given out using " << partial_results[amount] << " coins." << endl;
    cout << "Used coins: ";
    i = amount;
    while (i > 0) {
        cout << used_coins[i] << " ";
        i -= used_coins[i];
    }

    cout << endl;
}

int main() {
    int amount;
    cout << "Enter amount: ";
    cin >> amount;

    cout << "Greedy algorithm" << endl;
    cout << "Amount " << amount << " can be given out using " << change_greedy(amount) << " coins." << endl << endl;
    cout << "Dynamic algorithm" << endl;
    change_dynamic(amount);

    return 0;
}