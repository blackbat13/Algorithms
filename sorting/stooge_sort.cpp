//
// Created by Damian Kurpiewski on 27.01.2017.
//

#include <iostream>

using namespace std;

/// Sort ascending array of specified length
/// \param array - array to sort
/// \param begin - begin of range to sort
/// \param end - end of range to sort
void stooge_sort(int array[], int begin, int end) {
    if (array[end] < array[begin]) {
        swap(array[begin], array[end]);
    }
    if (end - begin + 1 > 2) {
        int t = (end - begin + 1) / 3;
        stooge_sort(array, begin, end - t);
        stooge_sort(array, begin + t, end);
        stooge_sort(array, begin, end - t);
    }
}

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    stooge_sort(array, 0, 9);

    for (int i = 0; i < 10; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}