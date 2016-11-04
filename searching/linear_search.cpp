//
// Created by Damian Kurpiewski on 04.11.2016.
//

#include <iostream>

using namespace std;

/// Perform linear search on given array
/// \param array - array to search in
/// \param length - length of array
/// \param number - element to find
/// \return index of element in array, or -1 if not found
int linear_search(int array[], int length, int number) {
    for (int i = 0; i < length; i++) {
        if (array[i] == number) {
            return i;
        }
    }

    return -1;
}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int number;
    int index;
    cout << "Enter number to find: ";
    cin >> number;
    index = linear_search(array, 10, number);
    if (index == -1) {
        cout << "Number not found in array" << endl;
    } else {
        cout << "Index of given number is " << index << endl;
    }

    return 0;
}