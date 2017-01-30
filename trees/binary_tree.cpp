//
// Created by Damian Kurpiewski on 30.01.2017.
//

#include <iostream>

using namespace std;

class Binary_tree {
private:
    struct node {
        int value;
        node *left;
        node *right;
    };

    node *root;

public:
    Binary_tree() {
        root = NULL;
    }

    void add_value(int value) {
        node *current = root;
        node *next = root;
        while (next != NULL) {
            current = next;
            if (value < current->value) {
                next = current->left;
            } else {
                next = current->right;
            }
        }

        next = new node();
        next->value = value;
        next->left = NULL;
        next->right = NULL;

        if (current == NULL) {
            root = next;
            return;
        }

        if (value < current->value) {
            current->left = next;
        } else {
            current->right = next;
        }
    }

    void inorder(node *current) {
        if (current == NULL) {
            return;
        }

        inorder(current->left);
        cout << current->value << " ";
        inorder(current->right);
    }

    void preorder(node *current) {
        if (current == NULL) {
            return;
        }

        cout << current->value << " ";
        preorder(current->left);
        preorder(current->right);
    }

    void postorder(node *current) {
        if (current == NULL) {
            return;
        }

        postorder(current->left);
        postorder(current->right);
        cout << current->value << " ";
    }

    node *get_root() {
        return root;
    }

    void clear(node *current) {
        if (current == NULL) {
            return;
        }

        clear(current->left);
        clear(current->right);
        delete current;
    }

    ~Binary_tree() {
        clear(root);
    }
};

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    Binary_tree binary_tree = Binary_tree();
    for (int i = 0; i < 10; i++) {
        binary_tree.add_value(array[i]);
    }

    cout << "INORDER: ";
    binary_tree.inorder(binary_tree.get_root());
    cout << endl;
    cout << "PREORDER: ";
    binary_tree.preorder(binary_tree.get_root());
    cout << endl;
    cout << "POSTORDER: ";
    binary_tree.postorder(binary_tree.get_root());
    cout << endl;

    return 0;
}