#include <iostream>
#include <queue>
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

    // Insert node in Binary Tree (Level Order)
    void insert(int value) {
        Node* newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left == nullptr) {
                temp->left = newNode;
                return;
            } else {
                q.push(temp->left);
            }

            if (temp->right == nullptr) {
                temp->right = newNode;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }

    // Function to delete a node from Binary Tree
    void deleteNode(int key) {
        if (root == nullptr) return;

        queue<Node*> q;
        q.push(root);

        Node* keyNode = nullptr;
        Node* temp;
        Node* lastNode = nullptr;

        // Level-order traversal to find keyNode and lastNode
        while (!q.empty()) {
            temp = q.front();
            q.pop();

            if (temp->data == key) {
                keyNode = temp;
            }

            if (temp->left) {
                lastNode = temp;
                q.push(temp->left);
            }
            if (temp->right) {
                lastNode = temp;
                q.push(temp->right);
            }
        }

        // If key is found, replace it with the deepest node
        if (keyNode != nullptr) {
            keyNode->data = temp->data;  // Replace key node with deepest node

            // Delete the deepest node
            if (lastNode->right == temp) {
                lastNode->right = nullptr;
            } else {
                lastNode->left = nullptr;
            }

            delete temp;
        }
    }

    // Inorder traversal (Left → Root → Right)
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    int n, value, delValue;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }

    cout << "Inorder Traversal before Deletion: ";
    tree.inorderTraversal();

    cout << "Enter value to delete: ";
    cin >> delValue;

    tree.deleteNode(delValue);

    cout << "Inorder Traversal after Deletion: ";
    tree.inorderTraversal();

    return 0;
}
