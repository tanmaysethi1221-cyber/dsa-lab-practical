
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *left, *right, *parent;

    Node(int v) {
        val = v;
        left = right = parent = NULL;
    }
};
// INSERT
Node* insert(Node* root, int val, Node* parent = NULL) {
    if (root == NULL) {
        Node* temp = new Node(val);
        temp->parent = parent;
        return temp;
    }

    if (val < root->val)
        root->left = insert(root->left, val, root);

    else if (val > root->val)
        root->right = insert(root->right, val, root);

    else
        cout << "Duplicate value!\n";

    return root;
}

// SEARCH
Node* search(Node* root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (val < root->val)
        return search(root->left, val);

    return search(root->right, val);
}

// FIND MAXIMUM
Node* maxNode(Node* root) {
    while (root->right != NULL)
        root = root->right;

    return root;
}

// DELETE
Node* Delete(Node* root, int val) {
    Node* temp = search(root, val);

    if (temp == NULL) {
        cout << "Value not found\n";
        return root;
    }

    // Two children
    if (temp->left && temp->right) {
        Node* p = maxNode(temp->left);
        temp->val = p->val;
        temp = p;
    }

    // Zero or one child
    Node* child = (temp->left) ? temp->left : temp->right;

    if (child)
        child->parent = temp->parent;

    if (temp->parent == NULL)
        root = child;

    else if (temp->parent->left == temp)
        temp->parent->left = child;

    else
        temp->parent->right = child;

    delete temp;
    return root;
}

// DISPLAY
void display(Node* root) {
    if (root == NULL)
        return;

    display(root->left);
    cout << root->val << " ";
    display(root->right);
}

int main() {
    Node* root = NULL;
    int n, val, ch;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        root = insert(root, val);
    }
    do {
        cout << "\n\n1.Insert  2.Search  3.Delete  4.Display  0.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            root = insert(root, val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            cout << (search(root, val) ? "Found" : "Not Found");
            break;

        case 3:
            cout << "Enter value: ";
            cin >> val;
            root = Delete(root, val);
            break;

        case 4:
            display(root);
            break;

        case 0:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice";
        }

    } while (ch != 0);
    return 0;
}
