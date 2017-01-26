//
// Created by Damian Kurpiewski on 26.01.2017.
//

#include <iostream>

using namespace std;

/// Sort ascending array of specified length
/// \param array - array to sort
/// \param length - length of given array
void counting_sort(int array[], int length) {
    int occurences[100];
    int k = 0;
    for (int i = 0; i < 100; i++) {
        occurences[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        occurences[array[i]]++;
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < occurences[i]; j++) {
            array[k] = i;
            k++;
        }
    }
}

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    counting_sort(array, 10);

    for (int i = 0; i < 10; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}