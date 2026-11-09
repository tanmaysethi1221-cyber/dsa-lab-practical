#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// 1. CREATION
Node* createTree() {
    int val;
    cout << "Enter root value (-1 for NULL): ";
    cin >> val;
    if (val == -1)
        return NULL;
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left child of " << temp->data << ": ";
        cin >> val;

        if (val != -1) {
            temp->left = new Node(val);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << ": ";
        cin >> val;

        if (val != -1) {
            temp->right = new Node(val);
            q.push(temp->right);
        }
    }

    return root;
}
// 2. INSERTION (Level Order)
void insert(Node* root, int val) {
    if (root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = new Node(val);
            return;
        }
        else
            q.push(temp->left);

        if (temp->right == NULL) {
            temp->right = new Node(val);
            return;
        }
        else
            q.push(temp->right);
    }
}
// 3. INORDER
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// 4. PREORDER
void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// 5. POSTORDER
void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// 6. LEVEL ORDER
void levelOrder(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }
}

// 7. DELETE ANY NODE
void deleteNode(Node* root, int key) {
    if (root == NULL)
        return;

    if (root->data == key && !root->left && !root->right) {
        cout << "Cannot delete root without updating root pointer\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    Node* target = NULL;
    Node* deepest = NULL;
    Node* parent = NULL;

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->data == key)
            target = temp;

        if (temp->left) {
            parent = temp;
            deepest = temp->left;
            q.push(temp->left);
        }
        if (temp->right) {
            parent = temp;
            deepest = temp->right;
            q.push(temp->right);
        }
    }
    if (target == NULL) {
        cout << "Node not found\n";
        return;
    }

    if (deepest == target && parent == NULL) {
        cout << "Cannot delete the only root using this function\n";
        return;
    }

    target->data = deepest->data;

    if (parent->left == deepest)
        parent->left = NULL;
    else
        parent->right = NULL;

    delete deepest;
}

// MAIN
int main() {
    Node* root = createTree();
    int ch, val;

    do {
        cout << "\n\n1. Insert";
        cout << "\n2. Inorder";
        cout << "\n3. Preorder";
        cout << "\n4. Postorder";
        cout << "\n5. Level Order";
        cout << "\n6. Delete Any Node";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insert(root, val);
            break;

        case 2:
            inorder(root);
            break;

        case 3:
            preorder(root);
            break;

        case 4:
            postorder(root);
            break;

        case 5:
            levelOrder(root);
            break;
        case 6:
            cout << "Enter node to delete: ";
            cin >> val;
            deleteNode(root, val);
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
