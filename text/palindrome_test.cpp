//
// Created by Damian Kurpiewski on 22.01.2017.
//

#include <iostream>

using namespace std;

/// Check if a is palindrome
/// \param a - string to check
/// \return true if a is a palindrome, false otherwise
bool is_palindrome(string a) {
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

    if (is_palindrome(a)) {
        cout << a << " is a palindrome." << endl;
    } else {
        cout << a << " is not a palindrome." << endl;
    }

    return 0;
}