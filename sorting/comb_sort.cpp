//
// Created by Damian Kurpiewski on 26.01.2017.
//

#include <iostream>

using namespace std;

/// Sort ascending array of specified length
/// \param array - array to sort
/// \param length - length of given array
void comb_sort(int array[], int length) {
    for (int i = length - 1; i > 0; i--) {
        for (int j = 0; j < length - i; j++) {
            if (array[j] > array[j + i]) {
                swap(array[j], array[j + i]);
            }
        }
    }
}

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    comb_sort(array, 10);

    for (int i = 0; i < 10; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}