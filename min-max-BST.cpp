int minBST(Node* root){
    Node* temp = root;
    while(temp -> left){
        temp = temp->left;
    }
    return temp->data;
}

int maxBST(Node* root){
    Node* temp = root;
    while(temp -> right){
        temp = temp->right;
    }
    return temp -> right;
}
