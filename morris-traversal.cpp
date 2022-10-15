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

Node* find(Node* root){
    Node* current = root;
    current = current -> left;
    while(current->right && current->right != root){
        current = current -> right;
    }
    return current;
}



Node* buildTree(Node* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    if(data == -1){
        return NULL;
    }
    root = new Node(data);
    cout<<"Enter the data for inserting to the left of "<<root->data<<endl;
    root -> left = buildTree(root->left);
    cout<<"Enter the data for inserting to the right of "<<root->data<<endl;
    root -> right = buildTree(root->right);
    return root;
}


void morrisTraversal(Node* root){
    Node* current = root;
    while(current){
        if(!current->left){
            cout << current->data << " ";
            current = current -> right;
        }
        else{
            Node* predecessor = find(current);
            if(!predecessor -> right){
                predecessor -> right = current;
                current = current -> left;
            }
            else{
                predecessor -> right = NULL;
                cout << current -> data << " ";
                current = current -> right;
            }
        }
    }

}

int main(){
    Node* root = buildTree(root);
    morrisTraversal(root);

    return 0;
}