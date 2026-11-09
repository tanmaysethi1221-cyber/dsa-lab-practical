#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = right = NULL;
        height = 1;
    }
};
// Get Height
int getHeight(Node* root) {
    if (root == NULL)
        return 0;

    return root->height;
}
// Get Balance Factor
int getBalance(Node* root) {
    if (root == NULL)
        return 0;

    return getHeight(root->left) -
           getHeight(root->right);
}
// Right Rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t = x->right;
    x->right = y;
    y->left = t;
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    return x;
}
// Left Rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;
    x->height = 1 + max(getHeight(x->left),getHeight(x->right));
    y->height = 1 + max(getHeight(y->left),getHeight(y->right));
    return y;
}
// Insert Function
Node* insert(Node* root, int key) {
    if (root == NULL)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));
    int balance = getBalance(root);
    if (balance > 1 && key < root->left->data)
        return rightRotate(root);
    if (balance < -1 && key > root->right->data)
        return leftRotate(root);
    if (balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

// Find Minimum Value Node
Node* minValueNode(Node* root) {

    Node* current = root;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// DELETE FUNCTION
Node* deleteNode(Node* root, int key) {

    // Normal BST deletion
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {

        // Node has 0 or 1 child
        if (root->left == NULL ||
            root->right == NULL) {

            Node* temp = root->left ?
                         root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else {
                *root = *temp;
            }

            delete temp;
        }

        // Node has 2 children
        else {

            Node* temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right,
                                     temp->data);
        }
    }

    if (root == NULL)
        return root;

    // Update Height
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    int balance = getBalance(root);

    // LL Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // LR Case
    if (balance > 1 &&
        getBalance(root->left) < 0) {

        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // RL Case
    if (balance < -1 &&
        getBalance(root->right) > 0) {

        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder Traversal
void inorder(Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    Node* root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 50);
    cout << "Before Deletion: ";
    inorder(root);
    root = deleteNode(root, 10);
    cout << "\nAfter Deletion: ";
    inorder(root);

    return 0;
}
