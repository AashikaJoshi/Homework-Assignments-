#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

 
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertBefore(int key, int val) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Node with value " << key << " not found!\n";
        } else {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    
    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node with value " << key << " not found!\n";
        } else {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }


    void deleteNode(int key) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Node with value " << key << " not found!\n";
        } else {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    
    void searchNode(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp !=NULL) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found!\n";
    }
    void displayList() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, key;

    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete at Beginning\n";
        cout << "6. Delete at End\n";
        cout << "7. Delete a Specific Node\n";
        cout << "8. Search a Node\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtEnd(val);
                break;

            case 3:
                cout << "Enter key (before which to insert): ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                list.insertBefore(key, val);
                break;

            case 4:
                cout << "Enter key (after which to insert): ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                list.insertAfter(key, val);
                break;

            case 5:
                list.deleteAtBeginning();
                break;

            case 6:
                list.deleteAtEnd();
                break;

            case 7:
                cout << "Enter node value to delete: ";
                cin >> key;
                list.deleteNode(key);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> key;
                list.searchNode(key);
                break;

            case 9:
                list.displayList();
                break;

            case 10:
                exit(0);

            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
