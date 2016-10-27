//
// Created by Damian Kurpiewski on 27.10.2016.
//

#include <iostream>
using namespace std;

/// Sort ascending array of specified length
void insertion_sort(int array[], int length) {
    for(int i = 1; i < length; i++) {
        for(int j = i; j > 0; j--) {
            if(array[j] < array[j-1]) {
                swap(array[j], array[j-1]);
            } else {
                break;
            }
        }
    }
}

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    insertion_sort(array, 10);

    for(int i = 0; i < 10; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}