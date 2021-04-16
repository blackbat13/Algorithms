//
// Created by Damian Kurpiewski on 26.01.2017.
//

#include <iostream>

using namespace std;

/// Sort ascending array of specified length
/// \param array - array to sort
/// \param length - length of given array
void cocktail_shaker_sort(int array[], int n) {
    for (int i = 0; i <= n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }

        for (int j = n - 1 - i; j > i; j--) {
            if (array[j] < array[j - 1]) {
                swap(array[j], array[j - 1]);
            }
        }
    }
}

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    cocktail_shaker_sort(array, 10);

    for (int i = 0; i < 10; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}