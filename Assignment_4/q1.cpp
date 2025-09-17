#include <iostream>
using namespace std;
#define MAX 5  

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }


    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full! Cannot enqueue " << x << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        arr[++rear] = x;
        cout << x << " enqueued successfully." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty! Cannot dequeue." << endl;
            return;
        }
        cout << arr[front] << " dequeued successfully." << endl;
        if (front == rear) {
            front = rear = -1; 
        } else {
            front++;
        }
    }

   
    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << (q.isEmpty() ? "Queue is Empty" : "Queue is not Empty") << endl;
            break;
        case 6:
            cout << (q.isFull() ? "Queue is Full" : "Queue is not Full") << endl;
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}