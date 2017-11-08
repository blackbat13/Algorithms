//
// Created by Damian Kurpiewski on 22.01.2017.
//

#include <iostream>
#include <algorithm>

using namespace std;

/// Check if two strings are anagrams
/// \param a - first string to check
/// \param b - second string to check
/// \return true if a and b are anagrams, false otherwise
bool are_anagrams(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

int main() {
    string a, b;
    cout << "Enter first string to check: ";
    cin >> a;
    cout << "Enter second string to check: ";
    cin >> b;

    if (are_anagrams(a, b)) {
        cout << a << " and " << b << " are anagrams." << endl;
    } else {
        cout << a << " and " << b << " aren't anagrams." << endl;
    }

    return 0;
}