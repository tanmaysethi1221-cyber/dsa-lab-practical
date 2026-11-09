
#include <bits/stdc++.h>
using namespace std;

class Stack {
    int arr[5];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == 4) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Deleted: " << arr[top--] << endl;
    }

    void peek() {
        if (top == -1)
            cout << "Stack is Empty\n";
        else
            cout << "Top: " << arr[top] << endl;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 4;
    }

    void display() {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();
    s.peek();
    s.pop();
    s.display();

    return 0;
}
