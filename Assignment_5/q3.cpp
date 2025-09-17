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

    
    int findMiddle() {
        if (head == nullptr) return -1;

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        
            fast = fast->next->next;   
        }

        return slow->data; 
    }

  
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "Linked List: ";
    list.display();

    cout << "Middle Element: " << list.findMiddle() << endl;

    return 0;
}
