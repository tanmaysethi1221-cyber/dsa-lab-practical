#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void selectionSort(Node* head)
{
    Node* i = head;

    while(i != NULL)
    {
        Node* min = i;
        Node* j = i->next;

        while(j != NULL)
        {
            if(j->data < min->data)
                min = j;

            j = j->next;
        }

        int temp = i->data;
        i->data = min->data;
        min->data = temp;

        i = i->next;
    }
}

void display(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = new Node(64);
    head->next = new Node(25);
    head->next->next = new Node(12);
    head->next->next->next = new Node(22);
    head->next->next->next->next = new Node(11);

    cout << "Before sorting: ";
    display(head);

    selectionSort(head);

    cout << "\nAfter sorting: ";
    display(head);

    return 0;
}
