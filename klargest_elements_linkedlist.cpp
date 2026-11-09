
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void kLargest(Node* head, int k) {
    priority_queue<int> pq;

    // Insert linked list elements into max heap
    while (head != NULL) {
        pq.push(head->data);
        head = head->next;
    }

    // Extract K largest elements
    cout << "K largest elements: ";

    while (k-- && !pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(30);
    head->next->next->next->next->next = new Node(15);

    kLargest(head, 3);

    return 0;
}
