//
// Created by Damian Kurpiewski on 27.01.2017.
//

#include <iostream>

using namespace std;

/// Find majority element, if exist
/// \param array - array to search in
/// \param length - length of array
/// \return majority element in given array, if there is a majority
int find_leader(int array[], int length) {
    int current_candidate, counter;
    counter = 0;
    for (int i = 0; i < length; i++) {
        if (counter == 0) {
            current_candidate = array[i];
            counter = 1;
        } else {
            if (array[i] == current_candidate) {
                counter++;
            } else {
                counter--;
            }
        }
    }

    return current_candidate;
}

int main() {
    int array[10] = {1, 2, 5, 5, 7, 5, 5, 10, 5, 5};
    int majority;

    majority = find_leader(array, 10);
    cout << "Majority element is: " << majority << endl;

    return 0;
}