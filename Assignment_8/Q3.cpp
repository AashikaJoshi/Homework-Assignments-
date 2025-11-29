#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* n = new Node();
    n->data = data;
    n->left = n->right = NULL;
    return n;
}


Node* insertNode(Node* root, int data){
    if(root == NULL) return createNode(data);
    if(data == root->data) return root;       // no duplicates allowed
    if(data < root->data) root->left = insertNode(root->left, data);
    else root->right = insertNode(root->right, data);
    return root;
}

Node* findMin(Node* root){
    while(root && root->left) root = root->left;
    return root;
}


Node* deleteNode(Node* root, int key){
    if(root == NULL) return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


int maxDepth(Node* root){
    if(root == NULL) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return max(l, r) + 1;
}


int minDepth(Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL) return minDepth(root->right) + 1;
    if(root->right == NULL) return minDepth(root->left) + 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}


int main(){
    Node* root = NULL;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++){
        cin >> x;
        root = insertNode(root, x);
    }

    cout << "Enter element to delete: ";
    cin >> x;
    root = deleteNode(root, x);

    cout << "Maximum Depth: " << maxDepth(root) << endl;
    cout << "Minimum Depth: " << minDepth(root) << endl;

    return 0;
}