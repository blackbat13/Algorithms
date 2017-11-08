//
// Created by Damian Kurpiewski on 04.11.2016.
//

#include <iostream>

using namespace std;

/// Perform iterative binary search on given array
/// \param array - array to search in, sorted ascending
/// \param length - length of array
/// \param number - element to find
/// \return index of element in array, or -1 if not found
int binary_search_iterative(int array[], int length, int number) {
    int left = 0;
    int right = length - 1;
    int middle;

    while (left < right) {
        middle = (left + right) / 2;
        if (number <= array[middle]) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }

    if (array[left] == number) {
        return left;
    }

    return -1;
}

/// Perform recursive binary search on given array
/// \param array - array to search in, sorted ascending
/// \param number - element to find
/// \param left
/// \param right
/// \return index of element in array, or -1 if not found
int binary_search_recursive(int array[], int number, int left, int right) {
    int middle;

    if (left < right) {
        middle = (left + right) / 2;
        if (number <= array[middle]) {
            return binary_search_recursive(array, number, left, middle);
        } else {
            return binary_search_recursive(array, number, middle + 1, right);
        }
    } else if (array[left] == number) {
        return left;
    }

    return -1;
}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int number;
    int index1, index2;
    cout << "Enter number to find: ";
    cin >> number;
    index1 = binary_search_iterative(array, 10, number);
    index2 = binary_search_recursive(array, number, 0, 10);
    if (index1 != index2) {
        cout << "Method mismatch" << endl;
    } else if (index1 == -1) {
        cout << "Number not found in array" << endl;
    } else {
        cout << "Index of given number is " << index1 << endl;
    }

    return 0;
}