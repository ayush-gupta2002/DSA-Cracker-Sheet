#include <iostream> 
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this -> data = val;
            this -> left = NULL;
            this -> right = NULL;
        }
};

Node* constructTree(Node* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;

    if(data == -1){
        return NULL;
    }
    root = new Node(data);

    cout << "Enter the data to the left of "<<root -> data << endl;
    root -> left = constructTree(root -> left);
    cout<<"Enter the data to the right of "<<root->data<<endl;
    root -> right = constructTree(root->right);

    return root;
}

void inorderTraversal(Node* root){
    if(!root){
        return;
    }

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){
    Node* root;
    root = constructTree(root);
    inorderTraversal(root);
    return 0;
}