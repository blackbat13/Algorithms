//
// Created by Damian Kurpiewski on 21.11.2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// Prints content of the vector
/// \param array - vector to prints content of
void printVector(vector<int> array) {
    for (int el : array) {
        cout << el << " ";
    }

    cout << endl;
}

/// Compute absolute value of given integer
/// \param a - integer to compute asolute value of
/// \return Absolute value of a
int abs(int a) {
    if (a < 0) {
        return -a;
    } else {
        return a;
    }
}

/// Compare two elements using their absolute values
/// \param a - first value
/// \param b - second value
/// \result true if absolute value of a is lower than absolute value of b, false otherwise
bool compare(int a, int b) {
    return abs(a) < abs(b);
}

int main() {
    // First we create array we will be sorting
    vector<int> array;
    array.push_back(5);
    array.push_back(-2);
    array.push_back(-6);
    array.push_back(12);
    array.push_back(0);

    cout << "Sorting array in ascending order" << endl;
    // To sort array we call sort function
    sort(array.begin(), array.end());
    printVector(array);

    cout << "Sorting array in descending order" << endl;
    sort(array.rbegin(), array.rend());
    printVector(array);

    cout << "Sorting array using custom comparing function" << endl;
    // We can add custom function to compare elements while sorting them
    // This function should accept two parameters of type of the elements in the array
    // Function should return true if first element should be placed before second one and false otherwise
    sort(array.begin(), array.end(), compare);
    printVector(array);

    return 0;
}