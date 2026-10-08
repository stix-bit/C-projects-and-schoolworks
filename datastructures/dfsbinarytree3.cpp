#include <iostream>
using namespace std;

// Class definition for a Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Class definition for Binary Tree
class BinaryTree {
public:
    Node* root;

    // Constructor to initialize the tree
    BinaryTree() {
        root = nullptr;
    }

    // DFS Postorder Traversal (Left → Right → Root)
    void depthFirstSearch(Node* node) {
        if (node == nullptr)
            return;

        depthFirstSearch(node->left);   // Recursively traverse the left subtree
        depthFirstSearch(node->right);  // Recursively traverse the right subtree
        cout << node->data << " ";      // Process the current node (Root)
    }

    // Helper function to call DFS starting from the root
    void dfsTraversal() {
        depthFirstSearch(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;

    // Manually constructing the tree
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);
    tree.root->right->left = new Node(6);
    tree.root->right->right = new Node(7);

    cout << "Depth-First Search (Postorder Traversal: Left-Right-Root): ";
    tree.dfsTraversal();

    return 0;
}
