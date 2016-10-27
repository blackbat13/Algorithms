//
// Created by Damian Kurpiewski on 27.10.2016.
//

#include <iostream>
using namespace std;

/// Sort ascending array of specified length
void selection_sort(int array[], int length) {
    for(int i = 0; i < length; i++) {
        int min_index = i;
        for(int j = i + 1; j < length; j++) {
            if(array[j] < array[min_index]) {
                min_index = j;
            }
        }

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