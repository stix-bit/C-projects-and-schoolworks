#include <iostream>
using namespace std;

// Node structure for Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Binary Tree class
class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    // Insert node (Level Order for a general Binary Tree)
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    // Recursive search function
    bool search(Node* node, int key) {
        if (node == nullptr) return false;   // Base case: Not found
        if (node->data == key) return true;  // Found the key

        // Recur to left and right subtrees
        return search(node->left, key) || search(node->right, key);
    }

    bool search(int key) {
        return search(root, key);
    }
};

int main() {
    BinaryTree tree;
    int n, value, searchValue;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }

    cout << "Enter value to search: ";
    cin >> searchValue;

    if (tree.search(searchValue))
        cout << "Value found in the tree!" << endl;
    else
        cout << "Value not found in the tree." << endl;

    return 0;
}
