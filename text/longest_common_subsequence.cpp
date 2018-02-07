//
// Created by Damian Kurpiewski on 07.02.2018.
//
#include <iostream>

using namespace std;

string longest_common_subsequence(string a, string b) {
    int matrix[a.length() + 1][b.length() + 1];
    for (int i = 0; i <= a.length(); i++) {
        matrix[i][0] = 0;
    }

    for (int i = 0; i <= b.length(); i++) {
        matrix[0][i] = 0;
    }

    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }

    int value = matrix[a.length()][b.length()];
    int i = a.length(), j = b.length();
    string result = "";
    while (value > 0) {
        if (matrix[i - 1][j] == value) {
            i--;
        } else if (matrix[i][j - 1] == value) {
            j--;
        } else {
            result = a[i - 1] + result;
            i--;
            j--;
            value--;
        }
    }

    return result;
}

int main() {
    string a = "kitten";
    string b = "sitting";
    string lcs = longest_common_subsequence(a, b);
    cout << "Longest common subsequence of words " << a << " and " << b << " is " << lcs << endl;
    return 0;
}