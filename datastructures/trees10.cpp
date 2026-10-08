#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node (int value)
    {
        data = value;
        left = right = nullptr;
    }
};

class BinaryTree
{
    public:
    Node* root;

    BinaryTree()
    {
        root = nullptr;
    }
    
    Node* insert(Node* node, int value)
    {
        if(node == nullptr)
        {
            return new Node(value);
        }

        if(value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else
        {
            node->right = insert(node->right, value);
        }

        return node;
    }

    void insert(int value)
    {
        root = insert(root, value);
    }
};

int main()
{
    BinaryTree tree;

    tree.insert(15);
}