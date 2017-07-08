//
// Created by Damian Kurpiewski on 08.07.2017.
//

#include <iostream>

using namespace std;

void build_heap(int array[], int length) {
    for (int i = 1; i < length; i++) {
        int parent_index = (i - 1) / 2;
        int j = i;
        while (j > 0 && array[j] > array[parent_index]) {
            swap(array[j], array[parent_index]);
            j = parent_index;
            parent_index = (j - 1) / 2;
        }
    }
}

void heap_sort(int array[], int length) {
    for (int i = length - 1; i > 0; i--) {
        build_heap(array, i + 1);
        swap(array[0], array[i]);
    }
}

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    heap_sort(array, 10);

    for (int i = 0; i < 10; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}