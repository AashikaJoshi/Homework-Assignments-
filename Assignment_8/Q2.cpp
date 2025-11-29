#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);

        return node;
    }

    Node* searchRecursive(Node* node, int key) {
        if (!node || node->data == key) return node;

        if (key < node->data)
            return searchRecursive(node->left, key);
        return searchRecursive(node->right, key);
    }

    Node* findMin(Node* node) {
        if (!node) return nullptr;
        while (node->left) node = node->left;
        return node;
    }

    Node* findMax(Node* node) {
        if (!node) return nullptr;
        while (node->right) node = node->right;
        return node;
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int val) {
        root = insert(root, val);
    }


    Node* searchRec(int key) {
        return searchRecursive(root, key);
    }


    Node* searchIter(int key) {
        Node* curr = root;
        while (curr) {
            if (curr->data == key) return curr;
            curr = (key < curr->data) ? curr->left : curr->right;
        }
        return nullptr;
    }

    int getMin() {
        Node* res = findMin(root);
        return res ? res->data : -1;
    }

    int getMax() {
        Node* res = findMax(root);
        return res ? res->data : -1;
    }

    // Inorder successor
    Node* inorderSuccessor(int key) {
        Node* curr = searchRec(key);
        if (!curr) return nullptr;

        if (curr->right)
            return findMin(curr->right);

        Node* succ = nullptr;
        Node* ancestor = root;

        while (ancestor != curr) {
            if (key < ancestor->data) {
                succ = ancestor;
                ancestor = ancestor->left;
            } 
            else {
                ancestor = ancestor->right;
            }
        }
        return succ;
    }

    // Inorder predecessor
    Node* inorderPredecessor(int key) {
        Node* curr = searchRec(key);
        if (!curr) return nullptr;

        if (curr->left)
            return findMax(curr->left);

        Node* pred = nullptr;
        Node* ancestor = root;

        while (ancestor != curr) {
            if (key > ancestor->data) {
                pred = ancestor;
                ancestor = ancestor->right;
            } 
            else {
                ancestor = ancestor->left;
            }
        }
        return pred;
    }
};

int main() {
    BST tree;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        tree.insert(x);
    }

    cout << "\nEnter value to search: ";
    cin >> x;

    Node* r1 = tree.searchRec(x);
    Node* r2 = tree.searchIter(x);

    cout << "Recursive Search: " << (r1 ? "Found\n" : "Not Found\n");
    cout << "Iterative Search: " << (r2 ? "Found\n" : "Not Found\n");

    cout << "Minimum: " << tree.getMin() << endl;
    cout << "Maximum: " << tree.getMax() << endl;

    Node* suc = tree.inorderSuccessor(x);
    Node* pre = tree.inorderPredecessor(x);

    cout << "Inorder Successor: " 
         << (suc ? to_string(suc->data) : "None") << endl;

    cout << "Inorder Predecessor: " 
         << (pre ? to_string(pre->data) : "None") << endl;

    return 0;
}
