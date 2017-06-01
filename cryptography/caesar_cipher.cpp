//
// Created by Damian Kurpiewski on 26.01.2017.
//

#include <iostream>

using namespace std;

/// Encode given string using caesar cipher with key k
/// \param a - string to encode
/// \param k - cipher key
/// \return encoding of string a using caesar cipher with key k
string caesar_cipher_encode(string a, int k) {
    for (int i = 0; i < a.length(); i++) {
        if (a[i] >= 'a' && a[i] <= 'z') {
            a[i] += k % ('z' - 'a');
            if (a[i] > 'z') {
                a[i] = 'a' + a[i] - 'z' - 1;
            }
        }
    }

    return a;
}

string caesar_cipher_decode(string a, int k) {
    for (int i = 0; i < a.length(); i++) {
        if (a[i] >= 'a' && a[i] <= 'z') {
            a[i] -= k % ('z' - 'a');
            if (a[i] < 'a') {
                a[i] = 'z' - a[i] + 'a' - 1;
            }
        }
    }

    return a;
}

int main() {
    string a = "computer science";
    cout << caesar_cipher_encode(a, 3) << endl;
    cout << caesar_cipher_decode(caesar_cipher_encode(a, 3), 3) << endl;
    return 0;
}