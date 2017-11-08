//
// Created by Damian Kurpiewski on 02.11.2016.
//

#include <iostream>

using namespace std;

void quick_sort(int tab[], int left, int right) {
    if (right <= left) {
        return;
    }

    int pivot = tab[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (tab[i] < pivot) {
            i++;
        }

        while (pivot < tab[j]) {
            j--;
        }

        if (i > j) {
            break;
        }

        swap(tab[i], tab[j]);

        i++;
        j--;
    }

    quick_sort(tab, left, j);
    quick_sort(tab, i, right);
}

int main() {
    int tab[] = {7, 2, -2, 7, 7, 293, 1, 5, 94, -5};
    quick_sort(tab, 0, 9);
    for (int i = 0; i < 10; i++) {
        cout << tab[i] << " ";
    }

    cout << endl;
    return 0;
}