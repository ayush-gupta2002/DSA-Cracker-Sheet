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

void postorderUsingRecursion(Node* root){
    if(!root){
        return;
    }

    postorderUsingRecursion(root->left);
    postorderUsingRecursion(root->right);
    cout<<root->data<<" ";
}

int main(){

    Node* root;
    root = constructTree(root);
    postorderUsingRecursion(root);
    return 0;
}