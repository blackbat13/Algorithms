//
// Created by Damian Kurpiewski on 22.01.2017.
//

#include <iostream>

using namespace std;

/// Check if a is palindrom
/// \param a - string to check
/// \return true if a is a palindrom, false otherwise
bool is_palindrom(string a) {
    string b = "";
    for (int i = 0; i < a.length(); i++) {
        b = a[i] + b;
    }

    return a == b;
}

int main() {
    string a;
    cout << "Enter string to check: ";
    cin >> a;

    if (is_palindrom(a)) {
        cout << a << " is a palindrom." << endl;
    } else {
        cout << a << " is not a palindrom." << endl;
    }

    return 0;
}