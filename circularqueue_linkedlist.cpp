
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class CircularQueue {
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = nullptr;
        rear = nullptr;
    }

    // Check empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue
    void enqueue(int x) {
        Node* newNode = new Node(x);

        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front;
        }
        else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
    }

    // Dequeue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = front;

        cout << "Deleted: " << front->data << endl;

        if (front == rear) {
            front = rear = nullptr;
        }
        else {
            front = front->next;
            rear->next = front;
        }

        delete temp;
    }

    // Get Front
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return front->data;
    }

    // Get Rear
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return rear->data;
    }

    // Display
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = front;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);

        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    q.dequeue();

    q.display();

    q.enqueue(50);

    q.display();

    return 0;
}
