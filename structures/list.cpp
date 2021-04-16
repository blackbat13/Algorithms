#include <iostream>

using namespace std;

class List {
    struct element {
        int value;
        element *next;
    };

    element *first;
    int count;
public:
    List() {
        first = nullptr;
        count = 0;
    }

    int size() {
        return count;
    }

    void push(int value) {
        element *new_element = new element();
        new_element->value = value;
        new_element->next = nullptr;
        count++;
        if (first == nullptr) {
            first = new_element;
            return;
        }

        element *current = first;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = new_element;
    }

    void pop() {
        if (count == 0) {
            throw out_of_range("List is empty");
        }

        if (count == 1) {
            delete first;
            first = nullptr;
            count = 0;
            return;
        }

        element *current = first;
        element *previous;

        while (current->next != nullptr) {
            previous = current;
            current = current->next;
        }

        delete current;
        previous->next = nullptr;
        count--;
    }

    int operator[](int index) {
        if (index < 0 || index >= count) {
            throw out_of_range("Out of range");
        }

        element *current = first;
        int current_index = 0;
        while (current_index < index) {
            current_index++;
            current = current->next;
        }

        return current->value;
    }

    void replace(int index, int value) {
        if (index < 0 || index >= count) {
            throw out_of_range("Out of range");
        }

        element *current = first;
        int current_index = 0;
        while (current_index < index) {
            current_index++;
            current = current->next;
        }

        current->value = value;
    }

    void clear() {
        element *current = first, *tmp;
        while (current != nullptr) {
            tmp = current->next;
            delete current;
            current = tmp;
        }
    }

    ~List() {
        clear();
    }
};

int main() {
    List list = List();
    list.push(1);
    list.push(2);
    list.push(3);
    list.pop();
    list.replace(1, 10);
    list.push(4);
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }

    cout << endl;

    return 0;
}