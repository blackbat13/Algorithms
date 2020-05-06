//
// Created by Damian Kurpiewski on 30.01.2017.
//

#include <iostream>

using namespace std;

/**
 * Class for BST representation.
 */
class BinarySearchTree {
private:
    /**
     * Structure representing the node of the tree.
     */
    struct node {
        /// Value in the node.
        int value;

        /// Pointer to the left child.
        node *left;

        /// Pointer to the right child.
        node *right;
    };

    /// Pointer to the root of the tree.
    node *root;

public:
    /**
     * Constructor. Initializes the tree with empty root.
     */
    BinarySearchTree() {
        root = nullptr;
    }

    /**
     * Adds new value to the tree.
     * @param value value to be added to the tree.
     */
    void add_value(int value) {
        node *current = root; /// Start at the root of the trea.
        node *next = root;
        while (next != nullptr) { /// While nex node exists...
            /// Search for a place to insert new node into the tree
            current = next;
            if (value < current->value) {
                /// If new value is less than the value in the current node,
                /// then go to its left child.
                next = current->left;
            } else {
                /// Otherwise go to the right child.
                next = current->right;
            }
        }

        /// Create new node and insert it to the tree.
        next = new node();
        next->value = value;
        next->left = nullptr;
        next->right = nullptr;

        /// If root doesn't exist...
        if (root == nullptr) {
            /// Assign new node as the root of the tree.
            root = next;
            return;
        }

        /// Check if new node should be left or right child of the previous one.
        if (value < current->value) {
            current->left = next;
        } else {
            current->right = next;
        }
    }

    /**
     * Inorder traversal: left subtree - current node - right subtree
     * @param current pointer to the currently visited node.
     */
    void inorder(node *current) {
        if (current == nullptr) {
            return;
        }

        inorder(current->left);
        cout << current->value << " ";
        inorder(current->right);
    }

    /**
     * Preorder traversal: current node - left subtree - right subtree
     * @param current pointer to the currently visited node.
     */
    void preorder(node *current) {
        if (current == nullptr) {
            return;
        }

        cout << current->value << " ";
        preorder(current->left);
        preorder(current->right);
    }

    /**
     * Postorder traversal: left subtree - right subtree - current node
     * @param current pointer to the currently visited node.
     */
    void postorder(node *current) {
        if (current == nullptr) {
            return;
        }

        postorder(current->left);
        postorder(current->right);
        cout << current->value << " ";
    }

    /**
     * Returns pointer to the root of the tree.
     * @return pointer to the root of the tree.
     */
    node *get_root() {
        return root;
    }

    /**
     * Clears the tree using recursion.
     * Deletes each node.
     * @param current pointer to the currently visited node.
     */
    void clear(node *current) {
        if (current == nullptr) {
            return;
        }

        clear(current->left);
        clear(current->right);
        delete current;
    }

    /**
     * Destructor. Clears the tree.
     */
    ~BinarySearchTree() {
        clear(root);
    }
};

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};

    /// Create new BST.
    BinarySearchTree binary_search_tree = BinarySearchTree();

    /// Add values to the BST.
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