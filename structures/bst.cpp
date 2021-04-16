#include <iostream>
using namespace std;

/// Class representing a Binary Search Tree
class BST {
    struct node {
        int value;
        node *left;
        node *right;
    };

    node *root;
public:
    BST() {
        root = nullptr;
    }

    node* get_root() {
        return root;
    }

    /// Adds new value to the tree
    /// \param value new value to add
    void insert(int value) {
        node *new_node = new node();
        new_node->value = value;
        new_node->left = nullptr;
        new_node->right = nullptr;

        if(root == nullptr) {
            root = new_node;
            return;
        }

        node *current, *parent;
        current = root;
        while(current != nullptr) {
            parent = current;
            if(value < current->value) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if(value < parent->value) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
    }

    /// Inorder tree traversal
    /// \param current currently visited node
    void inorder(node *current) {
        if(current == nullptr) {
            return;
        }

        inorder(current->left);
        cout << current->value << " ";
        inorder(current->right);
    }

    /// Preorder tree traversal
    /// \param current currently visited node
    void preorder(node *current) {
        if(current == nullptr) {
            return;
        }

        cout << current->value << " ";
        preorder(current->left);
        preorder(current->right);
    }

    /// Postorder tree traversal
    /// \param current currently visited node
    void postorder(node *current) {
        if(current == nullptr) {
            return;
        }

        postorder(current->left);
        postorder(current->right);
        cout << current->value << " ";
    }

    /// Deletes given subtree
    /// \param current currently visited node
    void clear(node *current) {
        if(current == nullptr) {
            return;
        }

        clear(current->left);
        clear(current->right);
        delete current;
    }

    ~BST() {
        clear(root);
    }
};

int main() {
    int array[7] = {20, 10, 30, 5, 15, 25, 35};
    BST bst = BST();

    for(auto el : array) {
        bst.insert(el);
    }

    cout << "Inorder: ";
    bst.inorder(bst.get_root());
    cout << endl;

    cout << "Preorder: ";
    bst.preorder(bst.get_root());
    cout << endl;

    cout << "Postorder: ";
    bst.postorder(bst.get_root());
    cout << endl;
    return 0;
}