//
// Created by Damian Kurpiewski on 08.11.2017.
//

#include <iostream>
using namespace std;

int main() {

    cout << "Simple for loop, executing 10 times" << endl;
    for(int i = 0; i < 10; i++) {
        cout << "Hello World!" << endl;
    }

    cout << endl;
    cout << "We go from 0 to 10 non inclusive. After each loop step we increase counter (i) by 1" << endl;
    cout << "Loop executes as long as given condition is met, i.e. i < 10" << endl;
    for(int i = 0; i < 10; i++) {
        cout << i << endl;
    }

    cout << endl;
    cout << "We can change beginning value as well as the loop condition" << endl;
    for(int i = 2; i <= 5; i++) {
        cout << i << endl;
    }

    cout << endl;
    cout << "We can also work with loop step" << endl;
    for(int i = 0; i < 10; i += 2) {
        cout << i << endl;
    }

    cout << endl;
    cout << "Going from 10 to 0 is also simple. Just decrease counter value after each step" << endl;
    for(int i = 10; i >= 0; i--) {
        cout << i << endl;
    }

    int i;
    cout << endl;
    cout << "We can also use existing variable as a counter" << endl;
    for(i = 0; i < 10; i++) {
        cout << i << endl;
    }

    return 0;
}