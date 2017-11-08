//
// Created by Damian Kurpiewski on 21.01.2017.
//

#include <iostream>

using namespace std;

/// Find minimum and maximum value in given array using naive algorithm
/// \param array - array to search in
/// \param length - length of given array
void find_min_max_naive(int array[], int length) {
    int min, max, i;
    min = array[0];
    max = array[0];
    for (i = 1; i < length; i++) {
        if (array[i] < min) {
            min = array[i];
        } else if (array[i] > max) {
            max = array[i];
        }
    }

    cout << "Minimum value: " << min << endl;
    cout << "Maximal value: " << max << endl;
}

/// Find minimum and maximum value in given array using optimal divide and conquer algorithm
/// \param array - array to search in
/// \param length - length of given array
void find_min_max_optimal(int array[], int length) {
    int min, max, i;
    int min_candidates[(length + 1) / 2], max_candidates[(length + 1) / 2];
    for (i = 1; i < length; i += 2) {
        if (array[i - 1] < array[i]) {
            min_candidates[i / 2] = array[i - 1];
            max_candidates[i / 2] = array[i];
        } else {
            min_candidates[i / 2] = array[i];
            max_candidates[i / 2] = array[i - 1];
        }
    }

    if (length % 2 != 0) {
        min_candidates[(length + 1) / 2 - 1] = array[length - 1];
        max_candidates[(length + 1) / 2 - 1] = array[length - 1];
    }

    min = min_candidates[0];
    max = max_candidates[0];
    for (i = 1; i < (length + 1) / 2; i++) {
        if (min_candidates[i] < min) {
            min = min_candidates[i];
        }

        if (max_candidates[i] > max) {
            max = max_candidates[i];
        }
    }

    cout << "Minimum value: " << min << endl;
    cout << "Maximal value: " << max << endl;
}

int main() {
    int array[11] = {3, 6, 1, 9, 10, 4, -4, 6, 12, 5, 11};

    cout << "Naive algorithm" << endl;
    find_min_max_naive(array, 11);
    cout << "Optimal algorithm" << endl;
    find_min_max_optimal(array, 11);
    return 0;
}