//
// Created by Damian Kurpiewski on 07.02.2018.
//

#include <iostream>

using namespace std;

/// Count Hamming distance between two words a and b of equal length
int hamming_distance(string a, string b) {
    int distance = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            distance++;
        }
    }

    return distance;
}

int main() {
    string a = "karolin";
    string b = "kerstin";
    int distance = hamming_distance(a, b);
    cout << "Hamming distance between words " << a << " and " << b << " is " << distance << endl;
    return 0;
}
