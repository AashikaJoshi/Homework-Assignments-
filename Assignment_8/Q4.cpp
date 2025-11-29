#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create(){
    int x;
    cin >> x;
    if(x == -1) return NULL;

    Node* n = new Node();
    n->data = x;
    n->left = NULL;
    n->right = NULL;

    n->left = create();
    n->right = create();
    return n;
}

bool isBST(Node* root, int minVal, int maxVal){
    if(root == NULL) return true;

    if(root->data <= minVal || root->data >= maxVal)
        return false;

    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

int main(){
    cout << "Enter tree nodes (-1 for NULL):\n";
    Node* root = create();

    if(isBST(root, -1000000, 1000000))
        cout << "The tree IS a BST\n";
    else
        cout << "The tree is NOT a BST\n";

    return 0;
}