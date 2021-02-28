//
// Created by Damian Kurpiewski on 21.11.2017.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    cout << "Create queue containing values of type int" << endl;
    // We can create empty queue writing: queue<elements_type> variable_name;
    queue<int> qu;

    // To get current size of the queue (number of elements in it) we use "size" method
    cout << "Size of the queue: " << qu.size() << endl;

    cout << endl << "Add new elements to the end of the queue" << endl;
    // To add new elements to the queue we use "push" method
    // This places new element passed as a parameter at the end of the queue
    qu.push(5);
    qu.push(-50);
    qu.push(25);
    qu.push(120);

    cout << "Size of the queue: " << qu.size() << endl;

    // To get value of the first element in the queue we use "front" method
    // This method does not remove element from the queue
    cout << endl << "First element of the queue: " << qu.front() << endl;
    cout << "Removing top element from the queue" << endl;
    // To remove top element of the queue (from the first position) we use "pop" method
    // This method only removes the first element without returning its value
    qu.pop();
    cout << "First element of the queue: " << qu.front() << endl;
    cout << "Size of the queue: " << qu.size() << endl;

    // To get value of the last element in the queue we use "back" method
    // This method does not remove element from the queue
    cout << endl << "Last element of the queue: " << qu.back() << endl;

    cout << endl << "Clearing queue by assigning new value to it" << endl;
    qu = queue<int>();

    cout << "Size of the queue: " << qu.size() << endl;

    cout << endl << "Checking if queue is empty" << endl;
    // To check if queue is empty (its size is equal to zero) we can use "empty" method
    // This method returns true if queue is empty, false otherwise
    if (qu.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}