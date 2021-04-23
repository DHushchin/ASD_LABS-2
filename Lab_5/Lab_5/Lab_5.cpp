#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int data);
Node* Insert(Node* root, int data);
void printLevel(Node* node, int level, vector<int>& vect);
Node* FillTree(Node* root);
void GetLevel(Node* root);

int main() {
    Node* root = NULL;
    root = FillTree(root);
    GetLevel(root);
    system("pause");
    return 0;
}


Node* GetNewNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* Insert(Node* root, int data) {
    if (root == NULL) {
        root = GetNewNode(data);
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

void printLevel(Node* node, int level, vector<int>& vect) {
    if (node == nullptr) {
        return;
    }
    else {
        printLevel(node->left, level - 1, vect);
        if (level == 0) {
            vect.push_back(node->data);
        }
        printLevel(node->right, level - 1, vect);
    }
}

Node* FillTree(Node* root) {
    int count;
    cout << "Enter the amount of elements you want to enter: "; cin >> count;
    for (int i = 0; i < count; i++) {
        int elem;
        cout << "Enter a number: ";
        cin >> elem;
        root = Insert(root, elem);
    }
    return root;
}

void GetLevel(Node* root) {
    int level;
    cout << "Enter level: "; cin >> level;
    vector<int> vect;
    printLevel(root, level, vect);
    cout << "There are " << vect.size() << " elements on the " << level << " level: ";
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << "  ";
    cout << endl;
}