//
// Created by Damian Kurpiewski on 08.07.2017.
//

#include <iostream>

using namespace std;

class Queue {
private:
    struct element {
        int value;
        element *next;
        element *previous;
    };

    element *front_el;
    int el_count;
public:
    Queue() {
        front_el = NULL;
        el_count = 0;
    }

    void push(int value) {
        element *new_el = new element();
        new_el->value = value;
        new_el->next = NULL;
        if (front_el == NULL) {
            front_el = new_el;
            front_el->previous = NULL;
            el_count++;
            return;
        }

        element *last_el = front_el;
        while (last_el->next != NULL) {
            last_el = last_el->next;
        }

        new_el->previous = last_el;
        last_el->next = new_el;
        el_count++;
    }

    int front() {
        if (front_el != NULL) {
            return front_el->value;
        }

        throw nullptr;
    }

    void pop() {
        if (front_el != NULL) {
            element *tmp = front_el->next;
            delete front_el;
            front_el = tmp;
            if (front_el != NULL) {
                front_el->previous = NULL;
            }

            el_count--;
            return;
        }

        throw nullptr;
    }

    void clear() {
        element *tmp;
        while (front_el != NULL) {
            tmp = front_el->next;
            delete front_el;
            front_el = tmp;
        }
    }

    bool is_empty() {
        return front_el == NULL;
    }

    int count() {
        return el_count;
    }

    ~Queue() {
        clear();
    }
};

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    Queue queue = Queue();
    for (int i = 0; i < 10; i++) {
        queue.push(array[i]);
    }

    cout << queue.count() << endl;

    while (!queue.is_empty()) {
        cout << queue.front() << " ";
        queue.pop();
    }

    cout << endl;
    return 0;
}