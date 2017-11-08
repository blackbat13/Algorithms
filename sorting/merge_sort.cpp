#include <iostream>
using namespace std;

/// Merge two sorted ascending part of array
///   [left, division) and [division, right)
/// Merged array part will be sorted
void merge(int array[], int left, int right, int division) {
    int merged_length = right - left;
    int merged[merged_length];
    int index1 = left;
    int index2 = division;

    for(int i = 0; i < merged_length; i++) {
        if(index1 >= division) {
            merged[i] = array[index2];
            index2++;
        } else if(index2 >= right) {
            merged[i] = array[index1];
            index1++;
        } else if(array[index1] <= array[index2]) {
            merged[i] = array[index1];
            index1++;
        } else {
            merged[i] = array[index2];
            index2++;
        }
    }

    for(int i = left; i < right; i++) {
        array[i] = merged[i-left];
    }
}

/// Sort ascending array in range [left, right)
void merge_sort(int array[], int left, int right) {
    if(right - left <= 1) {
        return;
    }

    int division = (left + right)/2;
    merge_sort(array, left, division);
    merge_sort(array, division, right);

    merge(array, left, right, division);
}

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    merge_sort(array, 0, 10);

    for(int i = 0; i < 10; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}