#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

   
    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;  
            curr->next = prev;  
            prev = curr;         
            curr = next;        
        }
        head = prev;  
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    cout << "Original List: ";
    list.display();

    list.reverse();

    cout << "Reversed List: ";
    list.display();

    return 0;
}
