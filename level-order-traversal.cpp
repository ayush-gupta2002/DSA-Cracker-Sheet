#include <iostream>
#include <queue>
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

Node* LOTUsingQueue(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(!temp){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
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

void printCurrentLevel(Node* root,int level){
    if(!root){
        return;
    }
    if(level == 1){
        cout << root -> data << " ";
    }
    else if(level > 1){
        printCurrentLevel(root->left,level-1);
        printCurrentLevel(root->right,level-1);
    }
}

void LOTUsingRecursion(Node* root){
    int h = height(root);
    for(int i=1;i<=h;i++){
        printCurrentLevel(root,i);
    }
}

int main(){
    Node* root;
    root = constructTree(root);
    LOTUsingRecursion(root);
    return 0;
}