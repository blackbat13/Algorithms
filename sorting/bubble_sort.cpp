#include <iostream>
using namespace std;

/// Sort ascending array of specified length
/// \param array - array to sort
/// \param n - length of the given array
void bubble_sort(int array[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j > i; j--) {
            if(array[j] < array[j-1]) {
                swap(array[j], array[j-1]);
            }
        }
    }
}

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    bubble_sort(array, 10);

    for(int i = 0; i < 10; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}