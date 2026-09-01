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

void bubbleSort(Node* head)
{
    Node* i = head;

    while(i != NULL)
    {
        Node* j = head;

        while(j->next != NULL)
        {
            if(j->data > j->next->data)
            {
                int temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
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

    bubbleSort(head);

    cout << "\nAfter sorting: ";
    display(head);

    return 0;
}
