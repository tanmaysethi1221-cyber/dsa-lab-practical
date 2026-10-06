#include <iostream>
#include<vector>
#include<queue>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
void inorder(Node* root){
    if ( root == NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node*insert(Node*root,int x){
    if(root==NULL){
        root = new Node(x);
        return root;
    }
    if(root->data >x){
        root->left = insert(root->left,x);
    }
else {
root->right = insert(root->right,x);
}
return root;
}
Node* createBST(){
Node * root = nullptr;
int val;
cout<<"enter values and at last enter -1";
cin>>val;
while(val!=-1){
    root = insert(root,val);
    cin>>val;
}
return root;
}
Node*Maxelement(Node * root,int x){
    if(root->data == x){
        return root;
    }
 Node * temp = root;
 while (temp->right !=NULL){
    temp = temp ->right;
 }
 return temp;
}
Node*Minelement(Node * root,int x){
    if(root->data == x){
        return root;
    }
 Node * temp = root;
 while (temp->left !=NULL){
    temp = temp ->left;
 }
 return temp;
}
// now want to write code for the deletion
Node*deleteNode(Node*root,int x){
    if(root == NULL){
        return root;
    }
     if(root->data<x){
    root ->right = deleteNode(root->right,x);
    return root;
 }
 if(x<root->data) {
    root->left = deleteNode(root->left,x);
    return root;
 }
 else{
        //no child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // 1 child
        if(root->left!=NULL && root->right==NULL){
            Node * temp = root->left;
            delete root;
            return temp;
        }
        if(root->left ==NULL&& root->right!=NULL){
            Node * temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if(root->left != NULL && root->right !=NULL){
            Node * max = Maxelement(root->left,x);
            root->data = max->data;
            root->left = deleteNode(root->left,x);  
            return root;
        }
    }
    return root;
}
vector<vector<int>> levelorder(Node* root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelsize = q.size();
        vector<int> temp;

        for (int i = 0; i < levelsize; i++) {
            Node* t = q.front();
            q.pop();

            temp.push_back(t->data);

            if (t->left != nullptr) {
                q.push(t->left);
            }
            if (t->right != nullptr) {
                q.push(t->right);
            }
        }
        res.push_back(temp);
    }
    return res;
}
int main(){
Node * root = createBST();
cout << "\nInorder Traversal: ";
    inorder(root);
    cout << "\n";
vector<vector<int>> levels = levelorder(root);
    for (const auto& level : levels) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << "\n";
    }
root = deleteNode(root,56);
cout << "\nInorder Traversal: ";
    inorder(root);
    cout << "\n";
    return 0;

}
