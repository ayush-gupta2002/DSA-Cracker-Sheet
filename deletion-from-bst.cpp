/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int maxBST(TreeNode* root){
        TreeNode* temp = root;
        while(temp -> right){
            temp = temp -> right;
        }
        return temp -> val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root){
            return NULL;
        }
        
        if(root -> val == key){
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            if(root->left && !root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if(root->right && !root->left){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if(root -> left && root->right){
                int maxi = maxBST(root->left);
                root->val = maxi;
                root->left = deleteNode(root->left,maxi);
                return root;
                
            }
        }
        
        else if(root->val < key){
            root -> right = deleteNode(root->right,key);
            return root;
        }
        else{
            root -> left = deleteNode(root->left,key);
            return root;
        }
        return root;
    }
};
