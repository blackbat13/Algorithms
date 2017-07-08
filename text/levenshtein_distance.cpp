//
// Created by Damian Kurpiewski on 08.07.2017.
//

#include <iostream>

using namespace std;

/// Count Levenshtein distance (edit distance) between two words a and b
int levenshtein_distance(string a, string b) {
    int matrix[a.length() + 1][b.length() + 1];
    for (int i = 0; i < a.length(); i++) {
        matrix[i][0] = i;
    }

    for (int i = 0; i < b.length(); i++) {
        matrix[0][i] = i;
    }

    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            int cost;
            if (a[i - 1] == b[j - 1]) {
                cost = 0;
            } else {
                cost = 1;
            }

            matrix[i][j] = min(matrix[i - 1][j - 1] + cost, min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1));
        }
    }

    return matrix[a.length()][b.length()];
}

int main() {
    string a = "kitten";
    string b = "sitting";
    int distance = levenshtein_distance(a, b);
    cout << "Levenshtein distance between words " << a << " and " << b << " is " << distance << endl;
    return 0;
}