//
// Created by black on 01.06.2017.
//
#include <iostream>
#include <stack>

using namespace std;

/// Calculate value of given Reverse Polish Notation string
/// \param rpn - string containing Reverse Polish Notation, we assume that it's correct
/// \return value of Reverse Polish Notation
double calculate_rpn(string rpn) {
    stack<double> rpn_stack;
    double a, b;

    for (int i = 0; i < rpn.length(); i++) {
        if (isdigit(rpn[i])) {
            rpn_stack.push(rpn[i] - '0');
        } else {
            b = rpn_stack.top();
            rpn_stack.pop();
            a = rpn_stack.top();
            rpn_stack.pop();
            switch (rpn[i]) {
                case '+':
                    rpn_stack.push(a + b);
                    break;
                case '-':
                    rpn_stack.push(a - b);
                    break;
                case '*':
                    rpn_stack.push(a * b);
                    break;
                case '/':
                    rpn_stack.push(a / b);
                    break;
            }
        }
    }

    return rpn_stack.top();
}

int main() {
    string rpn = "27+3/13-4*+2/";

    cout << "Value of rpn string " << rpn << " is: " << calculate_rpn(rpn) << endl;

    return 0;
}