#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* createNode (int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}


void printTree(Node *root) // Preorder
{
    if (root == nullptr) return;

    cout << root->data << endl;
    printTree(root->left);
    printTree(root->right);
}

void printTreeInorder(Node *root) // Inorder
{
    if (root == nullptr) return;

    printTreeInorder(root->left);
    cout << root->data << endl;
    printTreeInorder(root->right);
}

void printTreePostorder(Node *root) // Postorder
{
    if (root == nullptr) return;

    printTreePostorder(root->left);
    printTreePostorder(root->right);
    cout << root->data << endl;
}

int main()
{
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    root->left->right->left = createNode(9);
    root->right->right->left = createNode(15);

    printTree(root);
    cout << endl;
    printTreeInorder(root);
    cout << endl;
    printTreePostorder(root);
}