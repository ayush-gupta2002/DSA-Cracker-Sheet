#include <iostream>
#include <stack>
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

int height(Node* root){
    if(!root){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int res = max(leftHeight,rightHeight) + 1;
    return res;
}

void preorderUsingRecursion(Node* root){
    if(!root){
        return;
    }

    cout<<root->data<<" ";
    preorderUsingRecursion(root->left);
    preorderUsingRecursion(root->right);
}

void preorderUsingIteration(Node* root){
    if(!root){
        return;
    }

    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* temp = s.top();
        s.pop();

        cout<< temp -> data << " ";
        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left){
            s.push(temp->left);
        }
    }
}

int main(){
    Node* root;
    root = constructTree(root);
    preorderUsingIteration(root);
    return 0;
}