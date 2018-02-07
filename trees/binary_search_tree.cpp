//
// Created by Damian Kurpiewski on 30.01.2017.
//

#include <iostream>

using namespace std;

class BinarySearchTree {
private:
    struct node {
        int value;
        node *left;
        node *right;
    };

    node *root;

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void add_value(int value) {
        node *current = root;
        node *next = root;
        while (next != nullptr) {
            current = next;
            if (value < current->value) {
                next = current->left;
            } else {
                next = current->right;
            }
        }

        next = new node();
        next->value = value;
        next->left = nullptr;
        next->right = nullptr;

        if (current == nullptr) {
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
        if (current == nullptr) {
            return;
        }

        inorder(current->left);
        cout << current->value << " ";
        inorder(current->right);
    }

    void preorder(node *current) {
        if (current == nullptr) {
            return;
        }

        cout << current->value << " ";
        preorder(current->left);
        preorder(current->right);
    }

    void postorder(node *current) {
        if (current == nullptr) {
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
        if (current == nullptr) {
            return;
        }

        clear(current->left);
        clear(current->right);
        delete current;
    }

    ~BinarySearchTree() {
        clear(root);
    }
};

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    BinarySearchTree binary_search_tree = BinarySearchTree();
    for (int i : array) {
        binary_search_tree.add_value(i);
    }

    cout << "INORDER: ";
    binary_search_tree.inorder(binary_search_tree.get_root());
    cout << endl;
    cout << "PREORDER: ";
    binary_search_tree.preorder(binary_search_tree.get_root());
    cout << endl;
    cout << "POSTORDER: ";
    binary_search_tree.postorder(binary_search_tree.get_root());
    cout << endl;

    return 0;
}