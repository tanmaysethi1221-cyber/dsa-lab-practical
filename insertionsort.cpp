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

void insertionSort(Node* head)
{
    Node* i = head->next;

    while(i != NULL)
    {
        Node* j = head;

        while(j != i)
        {
            if(j->data > i->data)
            {
                int temp = j->data;
                j->data = i->data;
                i->data = temp;
            }

            j = j->next;
        }

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

    insertionSort(head);

    cout << "\nAfter sorting: ";
    display(head);

    return 0;
}
