//
// Created by Damian Kurpiewski on 21.11.2017.
//

#include <iostream>
#include <deque>
using namespace std;

int main() {
    // Creating empty deque containing integers
    deque<int> array;
    // Creating deque containing 10 elements of type integer with default value for that type - 0
    deque<int> array2(10);

    cout << "Element 0 of array2 is: " << array2[0] << endl;

    // Creating deque containing 10 elements of type integer with value 23
    deque<int> array3(10, 23);

    cout << "Element 0 of array3 is: " << array3[0] << endl;

    // We can also achieve similar behaviour by setting value for existing variable
    array = deque<int>(10, 23);
    cout << "Element 0 of array is: " << array[0] << endl;

    // Checking size of the array
    cout << "Size of the array is: " << array.size() << endl;

    // Adding new element to the end of the array
    array.push_back(55);
    cout << "Last element of array is: " << array[array.size() - 1] << endl;
    cout << "Size of the array is: " << array.size() << endl;

    // Adding new element at the beggining of the array
    array.push_front(48);
    cout << "First element of the array is: " << array[0] << endl;
    cout << "Size of the array is: " << array.size() << endl;

    // Adding new element at the position 5 in the array
    array.insert(array.begin() + 5, 60);
    cout << "Element 5 of array is: " << array[5] << endl;
    cout << "Size of the array is: " << array.size() << endl;

    // Deleting last element in the array
    array.pop_back();
    cout << "Size of the array is: " << array.size() << endl;

    // Deleting first element in the array
    array.pop_front();
    cout << "Size of the array is: " << array.size() << endl;

    // Deleting element at the position 5
    array.erase(array.begin() + 5);
    cout << "Element 5 of array is: " << array[5] << endl;
    cout << "Size of the array is: " << array.size() << endl;

    // Deleting elements in the array from index 5 to 7, not including 7
    array.erase(array.begin() + 5, array.begin() + 7);
    cout << "Size of the array is: " << array.size() << endl;

    // Resizing array to size 20, filling new elements with default value
    array.resize(20);
    cout << "Element 19 of the array is: " << array[19] << endl;
    cout << "Size of the array is: " << array.size() << endl;

    // Resizing array to size 30, filling new elements with the value 41
    array.resize(30, 41);
    cout << "Element 29 of the array is: " << array[29] << endl;
    cout << "Size of the array is: " << array.size() << endl;

    // Checking if the array is empty
    if(array.empty()) {
        cout << "Array is empty" << endl;
    } else {
        cout << "Array is not empty" << endl;
    }

    // Clearing array removing all of its content
    array.clear();
    cout << "Size of the array is: " << array.size() << endl;

    return 0;
}