
#include <iostream>
using namespace std;

class Queue {
    int arr[5];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == 4;
    }

    // Enqueue
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Full\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = x;
    }

    // Dequeue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        if (front == rear)
            front = rear = -1;
        else
            front++;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    void display() {
        if (isEmpty()) return;

        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    q.dequeue();
    q.display();

    return 0;
}
