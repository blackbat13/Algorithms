//
// Created by Damian Kurpiewski on 27.10.2016.
//

#include <iostream>
using namespace std;

/// Finds minimum value in specified range [from, to) and returns its index
int find_min(int array[], int from, int to) {
    int min_value = array[from], min_index = from;
    for (int i = from + 1; i < to; i++) {
        if (array[i] < min_value) {
            min_value = array[i];
            min_index = i;
        }
    }

    return min_index;
}

/// Sort ascending array of specified length
void selection_sort(int array[], int length) {
    for(int i = 0; i < length; i++) {
        int min_index = find_min(array, i, length);

        swap(array[i], array[min_index]);
    }
}

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    selection_sort(array, 10);

    for(int i = 0; i < 10; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}