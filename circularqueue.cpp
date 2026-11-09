
#include <iostream>
using namespace std;

class CircularQueue {
    int arr[5];
    int size = 5;
    int front, rear;
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }
    // Check empty
    bool isEmpty() {
        return front == -1;
    }
    // Check full
    bool isFull() {
        return (rear + 1) % size == front;
    }

    // Enqueue
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = x;
    }
    // Dequeue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }

    // Front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    // Rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[rear];
    }

    // Display
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        int i = front;

        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;

            i = (i + 1) % size;
        }
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
    q.enqueue(60);
    q.display();
    return 0;
}
