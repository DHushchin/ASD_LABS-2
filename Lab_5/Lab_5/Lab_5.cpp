#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left, *right;
};

class BinaryTree {
private:
    Node* root;
public:
    BinaryTree(int data);
    ~BinaryTree();
    void DeleteTree(Node* leaf);
    void ShowTree(Node* node);
    void insert(int data, Node* leaf);
    Node* GetRoot();
};

int main()
{
    int count;
    cout << "Enter the amount of elements you want to enter: "; cin >> count;
    int elem;
    cout << "Enter a number: ";
    cin >> elem;
    BinaryTree Tree(elem);
    for (int i = 0; i < count - 1; i++) {
        int elem;
        cout << "Enter a number: "; 
        cin >> elem;
        Tree.insert(elem, Tree.GetRoot());
    }
}


BinaryTree::BinaryTree(int data) {
    root = new Node;
    root->data = data;
    root->left = root->right = NULL;
}

BinaryTree::~BinaryTree() {
    DeleteTree(root);
};

void BinaryTree::DeleteTree(Node* node) {
    if (node != NULL)
    {
        DeleteTree(node->left);
        DeleteTree(node->right);
        delete node;
    }
}


void BinaryTree::insert(int data, Node* leaf)
{
    if (leaf == NULL)
    {
        leaf = new Node;
        leaf->data = data;
        leaf->left = leaf->right = NULL;
    }
    else if (data < leaf->data)
        insert(data, leaf->left);
    else
        insert(data, leaf->right);
    cout << leaf->data << endl;
}


void BinaryTree::ShowTree(Node* node)
{
        if (node == NULL) return;
        ShowTree(node->left);
        cout << node->data << " ";
        ShowTree(node->right);
}


Node* BinaryTree::GetRoot() {
    return root;
}