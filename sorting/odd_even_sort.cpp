//
// Created by Damian Kurpiewski on 26.01.2017.
//

#include <iostream>

using namespace std;

/// Sort ascending array of specified length
/// \param array - array to sort
/// \param length - length of given array
void odd_even_sort(int array[], int length) {
    for (int i = 0; i < length; i++) {
        if (i % 2 == 1) {
            for (int j = 2; j < length; j += 2) {
                if (array[j] < array[j - 1]) {
                    swap(array[j], array[j - 1]);
                }
            }
        } else {
            for (int j = 1; j < length; j += 2) {
                if (array[j] < array[j - 1]) {
                    swap(array[j], array[j - 1]);
                }
            }
        }
    }
}

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    odd_even_sort(array, 10);

    for (int i = 0; i < 10; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}