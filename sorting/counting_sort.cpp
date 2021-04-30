#include <iostream>

using namespace std;

/// Sort ascending array of specified length
/// \param array - array to sort
/// \param n - length of the given array
void counting_sort(int array[], int n) {
    int occurrences[100];
    int k = 0;
    for (int i = 0; i < 100; i++) {
        occurrences[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        occurrences[array[i]]++;
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < occurrences[i]; j++) {
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