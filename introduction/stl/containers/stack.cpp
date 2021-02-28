//
// Created by Damian Kurpiewski on 21.11.2017.
//

#include <iostream>
#include <stack>

using namespace std;

int main() {
    cout << "Create stack containing values of type int" << endl;
    // We can create empty stack writing: stack<elements_type> variable_name;
    stack<int> st;

    // To get current size of the stack (number of elements in it) we use "size" method
    cout << "Size of the stack: " << st.size() << endl;

    cout << endl << "Add new elements to top of the stack" << endl;
    // To add new elements to the stack we use "push" method
    // This places new element passed as a parameter at the top of the stack
    st.push(5);
    st.push(-50);
    st.push(25);

    cout << "Size of the stack: " << st.size() << endl;

    // To get value of the top element in the stack we use "top" method
    // This method does not remove element from the stack
    cout << endl << "Top element of the stack: " << st.top() << endl;
    cout << "Removing top element from the stack" << endl;
    // To remove top element of the stack (last added) we use "pop" method
    // This method only removes the top element without returning its value
    st.pop();
    cout << "Top element of the stack: " << st.top() << endl;
    cout << "Size of the stack: " << st.size() << endl;

    cout << endl << "Clearing stack by assigning new value to it" << endl;
    st = stack<int>();

    cout << "Size of the stack: " << st.size() << endl;

    cout << endl << "Checking if stack is empty" << endl;
    // To check if stack is empty (its size is equal to zero) we can use "empty" method
    // This method returns true if stack is empty, false otherwise
    if (st.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}