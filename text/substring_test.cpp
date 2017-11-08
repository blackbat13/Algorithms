//
// Created by Damian Kurpiewski on 26.01.2017.
//

#include <iostream>
#include <algorithm>

using namespace std;

/// Check if one string is substring of the other
/// \param a - string to search for
/// \param b - string to search in
/// \return true if a is substring of b
bool is_substring(string a, string b) {
    int i, j;

    for (i = 0; i < b.length() - a.length(); i++) {
        j = 0;
        while (j < a.length()) {
            if (a[j] == b[i + j]) {
                j++;
            } else {
                break;
            }
        }

        if (j == a.length()) {
            return true;
        }
    }

    return false;
}

int main() {
    string a, b;
    cout << "Enter string to search for: ";
    cin >> a;
    cout << "Enter string to search in: ";
    cin >> b;

    if (is_substring(a, b)) {
        cout << a << " is substring of " << b << endl;
    } else {
        cout << a << " is not substring of " << b << endl;
    }

    return 0;
}