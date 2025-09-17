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

    int deleteOccurrences(int key) {
        int count = 0;

        // Handle nodes at beginning
        while (head != nullptr && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }

        Node* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->data == key) {
                Node* toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;
                count++;
            } else {
                curr = curr->next;
            }
        }

        return count;
    }

    void display() {
        if (head == nullptr) {
            cout << "Empty List";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << "->";
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;


    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(3);
    list.insert(1);

    int key = 1;
    cout << "Original List: ";
    list.display();

    int count = list.deleteOccurrences(key);

    cout << "\nCount: " << count << endl;
    cout << "Updated List: ";
    list.display();
    cout << endl;

    return 0;
}
