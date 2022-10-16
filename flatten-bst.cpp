#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void inorder(TreeNode<int>* root,vector<int>& res){
    if(!root){
        return;
    }
    
    inorder(root->left,res);
    res.push_back(root->data);
    inorder(root->right,res);
    
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> res;
    inorder(root,res);
    
    TreeNode<int>* newRoot = new TreeNode<int>(res[0]);
    TreeNode<int>* current = newRoot;
    
    int n = res.size();
    
    for(int i=1;i<n;i++){
        TreeNode<int>* temp = new TreeNode<int>(res[i]);
        current -> left = NULL;
        current -> right = temp;
        current = temp;
    }
    current -> left = NULL;
    current -> right = NULL;

    return newRoot;
}

